#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <stdio.h>

#if 0
//����ģʽ�� ������ �ļ���1 �ļ���2.����������
int main( int argc, char** argv ) 
{
	IplImage* frame;

	if(argc<2)
		return 0;

	frame= cvLoadImage(argv[1],1);

	//��ȡֱ��ͼ
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


	//CvRect rect={0,0,1,frame->height};
	//cvSetImageROI(b_plane,rect);

	cvCalcHist( &r_plane, r_hist, 0, 0 );
	cvCalcHist( &g_plane, g_hist, 0, 0 );
	cvCalcHist( &b_plane, b_hist, 0, 0 );
	cvCalcHist( &gray_plane, gray_hist, 0, 0 );

	//��һ��1.0Ϊ���
	cvNormalizeHist(b_hist,1.0);

	//��ȡֱ��ͼ�����ֵ�����ֵ���ڵ�λ��
	float max_value = 0;
	int max_idx=0;
	cvGetMinMaxHistValue(b_hist, NULL, &max_value, 0, &max_idx);

	double k=0;
	for (int i=0;i<hist_size;i++)
	{
		float  bins= cvQueryHistValue_1D(b_hist,i);
		//	if(i>=179 &&i<=200)
		k+=bins;
		printf("%d=%f\n",i,bins);

	}
	printf("%f",k);

	cvReleaseHist(&r_hist);
	cvReleaseHist(&g_hist);
	cvReleaseHist(&b_hist);
	cvReleaseHist(&gray_hist);


	cvSaveImage( argv[1], frame );


	cvReleaseImage(&frame);
	return 0;

}
#endif 

#if 0

//��ȡֱ��ͼ
int hist_size=256;
float range[] = {0,255};
float* ranges[]={range};

CvHistogram* gray_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);
int k;
for (int i=0;i<gray_plane->width;i++)
{

	k=XCut(0.01,0.95,i,gray_hist,gray_plane, hist_size);
	printf("%d\n",k);
	if(k)
		cvLine( frame,cvPoint(i,0) ,cvPoint(i,frame->height), cvScalar(255,0,0) );

}

cvReleaseHist(&gray_hist);


//��X�᷽���ͼƬ
//����1��ȥ 0����ȥ
//���ò�����Сֵ��ֵstopv �����Ƿ���еĲ������ֵcutv
//��ǰҪ���е�X curx
int XCut(double stopv,double cutv,int curx,CvHistogram* gray_hist,IplImage* gray_plane,int hist_size)
{

	CvRect rect={curx,0,1,gray_plane->height};
	cvSetImageROI(gray_plane,rect);

	cvCalcHist( &gray_plane, gray_hist, 0, 0 );

	//��һ��1.0Ϊ���
	cvNormalizeHist(gray_hist,1.0);

	//��ȡֱ��ͼ�����ֵ�����ֵ���ڵ�λ��
	float max_value = 0;
	int max_idx=0;
	cvGetMinMaxHistValue(gray_hist, NULL, &max_value, 0, &max_idx);

	//�ۼ����ֵ��ǰ�󲨷�ֵ
	double k=0;
	float  v=0;
	//��ǰ
	for (int i=max_idx;i>=0;i--)
	{
		v= cvQueryHistValue_1D(gray_hist,i);

		if(v<stopv)
			break;
		else
			k+=v;
	}

	//���
	for (int i=max_idx;i<hist_size;i++)
	{
		v= cvQueryHistValue_1D(gray_hist,i);

		if(v<stopv)
			break;
		else
			k+=v;
	}
	//�ж��Ƿ����
	if(k>cutv)
		return 1;
	else
		return 0;

}

#endif 

//����ģʽ�� ������ �ļ���1 �ļ���2.����������
int main( int argc, char** argv ) 
{
	IplImage* frame;

	if(argc<2)
		return 0;

	frame= cvLoadImage(argv[1],1);

	IplImage* gray_plane = cvCreateImage(cvGetSize(frame),8,1);
	cvCvtColor(frame,gray_plane,CV_BGR2GRAY);

	IplImage* canny_plane = cvCreateImage(cvGetSize(frame),8,1);

	cvCanny(gray_plane,canny_plane,130,85,3);

	double  minv,maxv;

	int xleft=0,xright=0,ytop=0,ybottom=0;

	for (int i=0;i<canny_plane->width;i++)
	{
		CvRect rect={i,0,1,canny_plane->height};
		cvSetImageROI(canny_plane,rect);

		cvMinMaxLoc(canny_plane,&minv,&maxv);

		if(maxv<80)
		{
			xleft++;
			cvLine( frame,cvPoint(i,0) ,cvPoint(i,frame->height), cvScalar(255,0,0) );
		}
		else
			break;
	}

	for (int i= canny_plane->width-1 ;i>=0;i--)
	{
		CvRect rect={i,0,1,canny_plane->height};
		cvSetImageROI(canny_plane,rect);

		cvMinMaxLoc(canny_plane,&minv,&maxv);

		if(maxv<80)
		{
			xright++;
			cvLine( frame,cvPoint(i,0) ,cvPoint(i,frame->height), cvScalar(255,0,0) );
		}
		else
			break;
	}

	for (int i=0;i<canny_plane->height;i++)
	{
		CvRect rect={0,i,canny_plane->width,1};
		cvSetImageROI(canny_plane,rect);

		cvMinMaxLoc(canny_plane,&minv,&maxv);

		if(maxv<80)
		{
			ytop++;
			cvLine( frame,cvPoint(0,i) ,cvPoint(frame->width,i), cvScalar(255,0,0) );
		}
		else
			break;
	}

	for (int i=canny_plane->height-1;i>=0;i--)
	{
		CvRect rect={0,i,canny_plane->width,1};
		cvSetImageROI(canny_plane,rect);

		cvMinMaxLoc(canny_plane,&minv,&maxv);

		if(maxv<80)
		{
			ybottom++;
			cvLine( frame,cvPoint(0,i) ,cvPoint(frame->width,i), cvScalar(255,0,0) );
		}
		else
			break;
	}
	cvResetImageROI(canny_plane);

	//Ĭ�ϲ���ʾ
	if(3==argc)
	{
		//��ʾ
		cvNamedWindow("src",1);
		cvMoveWindow("src",0,0);
		cvShowImage("src",canny_plane);  

		cvWaitKey(0);
		cvDestroyWindow("src");
	}

	//��������ļ�
	IplImage* newframe = cvCreateImage(cvSize(frame->width-xleft-xright,frame->height-ytop-ybottom),
		frame->depth,frame->nChannels);

	CvRect newrect={xleft,ytop,frame->width-xleft-xright,frame->height-ytop-ybottom};

	cvSetImageROI(frame,newrect);
	cvCopyImage(frame,newframe);
	
	cvSaveImage( argv[1], frame );

	cvReleaseImage(&frame);
	return 0;

}