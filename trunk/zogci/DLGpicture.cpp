// DLGpicture.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGpicture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib, "cvDL.lib") 
#pragma comment(lib, "cxcoreDL.lib") 
#pragma comment(lib, "highguiDL.lib") 

/////////////////////////////////////////////////////////////////////////////
// CDLGpicture dialog


CDLGpicture::CDLGpicture(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGpicture::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGpicture)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	LoadFlag=false;
	txtbuf=NULL;
	m_Image=NULL;
}


void CDLGpicture::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGpicture)
	DDX_Control(pDX, IDC_PICWIN, m_pic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGpicture, CDialog)
	//{{AFX_MSG_MAP(CDLGpicture)
	ON_BN_CLICKED(IDC_TXTWIN, OnTxtwin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGpicture message handlers

BOOL CDLGpicture::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	AutoSize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGpicture::AutoSize()
{
	CRect rc;
	GetClientRect(&rc);
	//Pannel

	pic_Rect.top = rc.top+5/* + 5*/;
	pic_Rect.bottom = rc.bottom-30/* - 10*/;
	pic_Rect.left = rc.left+3/* + 10*/;
	pic_Rect.right = rc.right-3;
	GetDlgItem(IDC_PICWIN)->MoveWindow(pic_Rect);

	CRect txt_Rect;
	txt_Rect.top = 	pic_Rect.bottom/* + 5*/;
	txt_Rect.bottom = rc.bottom/* - 10*/;
	txt_Rect.left = rc.left+3/* + 10*/;
	txt_Rect.right = rc.right-3;
	GetDlgItem(IDC_TXTWIN)->MoveWindow(txt_Rect);

	Invalidate();
}

//����ͼƬ
void CDLGpicture::Load(char *path,char *txt)
{
	UnLoad();

	int len;
	
	m_Image = cvLoadImage(path, 1);
	if(m_Image)
		LoadFlag=true;
	else
	{
		LoadFlag=false;
		return ;
	}

	if(LoadFlag)
	{
		len=strlen(txt);
		txtbuf=(char*)calloc(len,sizeof(char));
		strcpy(txtbuf,txt);
	
		len=strlen(path);
		picpath=(char*)calloc(len,sizeof(char));
		strcpy(picpath,path);
		//ͼƬ��ʾ�Ĵ���
		cvNamedWindow(picpath, 1);
		HWND hWnd = (HWND) cvGetWindowHandle(picpath);
		HWND hParent = ::GetParent(hWnd);
		::SetParent(hWnd, GetDlgItem(IDC_PICWIN)->m_hWnd);
		::ShowWindow(hParent, SW_HIDE);
	}
}

//ж��ͼƬ
void CDLGpicture::UnLoad(void)
{	
	if(false==LoadFlag)
		return;
	//���ٴ���
	cvDestroyWindow(picpath);

	cvReleaseImage(&m_Image); 
	m_Image=NULL;

	if(txtbuf)
	{
		free(txtbuf);
		txtbuf=NULL;
	
		free(picpath);
		picpath=NULL;
	}

	LoadFlag=false;
}

void CDLGpicture::Show(void)
{
	CRect rect;
	GetDlgItem(IDC_PICWIN)->GetClientRect(&rect);

	// �����ʾ�ؼ��� DC
//	CDC* pCDC = GetDlgItem(IDC_PICWIN)->GetDC();

	// ��ȡHDC���豸����������л�ͼ����
//	HDC pHDC = pCDC->GetSafeHdc();


//	ReleaseDC( pCDC);

//
	//ͼ����ʾ
	cvShowImage(picpath,m_Image);
	//�ı���ʾ
	GetDlgItem(IDC_TXTWIN)->SetWindowText(txtbuf);
	
}
void CDLGpicture::ReShow(void)
{
}


void CDLGpicture::OnTxtwin() 
{
	// TODO: Add your control notification handler code here
	
}


void CDLGpicture::ReadImage(CString imgPath)
{
	// ��ȡͼƬ�����浽һ���ֲ����� ipl ��
	//IplImage* ipl = cvLoadImage((const char *)(LPCTSTR)imgPath, 1);


/*
	if((src_.cols > 900) && (src_.cols > src_.rows))
		{
			width_ = 900;
			height_ = int(width_*src_.rows/src_.cols);
		}

		if(src_.rows > 500)
		{
			height_ = 500;
			width_ = int(height_*src_.cols/src_.rows);
		}

		else
		{
			width_ = src_.cols;
			height_ = src_.rows;
		}
*/

	// �Զ����ͼƬ�������ţ�ʹ��������ֵ�պõ���256���ٸ��Ƶ� m_Image ��
//	ResizeImage(ipl);

	// ������ʾͼƬ����
	ShowImage(this->m_Image, IDC_PICWIN);


}

void CDLGpicture::ResizeImage(IplImage* img)
{
	// ��ȡͼƬ�Ŀ�͸�
	int width = img->width;
	int height = img->height;

	// �ҳ���͸ߵĽϴ�ֵ
	int max = (width > height) ? width : height;

	// ���㽫ͼƬ���ŵ�Image��������ı�������
	float scale = (float) ((float) max / 256.0f);

	// ���ź�ͼƬ�Ŀ�͸�
	int nwidth = 100;//(int) (width / scale);
	int nheight = 100;//(int) (height / scale);

	// ����ͼƬ��Image���Ͻǵ���������ֵ
	int tlx = 7;//(nwidth > nheight) ? 0 : (int) (256 - nwidth) / 2;
	int tly = 7;//(nwidth > nheight) ? (int) (256 - nwidth) / 2 : 0;

	// ����Image��ROI�������ڴ���ͼƬImg
	cvSetImageROI(this->m_Image, cvRect( tlx, tly, nwidth, nheight) );

	// ��ͼƬimg�������ţ�������m_Image��
	cvResize( img, this->m_Image);

	// ����m_Image��ROI׼��������һ��ͼ��
	cvResetImageROI(this->m_Image);	  
}

void CDLGpicture::ShowImage(IplImage* img, UINT ID)
{
	// �����ʾ�ؼ��� DC
	CDC* pCDC = GetDlgItem(ID)->GetDC();

	// ��ȡHDC���豸����������л�ͼ����
	HDC pHDC = pCDC->GetSafeHdc();

	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);

	// ���ͼƬ�ؼ��Ŀ�͸�
	int rw = rect.right - rect.left;
	int rh = rect.bottom - rect.top;

	// ��ȡͼƬ�Ŀ�͸�
	int iw = img->width;
	int ih = img->height;

	// ʹͼƬ����ʾλ�������ڿؼ�������
	int tx = (int) (rw - iw) / 2;
	int ty = (int) (rh - ih) / 2;

	SetRect( rect, tx, ty, tx+iw, ty+ih);

	cvNamedWindow("Image Display", 1);
	HWND hWnd = (HWND) cvGetWindowHandle("Image Display");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(ID)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	cvShowImage("Image Display",img);


}
