#ifndef __SIGNAL_DOWNLOAD_H
#define __SIGNAL_DOWNLOAD_H
#include "tchar.h"
#include "stdlib.h"
#include "include/curl/curl.h"
#include "include/curl/easy.h"


class SignalDownload
{
public:
	//url		URL地址 
	//filename	文件路径
	//timeout	设定下载超时时限
	//输出		下载成功或失败
	//执行下载
	bool Download(char *url,TCHAR *filename,long timeout);
private:
	CURL *curl;
	CURLcode res;
	FILE *outfile;
};

#endif