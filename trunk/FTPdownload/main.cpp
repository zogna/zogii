#include "SignalDownload.h"

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
	
	r=a.Download("http://dow111111111.com",_T("a.html"),10);
	printf("result=%d\n",r);

	r=a.Download("http://www.baidu.com",_T("a.html"),10);
	printf("result=%d\n",r);


	////////////////////////////////////
	curl_global_cleanup();
}