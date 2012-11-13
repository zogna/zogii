#include "MultiDownload.h"

//扩展定义
#define MD_curl_easy_setopt_EXT(A,B,C,D)			\
	D=curl_easy_setopt(A,B,C);						\
	if(CURLE_OK != D)  /* we failed */				\
	{												\
		fprintf(stderr, "curl told us %s\n", curl_easy_strerror(D));	\
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

//url		URL地址 
//filename	文件路径
//timeout	设定下载超时时限
//输出		下载成功或失败
//执行下载
bool MultiDownload::Load(MULTI_DOWNLOAD_INFO *info,long timeout)
{
	CURLcode res;

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

	CURLMcode mes=curl_multi_add_handle(curlmulti, curl);
	if(CURLM_OK != mes)  			
	{	/* we failed */										
		fprintf(stderr, "curlmulti told us %s\n", curl_multi_strerror(mes));	
		return false;								
	}
	return true;
}


//url		URL地址 
//filename	文件路径
//timeout	设定下载超时时限
//输出		下载成功或失败
//执行下载
bool MultiDownload::Download(MULTI_DOWNLOAD_INFO *&info,long infocount,long sametimecount,long timeout=10)
{

	
#if 0
	//初始化
	curl = curl_easy_init();
	if(NULL == curl)
		return false;
	//打开待写文件
	outfile = fopen(filename, "wb");
	if(NULL== outfile)
		return false;

	//设置URL地址
	MD_curl_easy_setopt_EXT(curl, CURLOPT_URL, url,res);
	//设置写入的文件指针
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, outfile,res);
	//设置写入回调函数
	MD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, MD_WriteFunc,res);
	//设置无进程函数
	MD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE,res);
	//设置进程回调函数
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, MD_ProgressFunc,res);
	//设置进程回调函数传的自定义参
	MD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA, this,res);
	//设置下载速度=0时 N次退出
	MD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout,res);
	//设置URL地址错误 重连N次后推出
	MD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout,res);
	//开始执行
	res = curl_easy_perform(curl);
	if(CURLE_OK != res)  			
	{	/* we failed */										
		fprintf(stderr, "curl told us %s\n", curl_easy_strerror(res));	
		return false;								
	}

	//关闭文件
	fclose(outfile);
	outfile=NULL;

	curl_easy_cleanup(curl);
	curl=NULL;
#endif
	return true;
}
