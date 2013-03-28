// DLGMap.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGMap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern TCHAR MapPath[ZOG_MAX_PATH_STR];
/////////////////////////////////////////////////////////////////////////////
// CDLGMap dialog


CDLGMap::CDLGMap(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGMap::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGMap)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	srcImage=NULL;
}

CDLGMap::~CDLGMap()
{
	cvReleaseImage(&srcImage);
	srcImage=NULL;
}


void CDLGMap::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGMap)
	DDX_Control(pDX, IDC_STATIC_MAP, m_map);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGMap, CDialog)
	//{{AFX_MSG_MAP(CDLGMap)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGMap message handlers

BOOL CDLGMap::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	//载入原始图片
	if(srcImage)
		cvReleaseImage(&srcImage);
	srcImage = cvLoadImage(MapPath, CV_LOAD_IMAGE_UNCHANGED);
	if(NULL==srcImage)
		MessageBox("miss map.bmp file");


	Load();

	AutoSize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGMap::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	rc.top-=15;
	rc.right-=5;
	rc.bottom-=25;

	m_map.MoveWindow(&rc);

	ReSizeShowImage(srcImage);
}

//比例变小，转换成BMP并显示
void CDLGMap::Load()
{
	BuildMap();
	ReSizeShowImage(srcImage);
}


void CDLGMap::BuildMap()
{


}
//比例变小，转换成BMP并显示
void CDLGMap::ReSizeShowImage(IplImage *pImage)
{
	CRect rect;
	m_map.GetClientRect(&rect);

	//自适应大小
	float ratew=(float)rect.Width()/(float)pImage->width;
	float rateh=(float)rect.Height()/(float)pImage->height;
	float rate=ratew < rateh? ratew:rateh;

	int dstw=(int)(pImage->width*rate);
	int dsth=(int)(pImage->height*rate);

	//太小返回
	if(dstw<=10 || dsth<=10)
		return ;

	//创建缩小
	miniImage = cvCreateImage( cvSize(dstw,dsth), IPL_DEPTH_8U, 3 );
	cvResize(pImage,miniImage);
	//转换
	HBITMAP	hbitmap ;
	IplImage2Bmp(miniImage,hbitmap);
	//显示
	m_map.SetBitmap(hbitmap);
	//释放
	cvReleaseImage(&miniImage); 
	miniImage=NULL;

}


bool CDLGMap::IplImage2Bmp(IplImage *pImage,HBITMAP &hBitmap)
{
	if( pImage && pImage->depth == IPL_DEPTH_8U )
    {
        uchar buffer[sizeof(BITMAPINFOHEADER) + 1024];
        BITMAPINFO* bmi = (BITMAPINFO*)buffer;
        int bmp_w = pImage->width, bmp_h = pImage->height;
		
		int width=bmp_w;
		int height=bmp_h;
		int bpp=pImage ? (pImage->depth & 255)*pImage->nChannels : 0;
		int origin=pImage->origin;
		
		assert( bmi && width >= 0 && height >= 0 && (bpp == 8 || bpp == 24 || bpp == 32));
		
		BITMAPINFOHEADER* bmih = &(bmi->bmiHeader);
		
		memset( bmih, 0, sizeof(*bmih));
		bmih->biSize = sizeof(BITMAPINFOHEADER);
		bmih->biWidth = width;
		bmih->biHeight = origin ? abs(height) : -abs(height);
		bmih->biPlanes = 1;
		bmih->biBitCount = (unsigned short)bpp;
		bmih->biCompression = BI_RGB;
		
		if( bpp == 8 )
		{
			RGBQUAD* palette = bmi->bmiColors;
			int i;
			for( i = 0; i < 256; i++ )
			{
				palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
				palette[i].rgbReserved = 0;
			}
		}
		
		hBitmap=CreateDIBitmap(CClientDC(NULL),bmih,CBM_INIT,pImage->imageData,bmi,DIB_RGB_COLORS);
		return true;
    }
	return false;
}

void CDLGMap::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	/*
	// Do not call CDialog::OnPaint() for painting messages
	//贴背景图	
	CRect    rect;     
	GetClientRect(&rect);     
	
	//从资源中载入位图     
	CBitmap    bitmap;     
	bitmap.LoadBitmap(IDB_BITMAP_MAP);    
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	
	CDC    memdc;     
	memdc.CreateCompatibleDC(&dc);     
	memdc.SelectObject(bitmap); 
	dc.SetStretchBltMode(COLORONCOLOR);
	//自适应大小
	float ratew=(float)rect.Width()/(float)bmp.bmWidth;
	float rateh=(float)rect.Height()/(float)bmp.bmHeight;
	float rate=ratew < rateh? ratew:rateh;

//	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	dc.StretchBlt(0,(rect.Height()-bmp.bmHeight*rate)/2,bmp.bmWidth*rate,bmp.bmHeight*rate,
		&memdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);

	memdc.DeleteDC();
	*/
}
