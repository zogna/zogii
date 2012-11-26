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
	//start		起始下载字节
	//输出		下载成功或失败
	//执行下载
	bool HTTPDownload(char *url,TCHAR *filename,long timeout,long startsize);
	//当前完成字节
	long completesize;
	//文件总字节
	long totalsize;

	bool FTPUpload(char *url,char *userpsw,long port,TCHAR *filename,long timeout);
	bool FTPDownload(char *url,char *userpsw,long port,TCHAR *filename,long timeout);
	bool FTPtest(char *url,char *userpsw,long port);

	bool FTPFileinfo(char *url,char *userpsw,long port, time_t *filetime,double *filesize,long timeout);

private:
	CURL *curl;
	CURLcode res;
	FILE *outfile;
	char sizestr[128];
};

#endif