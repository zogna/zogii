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
	ON_BN_CLICKED(IDC_PICWIN, OnPicwin)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGpicture message handlers

BOOL CDLGpicture::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	AutoSize();

	/*SetEffectBk();
	  SOLID =0
	  HGRADIENT=1
	  VGRADIENT=2
	  HCGRADIENT=3
	  HVGRADIENT=4
	  3HGRADIENT=5
	  3VGRADIENT=6
	  NOISE =无特效=7
	  DIAGSHADE=8
	  HSHADE=9
	  VSHADE=10
	  HBUMP=11
	  VBUMP=12
	  SOFTBUMP=13
	  HARDBUMP=14
	  METAL=15
	*/
	m_tooltip.Create(this);
	m_tooltip.SetBehaviour(PPTOOLTIP_NOCLOSE_OVER | PPTOOLTIP_CLOSE_LEAVEWND | PPTOOLTIP_DISABLE_AUTOPOP);
	m_tooltip.SetColorBk(RGB(255, 255, 255), RGB(242, 246, 251), RGB(202, 218, 239));
	//m_tooltip.SetCallbackHyperlink(this->GetSafeHwnd(), UNM_HYPERLINK_CLICKED);
	m_tooltip.SetEffectBk(15,0);
	m_tooltip.SetDirection(PPTOOLTIP_BOTTOMEDGE_CENTER);
	//关闭阴影
	m_tooltip.SetTooltipShadow(0, 0, 0, 0, 0, 0);
	m_tooltip.SetImageShadow(0, 0, 0, 0, 0, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGpicture::AutoSize()
{
	CRect rc;
	GetClientRect(&rc);
	//Pannel

	pic_Rect.top = rc.top+5/* + 5*/;
	pic_Rect.bottom = rc.bottom/* - 10*/;
	pic_Rect.left = rc.left+3/* + 10*/;
	pic_Rect.right = rc.right-3;
	GetDlgItem(IDC_PICWIN)->MoveWindow(pic_Rect);

	//显示图片
	if(LoadFlag)
		ReSizeShowImage();

	Invalidate();
}

//载入图片
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
		//图片显示
		//ReSizeShowImage();
		//字
		m_tooltip.AddTool(GetDlgItem(IDC_PICWIN),
	_T("<center><h2>Disables a button</h2></center><br><hr color=green><br>To open URL click<b><a href=\"http://www.codeproject.com\">link</a></b>"));
	}
}

//卸载图片
void CDLGpicture::UnLoad(void)
{	
	if(false==LoadFlag)
		return;

	cvReleaseImage(&m_Image); 
	m_Image=NULL;

	free(txtbuf);
	txtbuf=NULL;
	
	free(picpath);
	picpath=NULL;
	
	m_tooltip.RemoveAllTools();
	LoadFlag=false;
}

//比例变小，转换成BMP并显示
void CDLGpicture::ReSizeShowImage(void)
{
	//宽高限制
#if 0
	int limitw=480;
	int limith=480;
#else
	CRect rect;
	GetDlgItem(IDC_PICWIN)->GetClientRect(&rect);

	int limitw=rect.right-rect.left;
	int limith=rect.bottom-rect.top;
#endif

	int width = m_Image->width;
	int height = m_Image->height;

	int dstw;
	int dsth;
	//等比例缩放
	if((width > limitw) && (width > height))
	{
		dstw=limitw;
		dsth=(int)((float)dstw/(float)width*height);
	}
	if(height > limith)
	{
		dsth=limith;
		dstw=(int)((float)dsth/(float)height*width);
	}
	else
	{
		dstw=width;
		dsth=height;
	}
	//创建缩小
	miniImage = cvCreateImage( cvSize(dstw,dsth), IPL_DEPTH_8U, 3 );
	cvResize(m_Image,miniImage);
	//转换
	HBITMAP	hbitmap ;
	IplImage2Bmp(miniImage,hbitmap);
	//显示
	m_pic.SetBitmap(hbitmap);
	//释放
	cvReleaseImage(&miniImage); 
	miniImage=NULL;

/*
	HBITMAP	hbitmap = (HBITMAP)LoadImage(
		NULL,				// handle of the instance that contains the image
		str,
		IMAGE_BITMAP,		// type of image-- can also be IMAGE_CURSOR or IMAGE_ICON 
		0,0,				// desired width and height
		LR_LOADFROMFILE);	// load flags-- with LR_LOADTRANSPARENT makes transparent to bkgrnd

	char str[260];
	sprintf(str,"%s.bmp",picpath);
	cvSaveImage(str,bmpImage);
*/
	//图片显示的窗口
	/*	
	cvNamedWindow(picpath, 1);
	HWND hWnd = (HWND) cvGetWindowHandle(picpath);
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_PICWIN)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	cvShowImage(picpath,m_Image);
	cvDestroyWindow(picpath);
	*/
}

bool CDLGpicture::IplImage2Bmp(IplImage *pImage,HBITMAP &hBitmap)
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

void CDLGpicture::OnPicwin() 
{
	// TODO: Add your control notification handler code here
	if(LoadFlag)
		NULL;
	//	ShellExecute(this->m_hWnd,NULL,picpath,NULL,NULL,SW_NORMAL);
	//跳转到详细信息

}

//为了TOOLTIP
BOOL CDLGpicture::PreTranslateMessage(MSG* pMsg) 
{
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}


