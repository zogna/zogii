#include "MultiDownload.h"

//��չ����
#define MD_CURLE_ErrorReport(A)						\
	if(CURLE_OK != A)  /* we failed */				\
	{												\
		fprintf(stderr, "ERROR:%s,%d,curl told us %s\n", __FILE__,__LINE__,curl_easy_strerror(A));	\
		return false;								\
	}

//��չ����
#define MD_curl_easy_setopt_EXT(A,B,C,D)			\
	D=curl_easy_setopt(A,B,C);						\
	MD_CURLE_ErrorReport(D);

//��չ����
#define	MD_CURLM_ErrorReport(A)						\
	if(CURLM_OK != A)								\
	{												\
		fprintf(stderr,"ERROR:%s,%d,curlmulti told us %s\n",__FILE__,__LINE__,curl_multi_strerror(A));	\
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

//MULTI_DOWNLOAD_INFO	1���ṹ��
//timeout				��ʱ����
//���		��ʼ���ɹ���ʧ��
//��ʼ��
bool MultiDownload::Load(MULTI_DOWNLOAD_INFO *info,long timeout)
{
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
	//Ҫһ�����á�����curl_multi ���ò���URL��ַ 
	//��curl_easy_getinfo(curlmultiSG->easy_handle, CURLINFO_PRIVATE, &url);
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PRIVATE,info->url,res);
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

	mes=curl_multi_add_handle(curlmulti, curl);
	MD_CURLM_ErrorReport(mes);
	return true;
}


//MULTI_DOWNLOAD_INFO	N���ṹ��
//infocount				N
//sametimecount			ͬʱ�����ļ��ĸ���
//timeout				��ʱ����
//����					ִ�гɹ�����ʧ��
//ִ������
bool MultiDownload::Download(MULTI_DOWNLOAD_INFO *&info,long infocount,long sametimecount,long timeout=10)
{
	long i,j;
	fd_set Reads, Writes, Execs;
	int maxfd;
	int run=1;
	int queue;
	long sleeptime=timeout;
	struct timeval T;
	char *url;
	CURL *tempcurl;

	//��ʼ��
	curlmulti = curl_multi_init();
	if(NULL == curlmulti)
		return false;

	//����ܹ�Ҫ�µ����� С�� ͬʱ����������ͬʱ������ ���ó� �ܹ�Ҫ�µ�����
	if(infocount < sametimecount)
		sametimecount=infocount;
	//����ͬʱ������
	mes=curl_multi_setopt(curlmulti, CURLMOPT_MAXCONNECTS, sametimecount);
	MD_CURLM_ErrorReport(mes);

	//��ʼ������
	for (i = 0;i < sametimecount; i++) 
	{
		if(false == Load(&info[i],timeout))
			return false;
	}

	while (run) 
	{
		//ִ�������б�
		mes=curl_multi_perform(curlmulti, &run);
		MD_CURLM_ErrorReport(mes);

		if (run)
		{
			FD_ZERO(&Reads);
			FD_ZERO(&Writes);
			FD_ZERO(&Execs);
			
			mes=curl_multi_fdset(curlmulti, &Reads, &Writes, &Execs, &maxfd);
			MD_CURLM_ErrorReport(mes);
			//����ִ�С���ȡ�Ƿ�ʱ�ȴ�
			mes=curl_multi_timeout(curlmulti, &sleeptime);
			MD_CURLM_ErrorReport(mes);

			if (maxfd == -1)
			{
#ifdef WIN32
				Sleep(sleeptime);
#else
				sleep(sleeptime / 1000);
#endif
			}
			else 
			{
				T.tv_sec = sleeptime/1000;
				T.tv_usec = (sleeptime%1000)*1000;

				if (0 > select(maxfd+1, &Reads, &Writes, &Execs, &T)) 
				{
					fprintf(stderr, "curlmulti error: select(%i,,,,%li): %i: %s\n",
						maxfd+1, sleeptime, errno, strerror(errno));
					return false;
				}
			}
		}

		while ((curlmultiSG = curl_multi_info_read(curlmulti, &queue)))
		{
			//������� �� �����쳣�˳�
			if ( CURLMSG_DONE == curlmultiSG->msg) 
			{
				tempcurl = curlmultiSG->easy_handle;

				res=curl_easy_getinfo(curlmultiSG->easy_handle, CURLINFO_PRIVATE, &url);
				MD_CURLE_ErrorReport(res);

				fprintf(stderr, "curlmulti result: %d - %s\n<%s>\n",
					curlmultiSG->data.result, curl_easy_strerror(curlmultiSG->data.result), url);
					
				//�����д�� ���ؽṹ��
				for(j=0;j<infocount;j++)
				{
					if(0==strcmp(info[j].url,url))
					{
						//�ر��ļ�
						fclose(info[j].fp);
						if(CURLE_OK == curlmultiSG->data.result)
							info[j].result=true;
						else
							info[j].result=false;
					}
				}

				//�������б���ɾ���
				mes=curl_multi_remove_handle(curlmulti, tempcurl);
				MD_CURLM_ErrorReport(mes);
				//����
				curl_easy_cleanup(tempcurl);
			}
			else 
			{
				//δ֪�쳣
				fprintf(stderr, "curlmultiSG error: CURLMsg (%d)\n", curlmultiSG->msg);
				return	false;
				
			}
			if (i < infocount) 
			{
				if(false == Load(&info[i],timeout))
					return false;
				i++;
				run++; /* just to prevent it from remaining at 0 if there are more
					 URLs to get */
			}
		}
	}

	mes=curl_multi_cleanup(curlmulti);
	MD_CURLM_ErrorReport(mes);

	return true;
}
