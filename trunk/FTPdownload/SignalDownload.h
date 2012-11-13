#ifndef __SIGNAL_DOWNLOAD_H
#define __SIGNAL_DOWNLOAD_H
#include "tchar.h"
#include "stdlib.h"
#include "include/curl/curl.h"
#include "include/curl/easy.h"


class SignalDownload
{
public:
	//url		URL��ַ 
	//filename	�ļ�·��
	//timeout	�趨���س�ʱʱ��
	//���		���سɹ���ʧ��
	//ִ������
	bool Download(char *url,TCHAR *filename,long timeout);
private:
	CURL *curl;
	CURLcode res;
	FILE *outfile;
};

#endif