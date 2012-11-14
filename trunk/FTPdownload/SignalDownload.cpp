#include "SignalDownload.h"


//��չ����
#define SD_curl_easy_setopt_EXT(A,B,C)			\
	res=curl_easy_setopt(A,B,C);				\
	if(CURLE_OK != res)  /* we failed */		\
	{											\
		fprintf(stderr, "ERROR:%s,%d,curl told us %s\n", __FILE__,__LINE__,curl_easy_strerror(res));	\
		fclose(outfile);						\
		outfile=NULL;							\
		curl_easy_cleanup(A);				\
		A=NULL;								\
		return false;							\
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
	SignalDownload *s=(SignalDownload *)clientp;
	s->completesize=(long)dlnow;
	s->totalsize=(long)dltotal;

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
bool SignalDownload::Download(char *url,TCHAR *filename,long timeout=10,long startsize=0)
{
	completesize=0;
	totalsize=0;
	//��ʼ��
	curl = curl_easy_init();
	if(NULL == curl)
		return false;
	//�򿪴�д�ļ�
	outfile = _tfopen(filename, _T("wb"));
	if(NULL== outfile)
	{
		curl_easy_cleanup(curl);
		curl=NULL;
		return false;
	}
	//����URL��ַ
	SD_curl_easy_setopt_EXT(curl, CURLOPT_URL, url);
	/*
	//������ʼ����λ��
	sprintf(sizestr,"%d-",startsize);
	fseek(outfile,startsize,SEEK_SET);
	SD_curl_easy_setopt_EXT(curl, CURLOPT_RANGE, sizestr);
	*/
	//����д����ļ�ָ��
	SD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, outfile);
	//����д��ص�����
	SD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, SD_WriteFunc);
	//�����޽��̺���
	SD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE);
	//���ý��̻ص�����
	SD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, SD_ProgressFunc);
	//���ý��̻ص����������Զ����
	SD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA, this);
	//���������ٶ�=0ʱ N���˳�
	SD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout);
	//����URL��ַ���� ����N�κ��Ƴ�
	SD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout);
	//��ʼִ��
	res = curl_easy_perform(curl);
	if(CURLE_OK != res)  /* we failed */				
	{												
		fprintf(stderr, "curl result %s\n",curl_easy_strerror(res));	
		fclose(outfile);
		outfile=NULL;
		curl_easy_cleanup(curl);
		curl=NULL;
		return false;							
	}	

	//�ر��ļ�
	fclose(outfile);
	outfile=NULL;

	curl_easy_cleanup(curl);
	curl=NULL;

	return true;
}
