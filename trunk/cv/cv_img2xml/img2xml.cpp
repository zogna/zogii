
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
	const char* object_filename = argc == 2 ? argv[1] : "box.png";

	CvMemStorage* storage = cvCreateMemStorage(0);

	IplImage* object = cvLoadImage( object_filename, CV_LOAD_IMAGE_GRAYSCALE );

	CvSeq *objectKeypoints = 0, *objectDescriptors = 0;

	// 特征点选取的 hessian 阈值 500  
	// 是否扩展，1 - 生成128维描述符，0 - 64维描述符
	CvSURFParams params = cvSURFParams(500, 1);

	//计算两个图的特征 返回特征点总数。 特征点和特征点描述符
	cvExtractSURF( object, 0, &objectKeypoints, &objectDescriptors, storage, params );
	
	//CvSeq 写入文件
	CvFileStorage* fileStorage = cvOpenFileStorage("contour.xml",0,CV_STORAGE_WRITE);
	//contour1 为XML字段标记名
	cvWrite(fileStorage,"contour1",objectKeypoints);
	cvReleaseFileStorage(&fileStorage);

	return 0;
}
