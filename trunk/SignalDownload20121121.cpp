#include "SignalDownload.h"

//��չ����
#define SD_CURLE_ErrorReport(A)						\
	if(CURLE_OK != A)  /* we failed */				\
	{												\
		fprintf(stderr, "ERROR:%s,%d,curl told us %s\n", __FILE__,__LINE__,curl_easy_strerror(A));	\
		return false;								\
	}

//��չ����
#define SD_curl_easy_setopt_EXT(A,B,C,D)			\
	D=curl_easy_setopt(A,B,C);						\
	SD_CURLE_ErrorReport(D);
	
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
	if(CURLE_OK != res)  /* we failed */				
	{												
		fprintf(stderr, "curl result %s\n",curl_easy_strerror(res));	
		return false;								
	}

	//�ر��ļ�
	fclose(outfile);
	outfile=NULL;

	curl_easy_cleanup(curl);
	curl=NULL;

	return true;
}

#define LOCAL_FILE      _T("111a.html")
#define REMOTE_URL      "ftp://10.142.50.139/ftp/video server/a6.html"


static size_t read_callback(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  curl_off_t nread;
  /* in real-world cases, this would probably get this data differently
     as this fread() stuff is exactly what the library already would do
     by default internally */
  size_t retcode = fread(ptr, size, nmemb, stream);

  nread = (curl_off_t)retcode;

  fprintf(stderr, "*** We read %" CURL_FORMAT_CURL_OFF_T
          " bytes from file\n", nread);
  return retcode;
}

bool SignalDownload::Upload(char *url,TCHAR *filename,long timeout)
{
	
  FILE *hd_src;
 
  curl_off_t fsize;
  /* get the file size of the local file */
  /* get a FILE * of the same file */
  hd_src = _tfopen(LOCAL_FILE, _T("rb"));
	
  fseek(hd_src,0,SEEK_END);
  fsize =	ftell(hd_src);
  fseek(hd_src,0,SEEK_SET);

  printf("Local file size: %" CURL_FORMAT_CURL_OFF_T " bytes.\n", fsize);


  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* build a list of commands to pass to libcurl */

    /* enable uploading */
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    /* specify target */
    curl_easy_setopt(curl,CURLOPT_URL, REMOTE_URL);
	curl_easy_setopt(curl,CURLOPT_USERPWD, "da:da");
	curl_easy_setopt(curl,CURLOPT_PORT, 21);

	//���������ٶ�=0ʱ N���˳�
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
	//����URL��ַ���� ����N�κ��Ƴ�
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, timeout);
   curl_easy_setopt(curl, CURLOPT_FTP_RESPONSE_TIMEOUT, timeout);

    /* pass in that last of FTP commands to run after the transfer */

curl_easy_setopt(curl, CURLOPT_FTPPORT, "-"); /* disable passive mode */
 curl_easy_setopt(curl, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    /* we want to use our own read function */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

    /* now specify which file to upload */
    curl_easy_setopt(curl, CURLOPT_READDATA, hd_src);

    /* Set the size of the file to upload (optional).  If you give a *_LARGE
       option you MUST make sure that the type of the passed-in argument is a
       curl_off_t. If you use CURLOPT_INFILESIZE (without _LARGE) you must
       make sure that to pass in a type 'long' argument. */
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE,(curl_off_t)fsize);

    curl_easy_setopt(curl, CURLOPT_INFILESIZE,(curl_off_t)fsize);

    /* Now run off and do what you've been told! */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* clean up the FTP commands list */
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  fclose(hd_src); /* close the local file */

	return true;
}