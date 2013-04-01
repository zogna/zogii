#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <stdio.h>


//命令模式： 程序名 文件名1 文件名2.。。。。。
int main( int argc, char** argv ) 
{
	if(argc<2)
		return 0;

	IplImage* src;
	IplImage* dst;

	int params[3];

	params[0] = CV_IMWRITE_JPEG_QUALITY;
	params[1] = 85;//设置s压缩度
	params[2] = 0;

	int i;
	for(i=1;i<argc;i++)
	{
		src = cvLoadImage(argv[i],1);
		
#if 1
	//缩放
		dst = cvCreateImage(cvSize((int)(src->width*0.7),(int)(src->height*0.7)),src->depth,src->nChannels);
		cvResize(src,dst,CV_INTER_LINEAR);

		cvSaveImage(argv[i], dst,params);
		
		cvReleaseImage(&src);
		cvReleaseImage(&dst);

#else
		//直接压缩
		cvSaveImage(argv[i], src,params);
		cvReleaseImage(&src);
#endif

	}

	return 0;
}

