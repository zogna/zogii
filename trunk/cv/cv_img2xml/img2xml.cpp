
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
	const char* object_filename = argc == 2 ? argv[1] : "box.png";

	CvMemStorage* storage = cvCreateMemStorage(0);

	IplImage* object = cvLoadImage( object_filename, CV_LOAD_IMAGE_GRAYSCALE );

	CvSeq *objectKeypoints = 0, *objectDescriptors = 0;

	// ������ѡȡ�� hessian ��ֵ 500  
	// �Ƿ���չ��1 - ����128ά��������0 - 64ά������
	CvSURFParams params = cvSURFParams(500, 1);

	//��������ͼ������ ���������������� �������������������
	cvExtractSURF( object, 0, &objectKeypoints, &objectDescriptors, storage, params );
	
	//CvSeq д���ļ�
	CvFileStorage* fileStorage = cvOpenFileStorage("contour.xml",0,CV_STORAGE_WRITE);
	//contour1 ΪXML�ֶα����
	cvWrite(fileStorage,"contour1",objectKeypoints);
	cvReleaseFileStorage(&fileStorage);

	return 0;
}
