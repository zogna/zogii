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
	//start		��ʼ�����ֽ�
	//���		���سɹ���ʧ��
	//ִ������
	bool Download(char *url,TCHAR *filename,long timeout,long startsize);
	//��ǰ����ֽ�
	long completesize;
	//�ļ����ֽ�
	long totalsize;
private:
	CURL *curl;
	CURLcode res;
	FILE *outfile;
	char sizestr[128];
};

#endif