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
	bool HTTPDownload(char *url,TCHAR *filename,long timeout,long startsize);
	//��ǰ����ֽ�
	long completesize;
	//�ļ����ֽ�
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