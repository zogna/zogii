#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <stdio.h>


//命令模式： 程序名 文件名1 文件名2.。。。。。
int main( int argc, char** argv ) 
{
	IplImage* frame;

	if(argc<2)
		return 0;

	frame= cvLoadImage(argv[1],1);

	//获取直方图
	IplImage* r_plane = cvCreateImage(cvGetSize(frame),8,1);
	IplImage* g_plane = cvCreateImage(cvGetSize(frame),8,1);
	IplImage* b_plane = cvCreateImage(cvGetSize(frame),8,1);
	IplImage* gray_plane = cvCreateImage(cvGetSize(frame),8,1);

	cvCvtPixToPlane(frame,b_plane,g_plane,r_plane,0);
	cvCvtColor(frame,gray_plane,CV_BGR2GRAY);

	int hist_size=256;
	float range[] = {0,255};
	float* ranges[]={range};

	CvHistogram* r_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);
	CvHistogram* g_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);
	CvHistogram* b_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);
	CvHistogram* gray_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);

	cvCalcHist( &r_plane, r_hist, 0, 0 );
	cvCalcHist( &g_plane, g_hist, 0, 0 );
	cvCalcHist( &b_plane, b_hist, 0, 0 );
	cvCalcHist( &gray_plane, gray_hist, 0, 0 );

	for (int i=0;i<hist_size;i++)
	{
		float  bins= cvQueryHistValue_1D(b_hist,i);
		printf("%f\n",bins);

	}
	cvSaveImage( argv[1], frame );


	cvReleaseImage(&frame);
	return 0;

}