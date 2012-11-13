#ifndef __MULTI_DOWNLOAD_H
#define __MULTI_DOWNLOAD_H

#include "tchar.h"
#include "stdlib.h"
#include "include/curl/curl.h"
#include "include/curl/easy.h"

#define MD_URLSTR_MAX	512

typedef struct _MULTI_DOWNLOAD_FILE_ 
{
	//用户传递 文件路径 
	TCHAR filename[MAX_PATH];
	//用户传递URL
	char url[MD_URLSTR_MAX];
	//类中取用
	FILE* fp;
	//用户取用 文件下载是否成功
	bool result;
}MULTI_DOWNLOAD_INFO;

class MultiDownload
{
public:
	//MULTI_DOWNLOAD_INFO	N个结构体
	//infocount				N
	//sametimecount			同时下载文件的个数
	//timeout				超时设置
	//返回					执行成功或者失败
	//执行下载
	bool Download(MULTI_DOWNLOAD_INFO *&info,long infocount,long sametimecount,long timeout);
private:
	//初始化载入
	bool Load(MULTI_DOWNLOAD_INFO *info,long timeout);
	CURLM *curlmulti;
};

#endif