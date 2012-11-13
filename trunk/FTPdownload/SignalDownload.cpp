#include "SignalDownload.h"

//��չ����
#define SD_curl_easy_setopt_EXT(A,B,C,D)			\
	D=curl_easy_setopt(A,B,C);						\
	if(CURLE_OK != D)  /* we failed */				\
	{												\
		fprintf(stderr, "curl told us %s\n", curl_easy_strerror(D));	\
		return false;								\
	}
	
//���ز�д���ļ��� �ص�����
/*
typedef size_t (*curl_write_callback)(char *buffer,
                                      size_t size,
                                      size_t nitems,
                                      void *outstream);
*/
size_t SD_WriteFunc(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	return fwrite(ptr, size, nmemb, stream);
}

//ʵʱ���ػ��ϴ����̵Ļص�����
/*
typedef int (*curl_progress_callback)(void *clientp,
                                      double dltotal,
                                      double dlnow,
                                      double ultotal,
                                      double ulnow);
*/
int SD_ProgressFunc(void *clientp,
					 double dltotal, 
					 double dlnow, 
					 double ultotal,
					 double ulnow)
{
//	SignalDownload *s=(SignalDownload *)clientp;
	fprintf(stderr,"%g / %g (%g %%)\r\n", dlnow, dltotal, dlnow*100.0/dltotal);
	//ע�����ﷵ�� 0Ϊ��������
	//���� 1Ϊ�˳����ؽ��̡�ֱ������ʧ��(��������ȡ�����ء�ʹ��)
	return 	0;
}

//url		URL��ַ 
//filename	�ļ�·��
//timeout	�趨���س�ʱʱ��
//���		���سɹ���ʧ��
//ִ������
bool SignalDownload::Download(char *url,TCHAR *filename,long timeout=10)
{
	//��ʼ��
	curl = curl_easy_init();
	if(NULL == curl)
		return false;
	//�򿪴�д�ļ�
	outfile = _tfopen(filename, _T("wb"));
	if(NULL== outfile)
		return false;

	//����URL��ַ
	SD_curl_easy_setopt_EXT(curl, CURLOPT_URL, url,res);
	//����д����ļ�ָ��
	SD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, outfile,res);
	//����д��ص�����
	SD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, SD_WriteFunc,res);
	//�����޽��̺���
	SD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE,res);
	//���ý��̻ص�����
	SD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, SD_ProgressFunc,res);
	//���ý��̻ص����������Զ����
	SD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA, this,res);
	//���������ٶ�=0ʱ N���˳�
	SD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout,res);
	//����URL��ַ���� ����N�κ��Ƴ�
	SD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout,res);
	//��ʼִ��
	res = curl_easy_perform(curl);
	if(CURLE_OK != res)  			
	{	/* we failed */										
		fprintf(stderr, "curl told us %s\n", curl_easy_strerror(res));	
		return false;								
	}

	//�ر��ļ�
	fclose(outfile);
	outfile=NULL;

	curl_easy_cleanup(curl);
	curl=NULL;

	return true;
}
