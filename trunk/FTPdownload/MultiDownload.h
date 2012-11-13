#ifndef __MULTI_DOWNLOAD_H
#define __MULTI_DOWNLOAD_H

#include "tchar.h"
#include "stdlib.h"
#include "include/curl/curl.h"
#include "include/curl/easy.h"

#define MD_URLSTR_MAX	512

typedef struct _MULTI_DOWNLOAD_FILE_ 
{
	//�û����� �ļ�·�� 
	TCHAR filename[MAX_PATH];
	//�û�����URL
	char url[MD_URLSTR_MAX];
	//����ȡ��
	FILE* fp;
	//�û�ȡ�� �ļ������Ƿ�ɹ�
	bool result;
}MULTI_DOWNLOAD_INFO;

class MultiDownload
{
public:
	//MULTI_DOWNLOAD_INFO	N���ṹ��
	//infocount				N
	//sametimecount			ͬʱ�����ļ��ĸ���
	//timeout				��ʱ����
	//����					ִ�гɹ�����ʧ��
	//ִ������
	bool Download(MULTI_DOWNLOAD_INFO *&info,long infocount,long sametimecount,long timeout);
private:
	//��ʼ������
	bool Load(MULTI_DOWNLOAD_INFO *info,long timeout);
	CURLM *curlmulti;
};

#endif