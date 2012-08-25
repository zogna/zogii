#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <stdio.h>
#include <time.h>

#define WINDOW_NAME "zogii_imageview"
//���������д���
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

// ��������ʾ���ͼ��ĺ���
IplImage* cvShowMultiImages(char* title,
							CvFont *font,int argcinit, char** argv,
							int img_n, IplImage** img) 
{
	// DispImage - the image in which all the input images are to be copied
	IplImage* DispImage;

	int size;    // size - the size of the images in the window
	int i;        // i - the index of the image shown in the window
	int x, y;    // x,y - the coordinate of top left coner of input images
	int w, h;    // w,h - the width and height of the image

	// r - Maximum number of images in a column 
	// c - Maximum number of images in a row 
	int r, c;

	// scale - How much we have to resize the image
	float scale;
	// max - Max value of the width and height of the image
	int max;
	// space - the spacing between images
	int space;

	// Determine the size of the image, 
	// and the number of rows/cols 
	// from number of arguments 
	if (img_n == 1) 
	{
		cvPutText( img[0],  argv[argcinit], cvPoint(0,img[0]->height-10), font,  CV_RGB(255,0,0) );
		cvShowImage( title, img[0]);
		return NULL;
	}
	//�������� �ֱ���
	else if (img_n >= 2 && img_n <= 4) 
	{
		r = 2; 
		if(img_n%r)
			c = img_n/r+1;
		else
			c = img_n/r;

		size = 360;
	}
	else if (img_n >= 5) 
	{
		r = 4; 
		if(img_n%r)
			c = img_n/r+1;
		else
			c = img_n/r;
		size = 240;
	}

	// Loop for img_n number of arguments
	space = 5;

	// Create a new 3 channel image to show all the input images
	DispImage = cvCreateImage( cvSize((space+ size)*r-space, (space+ size)*c-space), IPL_DEPTH_8U, 3 );

	for (i = 0, x = 0, y = 0; i < img_n; i++, x += (space + size))
	{
		// Check whether it is NULL or not
		// If it is NULL, release the image, and return
		if(img[i] == 0) 
		{
			printf("Invalid arguments");
			cvReleaseImage(&DispImage);
			return NULL;
		}

		// Find the width and height of the image
		w = img[i]->width;
		h = img[i]->height;

		// Find whether height or width is greater in order to resize the image
		max = (w > h)? w: h;

		// Find the scaling factor to resize the image
		scale = (float) ( (float) max / size );

		// Used to Align the images
		// i.e. Align the image to next row
		if( i % r == 0 && x!= 0) 
		{
			x  = 0;
			y += space + size;
		}
		//�ϲ�
		// Set the image ROI to display the current image
		cvSetImageROI(DispImage, cvRect(x, y, (int)( w/scale ), (int)( h/scale )));

		// Resize the input image and copy the it to the Single Big Image
		cvResize(img[i], DispImage);

		// Reset the ROI in order to display the next image
		cvResetImageROI(DispImage);
		//д��
		cvPutText( DispImage,  argv[i+argcinit], cvPoint(x,y+size-10), font,  CV_RGB(255,0,0) );
	}

	/*
	// Create a new window, and show the Single Big Image
	//cvNamedWindow( title, 1 );
	cvShowImage( title, DispImage);

	// Release the Image Memory
	cvReleaseImage(&DispImage);
	*/

	return DispImage;
}


double mx = 0, my = 0;  
int dx = 0, dy = 0, horizBar_x = 0, vertiBar_y = 0;  
bool clickVertiBar = false, clickHorizBar = false, needScroll = false;  
CvRect rect_bar_horiz, rect_bar_verti;  


void mouse_callback( int event, int x, int y, int flags, void* param )  
{  
	//���ù����� �˳�
	if (!needScroll)  
		return ;

	switch( event )   
	{  
	case CV_EVENT_LBUTTONDOWN:  
		mx = x, my = y;  
		dx = 0, dy = 0;  
		// �������ʱ��궨λ��ˮƽ������������  
		if (x >= rect_bar_horiz.x && x <= rect_bar_horiz.x+rect_bar_horiz.width  
			&& y >= rect_bar_horiz.y && y<= rect_bar_horiz.y+rect_bar_horiz.height)  
		{  
			clickHorizBar = true;  
		}  
		// �������ʱ��궨λ�ڴ�ֱ������������  
		if (x >= rect_bar_verti.x && x <= rect_bar_verti.x+rect_bar_verti.width  
			&& y >= rect_bar_verti.y && y<= rect_bar_verti.y+rect_bar_verti.height)  
		{  
			clickVertiBar = true;  
		}  
		break;   
	case CV_EVENT_MOUSEMOVE:   
		if (clickHorizBar)  
		{  
			dx = fabs(x-mx) > 1 ? (int)(x-mx) : 0;  
			dy = 0;  
		}  
		if (clickVertiBar)  
		{  
			dx = 0;  
			dy = fabs(y-my) > 1 ? (int)(y-my) : 0;  
		}  
		mx = x, my = y;  
		break;    
	case CV_EVENT_LBUTTONUP:   
		mx = x, my = y;  
		dx = 0, dy = 0;  
		clickHorizBar = false;  
		clickVertiBar = false;  
		break;    
	default:  
		dx = 0, dy = 0;  
		break;  
	}  
}  

void myShowImageScroll(char* title, IplImage* src_img,   
					   int winWidth , int winHeight ) // ��ʾ���ڴ�СĬ��Ϊ 1400��700  
{  
	IplImage* dst_img;  
	CvRect  rect_dst,   // ��������Ч��ͼ����ʾ����  
		rect_src;   // ����ͼ���Ӧ��Դͼ���е�����  
	int imgWidth = src_img->width,   
		imgHeight = src_img->height,  
		barWidth = 25;  // �������Ŀ�ȣ����أ�  
	double  scale_w = (double)imgWidth/(double)winWidth,    // Դͼ���봰�ڵĿ�ȱ�ֵ  
		scale_h = (double)imgHeight/(double)winHeight;  // Դͼ���봰�ڵĸ߶ȱ�ֵ  

	if(scale_w<1)   
		winWidth = imgWidth+barWidth;  
	if(scale_h<1)   
		winHeight = imgHeight+barWidth;  

	int showWidth = winWidth, showHeight = winHeight; // rect_dst �Ŀ�͸�  
	int src_x = 0, src_y = 0;   // Դͼ���� rect_src �����Ͻ�λ��  
	int horizBar_width = 0, horizBar_height = 0,  
		vertiBar_width = 0, vertiBar_height = 0;  

	needScroll = scale_w>1.0 || scale_h>1.0 ? TRUE : FALSE;  
	// ��ͼ������趨�Ĵ��ڴ�С������ʾ������  
	if(needScroll)  
	{  
		dst_img = cvCreateImage(cvSize(winWidth, winHeight),src_img->depth, src_img->nChannels);  
		cvZero(dst_img);  
		// Դͼ���ȴ��ڴ��ڿ�ȣ�����ʾˮƽ������  
		if(scale_w > 1.0)  
		{  
			showHeight = winHeight - barWidth;  
			horizBar_width = (int)((double)winWidth/scale_w);  
			horizBar_height = winHeight-showHeight;  
			horizBar_x = min(  
				max(0,horizBar_x+dx),  
				winWidth-horizBar_width);  
			rect_bar_horiz = cvRect(  
				horizBar_x,   
				showHeight+1,   
				horizBar_width,   
				horizBar_height);  
			// ��ʾˮƽ������  
			cvRectangleR(dst_img, rect_bar_horiz, cvScalarAll(255), -1);  
		}   
		// Դͼ��߶ȴ��ڴ��ڸ߶ȣ�����ʾ��ֱ������  
		if(scale_h > 1.0)  
		{  
			showWidth = winWidth - barWidth;  
			vertiBar_width = winWidth-showWidth;  
			vertiBar_height = (int)((double)winHeight/scale_h);  
			vertiBar_y = min(  
				max(0,vertiBar_y+dy),   
				winHeight-vertiBar_height);  
			rect_bar_verti = cvRect(  
				showWidth+1,   
				vertiBar_y,   
				vertiBar_width,   
				vertiBar_height);  
			// ��ʾ��ֱ������  
			cvRectangleR(dst_img, rect_bar_verti, cvScalarAll(255), -1);  
		}  

		showWidth = min(showWidth,imgWidth);  
		showHeight = min(showHeight,imgHeight);  
		// ���ô�����ʾ���� ROI  
		rect_dst = cvRect(0, 0, showWidth, showHeight);  
		cvSetImageROI(dst_img, rect_dst);  
		// ����Դͼ��� ROI  
		src_x = (int)((double)horizBar_x*scale_w);  
		src_y = (int)((double)vertiBar_y*scale_h);  
		src_x = min(src_x, imgWidth-showWidth);  
		src_y = min(src_y, imgHeight-showHeight);  
		rect_src = cvRect(src_x, src_y, showWidth, showHeight);  
		cvSetImageROI(src_img, rect_src);  
		// ��Դͼ�����ݸ��Ƶ�������ʾ��  
		cvCopy(src_img, dst_img);  

		cvResetImageROI(dst_img);  
		cvResetImageROI(src_img);  

		// ��ʾͼ��͹�����  
		cvShowImage(title,dst_img);  

		cvReleaseImage(&dst_img);  
	}  
	// Դͼ��С���趨���ڣ���ֱ����ʾͼ���޹�����  
	else  
	{  
		cvShowImage(title, src_img);  
	}     
}  

/*
int winOpenFileJPG(wchar_t *buf, int len)
{
        OPENFILENAME ofn;
        buf[0] = 0;
        memset(&ofn, 0, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = buf;
        ofn.nMaxFile = len;
        ofn.lpstrInitialDir = NULL;
        ofn.lpstrTitle = L"zogii: Open JPEG file";
        ofn.lpstrFilter = L"JPEG Files (*.jpg)\0*.jpg\0All Files\0*\0\0";
        ofn.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
        return GetOpenFileName(&ofn);
}

int winOpenFileTXT(wchar_t *buf, int len)
{
        OPENFILENAME ofn;
        buf[0] = 0;
        memset(&ofn, 0, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = buf;
        ofn.nMaxFile = len;
        ofn.lpstrInitialDir = NULL;
        ofn.lpstrTitle = L"zogii: Open TXT file";
        ofn.lpstrFilter = L"TXT Files (*.txt)\0*.txt\0All Files\0*\0\0";
        ofn.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
        return GetOpenFileName(&ofn);
}
*/
/*
	wchar_t buf[1000];
	winOpenFileJPG(buf,1000);
*/

//����ģʽ�� ������ �ļ���1 �ļ���2.����������
int main( int argc, char** argv ) 
{
	cvNamedWindow(WINDOW_NAME,1);
	cvMoveWindow(WINDOW_NAME,0,0);

	CvFont timeFont;
	cvInitFont(&timeFont,  CV_FONT_HERSHEY_TRIPLEX,0.5,0.5,0,1,8);

	// Bitwise inversion of every element of the current frame
	int i,image_num,argcinit;

	IplImage* frame[100];

	//����ͼƬ
	image_num=0;
	argcinit=1;
	for(i=argcinit;i<argc;i++)
	{
		frame[i-argcinit]= cvLoadImage(argv[i],1);
		image_num++;
	}

	//ͼ��ϲ�
	IplImage* DispImage=cvShowMultiImages(WINDOW_NAME,&timeFont,argcinit, argv,image_num,frame);

	//���ͼƬ
	for(i=0;i<image_num;i++)
	{
		cvReleaseImage(&frame[i]);
	}

	//��һ��ͼƬ
	if(DispImage!=NULL)
	{
		int width=800, height=600;

		cvSetMouseCallback(WINDOW_NAME, mouse_callback);  

		while(1)  
		{  
			myShowImageScroll(WINDOW_NAME, DispImage, width, height);  
				
			if( 27 == cvWaitKey(10) )  
				break;  
		}  
		
		cvReleaseImage(&DispImage);
	}

	cvDestroyWindow(WINDOW_NAME);

	return 0;

}