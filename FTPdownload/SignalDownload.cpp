#include "SignalDownload.h"

//扩展定义
#define SD_curl_easy_setopt_EXT(A,B,C,D)			\
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
size_t SD_WriteFunc(void *ptr, size_t size, size_t nmemb, FILE *stream)
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
int SD_ProgressFunc(void *clientp,
					 double dltotal, 
					 double dlnow, 
					 double ultotal,
					 double ulnow)
{
//	SignalDownload *s=(SignalDownload *)clientp;
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
bool SignalDownload::Download(char *url,TCHAR *filename,long timeout=10)
{
	//初始化
	curl = curl_easy_init();
	if(NULL == curl)
		return false;
	//打开待写文件
	outfile = _tfopen(filename, _T("wb"));
	if(NULL== outfile)
		return false;

	//设置URL地址
	SD_curl_easy_setopt_EXT(curl, CURLOPT_URL, url,res);
	//设置写入的文件指针
	SD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEDATA, outfile,res);
	//设置写入回调函数
	SD_curl_easy_setopt_EXT(curl, CURLOPT_WRITEFUNCTION, SD_WriteFunc,res);
	//设置无进程函数
	SD_curl_easy_setopt_EXT(curl, CURLOPT_NOPROGRESS, FALSE,res);
	//设置进程回调函数
	SD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSFUNCTION, SD_ProgressFunc,res);
	//设置进程回调函数传的自定义参
	SD_curl_easy_setopt_EXT(curl, CURLOPT_PROGRESSDATA, this,res);
	//设置下载速度=0时 N次退出
	SD_curl_easy_setopt_EXT(curl, CURLOPT_TIMEOUT, timeout,res);
	//设置URL地址错误 重连N次后推出
	SD_curl_easy_setopt_EXT(curl, CURLOPT_CONNECTTIMEOUT, timeout,res);
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

	return true;
}
