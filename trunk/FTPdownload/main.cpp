#include "SignalDownload.h"
#include "MultiDownload.h"

//编译指南：
//属性LINK中 忽略 LIBCMTD.lib
//属性C++中 预定义宏 BUILDING_LIBCURL;HTTP_ONLY

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"wldap32.lib")

#ifdef _DEBUG
	#pragma comment(lib,"debug-ssl-zlib/libcurld.lib")
#else
	#pragma comment(lib,"release-ssl-zlib/libcurl.lib")
#endif

int main(void)
{
	CURLcode res=curl_global_init(CURL_GLOBAL_ALL);
	if(CURLE_OK != res) 
	{												
		fprintf(stderr, "curl told us %s\n", curl_easy_strerror(res));	
		return false;								
	}
	////////////////////////////////////

	SignalDownload a;
	bool r;



	r=a.FTPUpload("ftp://10.142.50.69/video server/a6.html","da:da",21,_T("1.html"),10);
	printf("result=%d\n",r);
	
	r=a.FTPtest("ftp://10.142.50.69","da:da",21);
	printf("result=%d\n",r);
#if 0

	r=a.HTTPDownload("http://dow111111111.com",_T("a.html"),10,0);
	printf("result=%d\n",r);

		r=a.HTTPDownload("http://oa.yirong-info.com:8000/sgccoa/NewNoticeMss1.nsf/0/17F500AE8A9569A348257ABD000B5EFF/$File/附件二%20先进个人评分表.docx",_T("a.html"),10,0);
		printf("result=%d\n",r);
		r=a.HTTPDownload("http://oa.yirong-info.com:8000/pt_index.htm",_T("a.html"),10,0);

		printf("result=%d\n",r);

	////////////////////////////////////
	MultiDownload	b;

	MULTI_DOWNLOAD_INFO data[2]=
	{
		{_T("a.html"),"http://dow111111111.com",NULL,false},
		{_T("a.html"),"http://www.baidu.com",NULL,false},
	};
	MULTI_DOWNLOAD_INFO *p=data;

	r=b.Download(p,2,10,10);
	printf("result=%d,%d,%d\n",r,data[0].result,data[1].result);
#endif	


	////////////////////////////////////
	curl_global_cleanup();
}