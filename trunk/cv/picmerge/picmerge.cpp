/*
* A Demo to OpenCV Implementation of SURF
* Further Information Refer to "SURF: Speed-Up Robust Feature"
* Author: Liu Liu
* liuliu.1987+opencv@gmail.com
*/
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc_c.h>

#include <iostream>
#include <vector>

using namespace std;

// define whether to use approximate nearest-neighbor search
#define USE_FLANN


IplImage *image = 0;

double
compareSURFDescriptors( const float* d1, const float* d2, double best, int length )
{
	double total_cost = 0;
	assert( length % 4 == 0 );
	for( int i = 0; i < length; i += 4 )
	{
		double t0 = d1[i] - d2[i];
		double t1 = d1[i+1] - d2[i+1];
		double t2 = d1[i+2] - d2[i+2];
		double t3 = d1[i+3] - d2[i+3];
		total_cost += t0*t0 + t1*t1 + t2*t2 + t3*t3;
		if( total_cost > best )
			break;
	}
	return total_cost;
}


int
naiveNearestNeighbor( const float* vec, int laplacian,
					 const CvSeq* model_keypoints,
					 const CvSeq* model_descriptors )
{
	int length = (int)(model_descriptors->elem_size/sizeof(float));
	int i, neighbor = -1;
	double d, dist1 = 1e6, dist2 = 1e6;
	CvSeqReader reader, kreader;
	cvStartReadSeq( model_keypoints, &kreader, 0 );
	cvStartReadSeq( model_descriptors, &reader, 0 );

	for( i = 0; i < model_descriptors->total; i++ )
	{
		const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
		const float* mvec = (const float*)reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		if( laplacian != kp->laplacian )
			continue;
		d = compareSURFDescriptors( vec, mvec, dist2, length );
		if( d < dist1 )
		{
			dist2 = dist1;
			dist1 = d;
			neighbor = i;
		}
		else if ( d < dist2 )
			dist2 = d;
	}
	if ( dist1 < 0.6*dist2 )
		return neighbor;
	return -1;
}

void
findPairs( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors,
		  const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, vector<int>& ptpairs )
{
	int i;
	CvSeqReader reader, kreader;
	cvStartReadSeq( objectKeypoints, &kreader );
	cvStartReadSeq( objectDescriptors, &reader );
	ptpairs.clear();

	for( i = 0; i < objectDescriptors->total; i++ )
	{
		const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
		const float* descriptor = (const float*)reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		int nearest_neighbor = naiveNearestNeighbor( descriptor, kp->laplacian, imageKeypoints, imageDescriptors );
		if( nearest_neighbor >= 0 )
		{
			ptpairs.push_back(i);
			ptpairs.push_back(nearest_neighbor);
		}
	}
}


void
flannFindPairs( const CvSeq*, const CvSeq* objectDescriptors,
			   const CvSeq*, const CvSeq* imageDescriptors, vector<int>& ptpairs )
{
	int length = (int)(objectDescriptors->elem_size/sizeof(float));

	cv::Mat m_object(objectDescriptors->total, length, CV_32F);
	cv::Mat m_image(imageDescriptors->total, length, CV_32F);


	// copy descriptors
	CvSeqReader obj_reader;
	float* obj_ptr = m_object.ptr<float>(0);
	cvStartReadSeq( objectDescriptors, &obj_reader );
	for(int i = 0; i < objectDescriptors->total; i++ )
	{
		const float* descriptor = (const float*)obj_reader.ptr;
		CV_NEXT_SEQ_ELEM( obj_reader.seq->elem_size, obj_reader );
		memcpy(obj_ptr, descriptor, length*sizeof(float));
		obj_ptr += length;
	}
	CvSeqReader img_reader;
	float* img_ptr = m_image.ptr<float>(0);
	cvStartReadSeq( imageDescriptors, &img_reader );
	for(int i = 0; i < imageDescriptors->total; i++ )
	{
		const float* descriptor = (const float*)img_reader.ptr;
		CV_NEXT_SEQ_ELEM( img_reader.seq->elem_size, img_reader );
		memcpy(img_ptr, descriptor, length*sizeof(float));
		img_ptr += length;
	}

	// find nearest neighbors using FLANN
	cv::Mat m_indices(objectDescriptors->total, 2, CV_32S);
	cv::Mat m_dists(objectDescriptors->total, 2, CV_32F);
	cv::flann::Index flann_index(m_image, cv::flann::KDTreeIndexParams(4));  // using 4 randomized kdtrees
	flann_index.knnSearch(m_object, m_indices, m_dists, 2, cv::flann::SearchParams(64) ); // maximum number of leafs checked

	int* indices_ptr = m_indices.ptr<int>(0);
	float* dists_ptr = m_dists.ptr<float>(0);
	for (int i=0;i<m_indices.rows;++i) {
		if (dists_ptr[2*i]<0.6*dists_ptr[2*i+1]) {
			ptpairs.push_back(i);
			ptpairs.push_back(indices_ptr[2*i]);
		}
	}
}


/* a rough implementation for object location */
int
locatePlanarObject( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors,
				   const CvSeq* imageKeypoints, const CvSeq* imageDescriptors,
				   const CvPoint src_corners[4], CvPoint dst_corners[4] )
{

	double h[9];
	CvMat _h = cvMat(3, 3, CV_64F, h);
	vector<int> ptpairs;
	vector<CvPoint2D32f> pt1, pt2;
	CvMat _pt1, _pt2;
	int i, n;

#ifdef USE_FLANN
	flannFindPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
#else
	findPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
#endif

	n = (int)(ptpairs.size()/2);
	if( n < 4 )
		return 0;

	pt1.resize(n);
	pt2.resize(n);
	for( i = 0; i < n; i++ )
	{
		pt1[i] = ((CvSURFPoint*)cvGetSeqElem(objectKeypoints,ptpairs[i*2]))->pt;
		pt2[i] = ((CvSURFPoint*)cvGetSeqElem(imageKeypoints,ptpairs[i*2+1]))->pt;
	}

	_pt1 = cvMat(1, n, CV_32FC2, &pt1[0] );
	_pt2 = cvMat(1, n, CV_32FC2, &pt2[0] );
	if( !cvFindHomography( &_pt1, &_pt2, &_h, CV_RANSAC, 5 ))
		return 0;

	for( i = 0; i < 4; i++ )
	{
		double x = src_corners[i].x, y = src_corners[i].y;
		double Z = 1./(h[6]*x + h[7]*y + h[8]);
		double X = (h[0]*x + h[1]*y + h[2])*Z;
		double Y = (h[3]*x + h[4]*y + h[5])*Z;
		dst_corners[i] = cvPoint(cvRound(X), cvRound(Y));
	}

	return 1;
}


/* a rough implementation for object location */
int
zoglocatePlanarObject( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors,
					  const CvSeq* imageKeypoints, const CvSeq* imageDescriptors,
					  CvMat *_h)
{
	vector<int> ptpairs;
	vector<CvPoint2D32f> pt1, pt2;
	CvMat _pt1, _pt2;
	int i, n;

#ifdef USE_FLANN
	flannFindPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
#else
	findPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
#endif

	n = (int)(ptpairs.size()/2);
	if( n < 4 )
		return 0;

	pt1.resize(n);
	pt2.resize(n);
	for( i = 0; i < n; i++ )
	{
		pt1[i] = ((CvSURFPoint*)cvGetSeqElem(objectKeypoints,(ptpairs)[i*2]))->pt;
		pt2[i] = ((CvSURFPoint*)cvGetSeqElem(imageKeypoints,(ptpairs)[i*2+1]))->pt;
	}

	_pt1 = cvMat(1, n, CV_32FC2, &pt1[0] );
	_pt2 = cvMat(1, n, CV_32FC2, &pt2[0] );
	if( !cvFindHomography( &_pt1, &_pt2, _h, CV_RANSAC, 5 ))
		return 0;

	return 1;
}

//同通道 两个图片相融合 支持ROI
void zogAlpha(IplImage *src,IplImage *dst,float alpha,float beta)
{
	int i,j,m,n,k;
	int dsty,dsth,dstx,dstw;
	//设置ROI
	if(dst->roi)
	{
		dsty=dst->roi->yOffset;
		dsth=dst->roi->yOffset + dst->roi->height;
		dstx=dst->roi->xOffset;
		dstw=dst->roi->xOffset + dst->roi->width;
	}
	else
	{
		dsty=0;
		dsth=dst->height;
		dstx=0;
		dstw=dst->width;
	}

	unsigned char *srcp,*dstp;
	int nullflag=0;

	for(i=dsty,m=0;i<dsth && m< src->height ;i++,m++)
	{
		if(i< 0 || i>= dst->height)
			continue;

		srcp=(unsigned char *)(src->imageData + m*src->widthStep);
		dstp=(unsigned char *)(dst->imageData + i*dst->widthStep);

		for(j=dstx,n=0;j<dstw && n< src->width ;j++,n++)
		{
			if(j< 0 || j>= dst->width)
				continue;

			//判断是否有值
			nullflag=0;
			for(k=0;k<dst->nChannels;k++)
				nullflag=dstp[dst->nChannels*j+k];
			//有值用融合
			if(nullflag)
			{
				for(k=0;k<dst->nChannels;k++)
					dstp[dst->nChannels*j+k]=(unsigned char)(int)(dstp[dst->nChannels*j+k]*alpha + srcp[src->nChannels*n+k]*beta);
			}
			else
			{
				//无值就直接拷贝
				for(k=0;k<dst->nChannels;k++)
					dstp[dst->nChannels*j+k]=srcp[src->nChannels*n+k];
			}
		}
	}

}

int main(int argc, char** argv)
{

	IplImage* src_image[100];
	IplImage* gray_image[100];
	IplImage* dst_image,*dstgray_image;

	int i;

	CvMemStorage* storage = cvCreateMemStorage(0);

	int dstw=0,dsth=0;

	for( i=1;i<argc;i++)
	{
		src_image[i-1] = cvLoadImage( argv[i], CV_LOAD_IMAGE_COLOR );
		gray_image[i-1] = cvCreateImage(cvGetSize(src_image[i-1]), 8, 1);
		cvCvtColor( src_image[i-1], gray_image[i-1], CV_BGR2GRAY );
		dstw+=src_image[i-1]->width;
		dsth+=src_image[i-1]->height;
	}
	dst_image = cvCreateImage(cvSize(dstw,dsth), 8, 3);
	dstgray_image = cvCreateImage(cvSize(dstw,dsth), 8, 1);
	cvZero(dst_image);
	cvZero(dstgray_image);

	// 特征点选取的 hessian 阈值 500  
	// 是否扩展，1 - 生成128维描述符，0 - 64维描述符
	CvSURFParams params = cvSURFParams(500, 1);
	CvSeq *objectKeypoints = 0, *objectDescriptors = 0;
	CvSeq *imageKeypoints = 0, *imageDescriptors = 0;

	//拷贝第一张图到原始位置
	cvSetImageROI( dst_image, cvRect( 0,0,  src_image[0]->width,  src_image[0]->height ) );
	cvCopy( src_image[0], dst_image );
	cvResetImageROI( dst_image );

	cvSetImageROI( dstgray_image, cvRect( 0,0,  gray_image[0]->width,  gray_image[0]->height ) );
	cvCopy( gray_image[0], dstgray_image );
	cvResetImageROI( dstgray_image );

	CvPoint dst_corners[4];

	double h[9];
	CvMat _h = cvMat(3, 3, CV_64F, h);

	CvMat* warp_matrix=cvCreateMat(3,3,CV_32FC1);

	for( i=2;i<argc;i++)
	{

		//计算两个图的特征 返回特征点总数。 特征点和特征点描述符
		cvExtractSURF( gray_image[i-1], 0, &objectKeypoints, &objectDescriptors, storage, params );

		cvExtractSURF( dstgray_image, 0, &imageKeypoints, &imageDescriptors, storage, params );

		CvPoint src_corners[4] = {{0,0}, {gray_image[i-1]->width,0}, {gray_image[i-1]->width, gray_image[i-1]->height}, {0, gray_image[i-1]->height}};


		//if( zoglocatePlanarObject( objectKeypoints, objectDescriptors, imageKeypoints,imageDescriptors, &_h ))
		if( locatePlanarObject( objectKeypoints, objectDescriptors, imageKeypoints,
			imageDescriptors, src_corners, dst_corners ))
		{
			CvPoint2D32f srcQuad[4]={cvPointTo32f(src_corners[0]),cvPointTo32f(src_corners[1]),cvPointTo32f(src_corners[2]),cvPointTo32f(src_corners[3])};
			CvPoint2D32f dstQuad[4]={cvPointTo32f(dst_corners[0]),cvPointTo32f(dst_corners[1]),cvPointTo32f(dst_corners[2]),cvPointTo32f(dst_corners[3])};

			cvGetPerspectiveTransform(srcQuad,dstQuad,warp_matrix);

		cvWarpPerspective (gray_image[i-1],dstgray_image,warp_matrix);



		}
	}



	cvNamedWindow("warp", 1);

	cvShowImage( "warp", dstgray_image );
	cvWaitKey(0);

	cvDestroyWindow("warp");

	for( i=1;i<argc;i++)
	{
		cvReleaseImage(&src_image[i-1] );
		cvReleaseImage(&gray_image[i-1] );
	}
	cvReleaseImage(&dst_image);
	cvReleaseImage(&dstgray_image);
#if 0




	double tt = (double)cvGetTickCount();

	//特征计算时间 秒
	tt = (double)cvGetTickCount() - tt;
	printf( "Extraction time = %gms\n", tt/(cvGetTickFrequency()*1000.));
	//下面将两个图片载合并载到一个大图片里。方便显示
	CvPoint src_corners[4] = {{0,0}, {object->width,0}, {object->width, object->height}, {0, object->height}};
	CvPoint dst_corners[4];
	IplImage* correspond = cvCreateImage( cvSize(image->width, object->height+image->height), 8, 1);
	cvSetImageROI( correspond, cvRect( 0, 0, object->width, object->height ) );
	cvCopy( object, correspond );
	cvSetImageROI( correspond, cvRect( 0, object->height, correspond->width, correspond->height ) );
	cvCopy( image, correspond );
	cvResetImageROI( correspond );

#ifdef USE_FLANN
	printf("Using approximate nearest neighbor search USE_FLANN\n");
#endif
	//	画平行四边形
	if( locatePlanarObject( objectKeypoints, objectDescriptors, imageKeypoints,
		imageDescriptors, src_corners, dst_corners ))
	{
		for( i = 0; i < 4; i++ )
		{
			CvPoint r1 = dst_corners[i%4];
			CvPoint r2 = dst_corners[(i+1)%4];
			cvLine( correspond, cvPoint(r1.x, r1.y+object->height ),
				cvPoint(r2.x, r2.y+object->height ), colors[8] );
		}

	}
	/////////////////////////////透视变换
	CvPoint2D32f srcQuad[4]={cvPointTo32f(src_corners[0]),cvPointTo32f(src_corners[1]),cvPointTo32f(src_corners[2]),cvPointTo32f(src_corners[3])};
	CvPoint2D32f dstQuad[4]={cvPointTo32f(dst_corners[0]),cvPointTo32f(dst_corners[1]),cvPointTo32f(dst_corners[2]),cvPointTo32f(dst_corners[3])};

	CvMat* warp_matrix=cvCreateMat(3,3,CV_32FC1);
	IplImage *dstpp= cvCreateImage(cvSize(512,512), 8, 1);
	cvZero(dstpp);


	for(int i=0;i<4;i++)
	{
		dstQuad[i].x +=150;
		dstQuad[i].y +=20;
	}

	cvGetPerspectiveTransform(srcQuad,dstQuad,warp_matrix);

	cvWarpPerspective (object,dstpp,warp_matrix);

	//cvWarpPerspective (object,dstpp,&_h);

	/*

	CvRect	rect_src = cvRect(200, 200, 256, 256);  
	cvSetImageROI(dstpp, rect_src);  


	cvResetImageROI(dstpp);  
	*/


	cvNamedWindow("warp", 1);

	cvShowImage( "warp", dstpp );


	cvNamedWindow("Object", 1);
	cvNamedWindow("Object Correspond", 1);


	cvShowImage( "Object Correspond", correspond );
	cvShowImage( "Object", object_color );

	//退出
	cvWaitKey(0);

	cvDestroyWindow("warp");
	cvDestroyWindow("Object");
	cvDestroyWindow("Object Correspond");
#endif
	return 0;
}
