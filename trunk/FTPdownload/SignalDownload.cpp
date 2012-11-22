#include "SignalDownload.h"

#define LOWSPEEDLIMIT 256

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

//��չ����
#define SD_curl_easy_setopt_EXT_NOFILE(A,B,C)	\
	res=curl_easy_setopt(A,B,C);				\
	if(CURLE_OK != res)  /* we failed */		\
	{											\
		fprintf(stderr, "ERROR:%s,%d,curl told us %s\n", __FILE__,__LINE__,curl_easy_strerror(res));	\
		curl_easy_cleanup(A);					\
		A=NULL;									\
		return false;							\
	}

//��չ����
#define SD_curl_easy_getinfo_EXT_NOFILE(A,B,C)	\
	res=curl_easy_getinfo(A,B,C);				\
	if(CURLE_OK != res)  /* we failed */		\
	{											\
		fprintf(stderr, "ERROR:%s,%d,curl told us %s\n", __FILE__,__LINE__,curl_easy_strerror(res));	\
		curl_easy_cleanup(A);					\
		A=NULL;									\
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
bool SignalDownload::HTTPDownload(char *url,TCHAR *filename,long timeout=10,long startsize=0)
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
	//��������ٶȡ�Ϊ����;������
	SD_curl_easy_setopt_EXT(curl, CURLOPT_LOW_SPEED_LIMIT, LOWSPEEDLIMIT);
	SD_curl_easy_setopt_EXT(curl, CURLOPT_LOW_SPEED_TIME, timeout);

	
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
//ʵʱ�ϴ��ص�
size_t SD_ReadFunc(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	//fprintf(stderr, "*** We read %d bytes from file\n", nmemb);
	return fread(ptr, size, nmemb, stream);
}

//url		URL��ַ 
//userpsw	�û��������� "user:psw"
//port		FTP�˿ں�
//filename	�ļ�·��
//timeout	�趨�ϴ���ʱʱ��
//���		�ϴ��ɹ���ʧ��
//ִ���ϴ�
bool SignalDownload::FTPUpload(char *url,char *userpsw,long port,TCHAR *filename,long timeout=10)
{
	curl_off_t fsize;

	curl=NULL;
	/* get a curl handle */
	curl = curl_easy_init();
	if(NULL == curl)
		return false;

	/* get the file size of the local file */
	/* get a FILE * of the same file */
	outfile=NULL;
	outfile = _tfopen(filename, _T("rb"));
	if(NULL== outfile)
	{
		curl_easy_cleanup(curl);
		curl=NULL;
		return false;
	}

	fseek(outfile,0,SEEK_END);
	fsize =	ftell(outfile);
	fseek(outfile,0,SEEK_SET);

	//printf("Local file size: %" CURL_FORMAT_CURL_OFF_T " bytes.\n", fsize);

	/* enable uploading */
	SD_curl_easy_setopt_EXT(curl, CURLOPT_UPLOAD, 1L);

	/* specify target */
	SD_curl_easy_setopt_EXT(curl,CURLOPT_URL, url);
	SD_curl_easy_setopt_EXT(curl,CURLOPT_USERPWD, userpsw);
	SD_curl_easy_setopt_EXT(curl,CURLOPT_PORT, port);

	//���������ٶ�=0ʱ N���˳�
	SD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout);
	//����URL��ַ���� ����N�κ��Ƴ�
	SD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout);
	SD_curl_easy_setopt_EXT(curl, CURLOPT_FTP_RESPONSE_TIMEOUT, timeout);
	//��������ٶȡ�Ϊ����;������
	SD_curl_easy_setopt_EXT(curl, CURLOPT_LOW_SPEED_LIMIT, LOWSPEEDLIMIT);
	SD_curl_easy_setopt_EXT(curl, CURLOPT_LOW_SPEED_TIME, timeout);

	/* pass in that last of FTP commands to run after the transfer */
	SD_curl_easy_setopt_EXT(curl, CURLOPT_FTPPORT, "-"); /* disable passive mode */
	SD_curl_easy_setopt_EXT(curl, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);

	SD_curl_easy_setopt_EXT(curl, CURLOPT_VERBOSE, 1L);

	/* we want to use our own read function */
	SD_curl_easy_setopt_EXT(curl, CURLOPT_READFUNCTION, SD_ReadFunc);

	/* now specify which file to upload */
	SD_curl_easy_setopt_EXT(curl, CURLOPT_READDATA, outfile);

	/* Set the size of the file to upload (optional).  If you give a *_LARGE
	option you MUST make sure that the type of the passed-in argument is a
	curl_off_t. If you use CURLOPT_INFILESIZE (without _LARGE) you must
	make sure that to pass in a type 'long' argument. */
	SD_curl_easy_setopt_EXT(curl, CURLOPT_INFILESIZE_LARGE,(curl_off_t)fsize);

	SD_curl_easy_setopt_EXT(curl, CURLOPT_INFILESIZE,(curl_off_t)fsize);

	/* Now run off and do what you've been told! */
	res = curl_easy_perform(curl);
	/* Check for errors */
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

size_t SD_HeaderFunc(void *ptr, size_t size, size_t nmemb, void *data)
{
  (void)ptr;
  (void)data;
  /* we are not interested in the headers itself,
     so we only return the size we would have saved ... */
  return (size_t)(size * nmemb);
}

bool SignalDownload::FTPFileinfo(char *url,char *userpsw,long port, time_t *filetime,double *filesize,long timeout=10)
{
	curl=NULL;
	/* get a curl handle */
	curl = curl_easy_init();
	if(NULL == curl)
		return false;
	
	SD_curl_easy_setopt_EXT_NOFILE(curl,CURLOPT_URL,url);
	SD_curl_easy_setopt_EXT_NOFILE(curl,CURLOPT_USERPWD,userpsw);
	SD_curl_easy_setopt_EXT_NOFILE(curl,CURLOPT_PORT, port);
	/* No download if the file */
	SD_curl_easy_setopt_EXT_NOFILE(curl, CURLOPT_NOBODY, 1L);
	/* Ask for filetime */
	SD_curl_easy_setopt_EXT_NOFILE(curl, CURLOPT_FILETIME, 1L);
	/* No header output: TODO 14.1 http-style HEAD output for ftp */
	SD_curl_easy_setopt_EXT_NOFILE(curl, CURLOPT_HEADERFUNCTION, SD_HeaderFunc);
	SD_curl_easy_setopt_EXT_NOFILE(curl, CURLOPT_HEADER, 0L);
	/* Switch on full protocol/debug output */
	/* curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); */

	res = curl_easy_perform(curl);

	if(CURLE_OK != res) 
	{
		fprintf(stderr, "curl result %s\n",curl_easy_strerror(res));	
		curl_easy_cleanup(curl);
		curl=NULL;
		return false;	
	}

	SD_curl_easy_getinfo_EXT_NOFILE(curl, CURLINFO_FILETIME, filetime);
	if(*filetime)
		printf("filetime: %s",ctime(filetime));

	SD_curl_easy_getinfo_EXT_NOFILE(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, filesize);
	if(*filesize)
		printf("filesize: %0.0f bytes\n", *filesize);

	curl_easy_cleanup(curl);
	curl=NULL;
	return	true;
}
