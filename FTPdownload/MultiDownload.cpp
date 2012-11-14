#include "MultiDownload.h"

//扩展定义
#define MD_CURLE_ErrorReport(A)						\
	if(CURLE_OK != A)  /* we failed */				\
	{												\
		fprintf(stderr, "ERROR:%s,%d,curl told us %s\n", __FILE__,__LINE__,curl_easy_strerror(A));	\
		return false;								\
	}

//扩展定义
#define MD_curl_easy_setopt_EXT(A,B,C,D)			\
	D=curl_easy_setopt(A,B,C);						\
	MD_CURLE_ErrorReport(D);

//扩展定义
#define	MD_CURLM_ErrorReport(A)						\
	if(CURLM_OK != A)								\
	{												\
		fprintf(stderr,"ERROR:%s,%d,curlmulti told us %s\n",__FILE__,__LINE__,curl_multi_strerror(A));	\
		return false;								\
	}
	
//下载并写到文件中 回调函数
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

//实时下载或上传进程的回调函数
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
	//注意这里返回 0为正常进程
	//返回 1为退出下载进程。直接下载失败(可以做“取消下载”使用)
	return 	0;
}

//MULTI_DOWNLOAD_INFO	1个结构体
//timeout				超时设置
//输出		初始化成功或失败
//初始化
bool MultiDownload::Load(MULTI_DOWNLOAD_INFO *info,long timeout)
{
	//初始化
	CURL *curl = curl_easy_init();
	if(NULL == curl)
		return false;

	//打开待写文件
	info->fp = _tfopen(info->filename, _T("wb"));
	if(NULL== info->fp )
		return false;

	//设置URL地址
	MD_curl_easy_setopt_EXT(curl, CURLOPT_URL, info->url,res);
	//要一并设置。否则curl_multi 将得不到URL地址 
	//见curl_easy_getinfo(curlmultiSG->easy_handle, CURLINFO_PRIVATE, &url);
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PRIVATE,info->url,res);
	//设置写入的文件指针
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, info->fp,res);
	//设置写入回调函数
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, MD_WriteFunc,res);
	//设置无进程函数
	MD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE,res);
	//设置进程回调函数
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, MD_ProgressFunc,res);
	//设置进程回调函数传的自定义参
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA,info->filename,res);
	//设置下载速度=0时 N次退出
	MD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout,res);
	//设置URL地址错误 重连N次后推出
	MD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout,res);

	mes=curl_multi_add_handle(curlmulti, curl);
	MD_CURLM_ErrorReport(mes);
	return true;
}


//MULTI_DOWNLOAD_INFO	N个结构体
//infocount				N
//sametimecount			同时下载文件的个数
//timeout				超时设置
//返回					执行成功或者失败
//执行下载
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

	//初始化
	curlmulti = curl_multi_init();
	if(NULL == curlmulti)
		return false;

	//如果总共要下的数量 小于 同时下载数，则同时下载数 设置成 总共要下的数量
	if(infocount < sametimecount)
		sametimecount=infocount;
	//设置同时下载数
	mes=curl_multi_setopt(curlmulti, CURLMOPT_MAXCONNECTS, sametimecount);
	MD_CURLM_ErrorReport(mes);

	//初始化载入
	for (i = 0;i < sametimecount; i++) 
	{
		if(false == Load(&info[i],timeout))
			return false;
	}

	while (run) 
	{
		//执行下载列表
		mes=curl_multi_perform(curlmulti, &run);
		MD_CURLM_ErrorReport(mes);

		if (run)
		{
			FD_ZERO(&Reads);
			FD_ZERO(&Writes);
			FD_ZERO(&Execs);
			
			mes=curl_multi_fdset(curlmulti, &Reads, &Writes, &Execs, &maxfd);
			MD_CURLM_ErrorReport(mes);
			//启动执行。获取是否超时等待
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
			//下载完成 或 下载异常退出
			if ( CURLMSG_DONE == curlmultiSG->msg) 
			{
				tempcurl = curlmultiSG->easy_handle;

				res=curl_easy_getinfo(curlmultiSG->easy_handle, CURLINFO_PRIVATE, &url);
				MD_CURLE_ErrorReport(res);

				fprintf(stderr, "curlmulti result: %d - %s\n<%s>\n",
					curlmultiSG->data.result, curl_easy_strerror(curlmultiSG->data.result), url);
					
				//将结果写入 返回结构体
				for(j=0;j<infocount;j++)
				{
					if(0==strcmp(info[j].url,url))
					{
						//关闭文件
						fclose(info[j].fp);
						if(CURLE_OK == curlmultiSG->data.result)
							info[j].result=true;
						else
							info[j].result=false;
					}
				}

				//从下载列表中删句柄
				mes=curl_multi_remove_handle(curlmulti, tempcurl);
				MD_CURLM_ErrorReport(mes);
				//清理
				curl_easy_cleanup(tempcurl);
			}
			else 
			{
				//未知异常
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
