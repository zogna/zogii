#include "MultiDownload.h"

//��չ����
#define MD_curl_easy_setopt_EXT(A,B,C,D)			\
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
size_t MD_WriteFunc(void *ptr, size_t size, size_t nmemb, FILE *stream)
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
int MD_ProgressFunc(void *clientp,
					 double dltotal, 
					 double dlnow, 
					 double ultotal,
					 double ulnow)
{
//	char *s=(char *)clientp;
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
bool MultiDownload::Load(MULTI_DOWNLOAD_INFO *info,long timeout)
{
	CURLcode res;

	//��ʼ��
	CURL *curl = curl_easy_init();
	if(NULL == curl)
		return false;

	//�򿪴�д�ļ�
	info->fp = _tfopen(info->filename, _T("wb"));
	if(NULL== info->fp )
		return false;

	//����URL��ַ
	MD_curl_easy_setopt_EXT(curl, CURLOPT_URL, info->url,res);
	//����д����ļ�ָ��
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, info->fp,res);
	//����д��ص�����
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, MD_WriteFunc,res);
	//�����޽��̺���
	MD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE,res);
	//���ý��̻ص�����
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, MD_ProgressFunc,res);
	//���ý��̻ص����������Զ����
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA,info->filename,res);
	//���������ٶ�=0ʱ N���˳�
	MD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout,res);
	//����URL��ַ���� ����N�κ��Ƴ�
	MD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout,res);

	CURLMcode mes=curl_multi_add_handle(curlmulti, curl);
	if(CURLM_OK != mes)  			
	{	/* we failed */										
		fprintf(stderr, "curlmulti told us %s\n", curl_multi_strerror(mes));	
		return false;								
	}
	return true;
}


//url		URL��ַ 
//filename	�ļ�·��
//timeout	�趨���س�ʱʱ��
//���		���سɹ���ʧ��
//ִ������
bool MultiDownload::Download(MULTI_DOWNLOAD_INFO *&info,long infocount,long sametimecount,long timeout=10)
{

	
#if 0
	//��ʼ��
	curl = curl_easy_init();
	if(NULL == curl)
		return false;
	//�򿪴�д�ļ�
	outfile = fopen(filename, "wb");
	if(NULL== outfile)
		return false;

	//����URL��ַ
	MD_curl_easy_setopt_EXT(curl, CURLOPT_URL, url,res);
	//����д����ļ�ָ��
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, outfile,res);
	//����д��ص�����
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, MD_WriteFunc,res);
	//�����޽��̺���
	MD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE,res);
	//���ý��̻ص�����
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, MD_ProgressFunc,res);
	//���ý��̻ص����������Զ����
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA, this,res);
	//���������ٶ�=0ʱ N���˳�
	MD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout,res);
	//����URL��ַ���� ����N�κ��Ƴ�
	MD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout,res);
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
#endif
	return true;
}
