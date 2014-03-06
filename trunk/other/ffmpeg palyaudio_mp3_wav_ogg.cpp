//http://www.cppblog.com/jackyxinli/archive/2009/11/24/101835.html


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#ifdef __cplusplus
extern "C" {
#endif
	
#include "./include/avcodec.h"
#include "./include/avformat.h"
#include "./include/avutil.h"
#include "./include/mem.h"
	
#ifdef __cplusplus
}
#endif

#define BLOCK_SIZE 4608
#define BLOCK_COUNT 20

HWAVEOUT hWaveOut = NULL;

static void CALLBACK waveOutProc(HWAVEOUT, UINT, DWORD, DWORD, DWORD);
static WAVEHDR* allocateBlocks(int size, int count);
static void freeBlocks(WAVEHDR* blockArray);
static void writeAudio(HWAVEOUT hWaveOut, LPSTR data, int size);

static CRITICAL_SECTION waveCriticalSection;
static WAVEHDR* waveBlocks;
static volatile unsigned int waveFreeBlockCount;
static int waveCurrentBlock;

typedef struct AudioState {
	AVFormatContext* pFmtCtx;
	AVCodecContext* pCodecCtx;
	AVCodec* pCodec;
	//uint8_t* audio_buf1[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2];
	uint8_t* audio_buf1;
	uint8_t* audio_buf;
	unsigned int audio_buf_size; /* in bytes */
	unsigned int buffer_size;
	int audio_buf_index; /* in bytes */
	AVPacket audio_pkt_temp;
	AVPacket audio_pkt;
	uint8_t* audio_pkt_data;
	int audio_pkt_size;
	
	int stream_index;
} AudioState;

int audio_decode_frame(AudioState* pState) {
	
	AVPacket* pkt_temp = &pState->audio_pkt_temp;
	AVPacket* pkt = &pState->audio_pkt;
	AVCodecContext* dec= pState->pCodecCtx;
	int len = 0, data_size = sizeof(pState->audio_buf1);
	int err = 0;
	
	for( ; ; ) {
		while (pkt_temp->size > 0) {
			// data_size = sizeof(pState->audio_buf1);
			data_size = pState->buffer_size;
			len = avcodec_decode_audio3(dec, (int16_t*)pState->audio_buf1, &data_size, pkt_temp);
			if (len < 0) {
				pkt_temp->size = 0;
				break;
			}
			
			pkt_temp->data += len;
			pkt_temp->size -= len;
			
			if (data_size <= 0)
				continue;
			
			pState->audio_buf = pState->audio_buf1;
			return data_size;
		}
		
		if (pkt->data)
			av_free_packet(pkt);
		
		if((err = av_read_frame(pState->pFmtCtx, pkt)) < 0)
			return -1;
		
		pkt_temp->data = pkt->data;
		pkt_temp->size = pkt->size;
	}
	
	return -1;
}

int main(int argc, char* argv[]) {
	int err = 0;
	AudioState audio_state = {0};
	unsigned int i = 0;
	unsigned int ready = 0;
	
	OPENFILENAME ofn = {0};
	char filename[MAX_PATH];
	WAVEFORMATEX wfx = {0};
	uint8_t buffer[BLOCK_SIZE];
	uint8_t* pbuffer = buffer;
	AVInputFormat* iformat = NULL;
	
	int audio_size = 0, data_size = 0;
	int len = 0, len1 = 0, eof = 0, size = 0;
	
	memset(&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = GetDesktopWindow();
	ofn.lpstrFile = filename;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(filename) / sizeof(filename[0]);
	ofn.lpstrFilter = _TEXT("All support files\0*.aac;*.ape;*.flac;*.mp3;*.mp4;*.mpc;*.ogg;*.tta;*.wma;*.wav\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	
	if (GetOpenFileName(&ofn) == FALSE)
		return 0;
	
	av_register_all();
	
	err = av_open_input_file(&audio_state.pFmtCtx, filename, NULL, 0, NULL);
	if(err < 0) {
		printf("can not open file %s.\n", filename);
		return -1;
	}
	
	err = av_find_stream_info(audio_state.pFmtCtx);
	if(err < 0) {
		printf("can not find stream info of file %s.\n", filename);
		return -1;
	}
	
	for(i = 0; i < audio_state.pFmtCtx->nb_streams; i++) {
		if(audio_state.pFmtCtx->streams[i]->codec->codec_type == CODEC_TYPE_AUDIO) {
			audio_state.pCodecCtx = audio_state.pFmtCtx->streams[i]->codec;
			audio_state.stream_index = i;
			ready = 1;
			break;
		}
	}
	
	if(!ready)
		return -1;
	
	audio_state.pCodec = avcodec_find_decoder(audio_state.pCodecCtx->codec_id);
	if(!audio_state.pCodec || avcodec_open(audio_state.pCodecCtx, audio_state.pCodec) < 0)
		return -1;
	
	wfx.nSamplesPerSec = audio_state.pCodecCtx->sample_rate;
	switch(audio_state.pCodecCtx->sample_fmt)
	{
	case SAMPLE_FMT_U8:
		wfx.wBitsPerSample = 8;
		break;
	case SAMPLE_FMT_S16:
		wfx.wBitsPerSample = 16;
		break;
	case SAMPLE_FMT_S32:
		wfx.wBitsPerSample = 32;
		break;
	case SAMPLE_FMT_FLT:
		wfx.wBitsPerSample = sizeof(double) * 8;
		break;
	default:
		wfx.wBitsPerSample = 0;
		break;
	}
	
	wfx.nChannels = FFMIN(2, audio_state.pCodecCtx->channels);
	wfx.cbSize = 0;
	wfx.wFormatTag = WAVE_FORMAT_PCM;
	wfx.nBlockAlign = (wfx.wBitsPerSample * wfx.nChannels) >> 3;
	wfx.nAvgBytesPerSec = wfx.nBlockAlign * wfx.nSamplesPerSec;
	
	waveBlocks = allocateBlocks(BLOCK_SIZE, BLOCK_COUNT);
	waveFreeBlockCount = BLOCK_COUNT;
	waveCurrentBlock = 0;
	
	InitializeCriticalSection(&waveCriticalSection);
	
	// open wave out device
	if(waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, (DWORD_PTR)waveOutProc,
		(DWORD_PTR)&waveFreeBlockCount, CALLBACK_FUNCTION) != MMSYSERR_NOERROR) {
		fprintf(stderr, "%s: unable to open wave mapper device\n", argv[0]);
		ExitProcess(1);
	}
	
	// allocate memory
	audio_state.audio_buf1 =(uint8_t*)av_malloc(buffer_size);
	audio_state.buffer_size = buffer_size;
	
	// play loop
	for( ; ; ) {
		
		len = BLOCK_SIZE;
		size = 0;
		pbuffer = buffer;
		
		if(eof)
			break;
		
		while(len > 0) {
			if(audio_state.audio_buf_index >= (int)audio_state.audio_buf_size) {
				audio_size = audio_decode_frame(&audio_state);
				if(audio_size < 0) {
					if(size > 0)
						break;
					
					eof = 1;
					break;
				}
				
				audio_state.audio_buf_size = audio_size;
				audio_state.audio_buf_index = 0;
			}
			
			len1 = audio_state.audio_buf_size - audio_state.audio_buf_index;
			if(len1 > len)
				len1 = len;
			
			memcpy(pbuffer, (uint8_t *)audio_state.audio_buf + audio_state.audio_buf_index, len1);
			
			len -= len1;
			pbuffer += len1;
			size += len1;
			audio_state.audio_buf_index += len1;
		}
		
		writeAudio(hWaveOut, (char*)buffer, size);
	}
	
	// free allocated memory
	av_free(audio_state.audio_buf1);
	audio_state.audio_buf1 = NULL;
	
	// wait for complete
	for( ; ; ) {
		if(waveFreeBlockCount >= BLOCK_COUNT)
			break;
		
		Sleep(10);
	}
	
	for(i = 0; i < waveFreeBlockCount; i++)
		if(waveBlocks[i].dwFlags & WHDR_PREPARED)
			waveOutUnprepareHeader(hWaveOut, &waveBlocks[i], sizeof(WAVEHDR));
		
		DeleteCriticalSection(&waveCriticalSection);
		freeBlocks(waveBlocks);
		waveOutClose(hWaveOut);
		
		avcodec_close(audio_state.pCodecCtx);
		
		system("pause");
		return 0;
}

static void writeAudio(HWAVEOUT hWaveOut, LPSTR data, int size)
{
	WAVEHDR* current;
	int remain;
	
	current = &waveBlocks[waveCurrentBlock];
	
	while(size > 0) {
	/*
	* first make sure the header we're going to use is unprepared
		*/
		if(current->dwFlags & WHDR_PREPARED)
			waveOutUnprepareHeader(hWaveOut, current, sizeof(WAVEHDR));
		
		if(size < (int)(BLOCK_SIZE - current->dwUser)) {
			memcpy(current->lpData + current->dwUser, data, size);
			current->dwUser += size;
			break;
		}
		
		remain = BLOCK_SIZE - current->dwUser;
		memcpy(current->lpData + current->dwUser, data, remain);
		size -= remain;
		data += remain;
		current->dwBufferLength = BLOCK_SIZE;
		
		waveOutPrepareHeader(hWaveOut, current, sizeof(WAVEHDR));
		waveOutWrite(hWaveOut, current, sizeof(WAVEHDR));
		
		EnterCriticalSection(&waveCriticalSection);
		waveFreeBlockCount--;
		LeaveCriticalSection(&waveCriticalSection);
		
		/*
		* wait for a block to become free
		*/
		while(!waveFreeBlockCount)
			Sleep(10);
		
			/*
			* point to the next block
		*/
		waveCurrentBlock++;
		waveCurrentBlock %= BLOCK_COUNT;
		
		current = &waveBlocks[waveCurrentBlock];
		current->dwUser = 0;
	}
}

static WAVEHDR* allocateBlocks(int size, int count)
{
	char* buffer;
	int i;
	WAVEHDR* blocks;
	DWORD totalBufferSize = (size + sizeof(WAVEHDR)) * count;
	
	/*
	* allocate memory for the entire set in one go
	*/
	if((buffer = (char*)HeapAlloc(
		GetProcessHeap(),
		HEAP_ZERO_MEMORY,
		totalBufferSize
		)) == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		ExitProcess(1);
	}
	
	/*
	* and set up the pointers to each bit
	*/
	blocks = (WAVEHDR*)buffer;
	buffer += sizeof(WAVEHDR) * count;
	for(i = 0; i < count; i++) {
		blocks[i].dwBufferLength = size;
		blocks[i].lpData = buffer;
		buffer += size;
	}
	
	return blocks;
}

static void freeBlocks(WAVEHDR* blockArray)
{
/*
* and this is why allocateBlocks works the way it does
	*/
	HeapFree(GetProcessHeap(), 0, blockArray);
}

static void CALLBACK waveOutProc(
								 HWAVEOUT hWaveOut,
								 UINT uMsg,
								 DWORD dwInstance,
								 DWORD dwParam1,
								 DWORD dwParam2
								 )
{
	int* freeBlockCounter = (int*)dwInstance;
	/*
	* ignore calls that occur due to opening and closing the
	* device.
	*/
	if(uMsg != WOM_DONE)
		return;
	
	EnterCriticalSection(&waveCriticalSection);
	(*freeBlockCounter)++;
	LeaveCriticalSection(&waveCriticalSection);
} 