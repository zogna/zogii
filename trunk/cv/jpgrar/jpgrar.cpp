#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <stdio.h>


//����ģʽ�� ������ �ļ���1 �ļ���2.����������
int main( int argc, char** argv ) 
{
	if(argc<2)
		return 0;

	IplImage* src;
	IplImage* dst;

	int params[3];

	params[0] = CV_IMWRITE_JPEG_QUALITY;
	params[1] = 85;//����sѹ����
	params[2] = 0;

	int i;
	for(i=1;i<argc;i++)
	{
		src = cvLoadImage(argv[i],1);
		
#if 1
	//����
		dst = cvCreateImage(cvSize((int)(src->width*0.7),(int)(src->height*0.7)),src->depth,src->nChannels);
		cvResize(src,dst,CV_INTER_LINEAR);

		cvSaveImage(argv[i], dst,params);
		
		cvReleaseImage(&src);
		cvReleaseImage(&dst);

#else
		//ֱ��ѹ��
		cvSaveImage(argv[i], src,params);
		cvReleaseImage(&src);
#endif

	}

	return 0;
}

