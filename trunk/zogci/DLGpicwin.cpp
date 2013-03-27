// DLGpicwin.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGpicwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib, "cvDL.lib") 
#pragma comment(lib, "cxcoreDL.lib") 
#pragma comment(lib, "highguiDL.lib") 

DLGpicwin *DlgPicWin;

unsigned int IDC_PICWIN_RES[]=
{
	IDC_BUTTON_PICWIN1,
		IDC_BUTTON_PICWIN2,
		IDC_BUTTON_PICWIN3,
		IDC_BUTTON_PICWIN4,
		IDC_BUTTON_PICWIN5,
		IDC_BUTTON_PICWIN6,
		IDC_BUTTON_PICWIN7,
		IDC_BUTTON_PICWIN8,
		IDC_BUTTON_PICWIN9,
		IDC_BUTTON_PICWIN10,
		IDC_BUTTON_PICWIN11,
		IDC_BUTTON_PICWIN12,
		IDC_BUTTON_PICWIN13,
		IDC_BUTTON_PICWIN14,
		IDC_BUTTON_PICWIN15,
		IDC_BUTTON_PICWIN16,
		IDC_BUTTON_PICWIN17,
		IDC_BUTTON_PICWIN18,
		IDC_BUTTON_PICWIN19,
		IDC_BUTTON_PICWIN20,
		IDC_BUTTON_PICWIN21,
		IDC_BUTTON_PICWIN22,
		IDC_BUTTON_PICWIN23,
		IDC_BUTTON_PICWIN24,
		IDC_BUTTON_PICWIN25,
		IDC_BUTTON_PICWIN26,
		IDC_BUTTON_PICWIN27,
		IDC_BUTTON_PICWIN28,
		IDC_BUTTON_PICWIN29,
		IDC_BUTTON_PICWIN30,
};

/////////////////////////////////////////////////////////////////////////////
// DLGpicwin dialog


DLGpicwin::DLGpicwin(CWnd* pParent /*=NULL*/)
	: CDialog(DLGpicwin::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLGpicwin)
	//}}AFX_DATA_INIT
	CurrentPicWinMax=MIN_PICTURE_WIN;
	DlgPicWin=this;
	flag=0;
}


void DLGpicwin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLGpicwin)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLGpicwin, CDialog)
	//{{AFX_MSG_MAP(DLGpicwin)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN1, OnButtonPicwin1)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN2, OnButtonPicwin2)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN3, OnButtonPicwin3)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN4, OnButtonPicwin4)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN5, OnButtonPicwin5)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN6, OnButtonPicwin6)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN7, OnButtonPicwin7)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN8, OnButtonPicwin8)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN9, OnButtonPicwin9)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN10, OnButtonPicwin10)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN11, OnButtonPicwin11)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN12, OnButtonPicwin12)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN13, OnButtonPicwin13)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN14, OnButtonPicwin14)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN15, OnButtonPicwin15)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN16, OnButtonPicwin16)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN17, OnButtonPicwin17)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN18, OnButtonPicwin18)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN19, OnButtonPicwin19)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN20, OnButtonPicwin20)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN21, OnButtonPicwin21)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN22, OnButtonPicwin22)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN23, OnButtonPicwin23)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN24, OnButtonPicwin24)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN25, OnButtonPicwin25)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN26, OnButtonPicwin26)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN27, OnButtonPicwin27)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN28, OnButtonPicwin28)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN29, OnButtonPicwin29)
	ON_BN_CLICKED(IDC_BUTTON_PICWIN30, OnButtonPicwin30)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLGpicwin message handlers

BOOL DLGpicwin::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	DlgResultPannel.Create(IDD_RESULT_PANNEL,this);
	DlgResultPannel.ShowWindow(SW_SHOW);

	InitToolTip();

	//初始化
	int i;
	for(i=0;i<MAX_PICTURE_WIN;i++)
	{
		PicWinData[i].LoadFlag=false;
		PicWinData[i].buttonres=(CButton *)GetDlgItem(IDC_PICWIN_RES[i]);
	}

	//放在所有CREATE最后
	AutoSize();

	Load(0,"1.jpg","sb");
	Load(1,"22.jpg",
		_T("<center><h2>Disables a button</h2></center><br><hr color=green><br>To open URL click<b><a href=\"http://www.codeproject.com\">link</a></b>"));

	//idres=136  136这个数字是 IDB_BITMAP1的宏定义 #define IDB_BITMAP1                     136
//	_T("<b><i>Click to: ...</i></b><br><right><b>go to <h2>link</h2> <a href=\"http://www.codeproject.com\"><bmp idres=136 mask hotstyle=s></a></b>"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}
//////////////////////////////////////////////////////////////////////
void DLGpicwin::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	switch(flag)
	{
	case FLAG_WIN_RESULT:	
		GetClientRect(&rc);
		break;
	case FLAG_WIN_ADULT	:
	case FLAG_WIN_LARVA	:
	case FLAG_WIN_PUPA	:
	case FLAG_WIN_OVUM	:
	case FLAG_WIN_OTHER	:
		GetParent()->GetClientRect(&rc);
		((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
		MoveWindow(&rc);
		rc.top-=15;
		rc.bottom-=20;
		break;
	default:MessageBox("DLGpicwin::AutoSize error"); break;
	}
	//变化的框
	AutoSizePictureWin(rc);

	//Pannel
	CRect website_Rect;
	website_Rect.top = rc.bottom-30/* + 5*/;
	website_Rect.bottom = rc.bottom/* - 10*/;
	website_Rect.left = rc.left+50/* + 10*/;
	website_Rect.right = rc.right;
	//必须 样式=重叠，边框=调整大小
	DlgResultPannel.MoveWindow(website_Rect);

	//调整图片
	int i;
	for(i=0;i<MAX_PICTURE_WIN;i++)
	{
		if(PicWinData[i].LoadFlag)
			//图片显示
			ReSizeShowImage(PicWinData[i].buttonres,PicWinData[i].Image);
	}

	Invalidate();
}

void DLGpicwin::AutoSizePictureWin(CRect rc)
{
	CRect rect;
	int i;

	int w;
	int h;

	rc.bottom-=30;

	switch(CurrentPicWinMax)
	{
	case MAX_PICTURE_WIN	:w=6;h=5;break;	
	case MID_PICTURE_WIN	:w=5;h=4;break;	
	case MIN_PICTURE_WIN	:w=4;h=3;break;	
	default:MessageBox("DLGpicwin::AutoSizePictureWin ERROR");return;
	}

	int lwidth=(rc.right-rc.left)/w;
	int lhight=(rc.bottom-rc.top)/h;
	int rwidth=(rc.right-rc.left)/w-5;
	int rhight=(rc.bottom-rc.top)/h-5;

	for(i=0;i<CurrentPicWinMax;i++)
	{
		//Pannel
		rect.top = rc.top+i/w*lhight /* + 5*/;
		rect.bottom = rect.top+rhight/* - 10*/;
		rect.left = rc.left+i%w*lwidth/* + 10*/;
		rect.right = rect.left+rwidth;
		//必须 样式=重叠，边框=调整大小
		GetDlgItem(IDC_PICWIN_RES[i])->MoveWindow(rect);
		GetDlgItem(IDC_PICWIN_RES[i])->ShowWindow(SW_SHOW);
	}

	for(NULL;i<MAX_PICTURE_WIN;i++)
		GetDlgItem(IDC_PICWIN_RES[i])->ShowWindow(SW_HIDE);
}

//////////////////////////////////TOOL TIP//////////////////////////////////
void DLGpicwin::InitToolTip(void)
{
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
	m_tooltip.SetEffectBk(15,10);
	m_tooltip.SetDirection(PPTOOLTIP_LEFTEDGE_VCENTER);
	//关闭阴影
	m_tooltip.SetTooltipShadow(0, 0, 0, 0, 0, 0);
}

BOOL DLGpicwin::PreTranslateMessage(MSG* pMsg) 
{
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
//////////////////////////////////////////////////////////////
//比例变小，转换成BMP并显示
void DLGpicwin::ReSizeShowImage(CButton *buttonres,IplImage *pImage)
{
	//宽高限制
#if 0
	int limitw=480;
	int limith=480;
#else
	CRect rect;
	GetDlgItem(IDC_BUTTON_PICWIN1)->GetClientRect(&rect);

	int limitw=rect.right-rect.left;
	int limith=rect.bottom-rect.top;
#endif

	int width = pImage->width;
	int height = pImage->height;

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
	cvResize(pImage,miniImage);
	//转换
	HBITMAP	hbitmap ;
	IplImage2Bmp(miniImage,hbitmap);
	//显示
	buttonres->SetBitmap(hbitmap);
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

bool DLGpicwin::IplImage2Bmp(IplImage *pImage,HBITMAP &hBitmap)
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

//////////////////////////////////////////////
void DLGpicwin::Load(int i,char *path,char* txt)
{
	UnLoad(i);
	
	PicWinData[i].Image = cvLoadImage(path, 1);
	if(PicWinData[i].Image )
		PicWinData[i].LoadFlag=true;
	else
	{
		PicWinData[i].LoadFlag=false;
		return ;
	}

	if(PicWinData[i].LoadFlag)
	{
		strcpy(PicWinData[i].path,path);

		//图片显示
		ReSizeShowImage(PicWinData[i].buttonres,PicWinData[i].Image);

		switch(flag)
		{
		case FLAG_WIN_RESULT:	
			ResultToolTipLoad(i,txt);
			break;
		case FLAG_WIN_ADULT	:
		case FLAG_WIN_LARVA	:
		case FLAG_WIN_PUPA	:
		case FLAG_WIN_OVUM	:
		case FLAG_WIN_OTHER	:
			//字
			m_tooltip.AddTool(PicWinData[i].buttonres,txt);
			break;
		default:MessageBox("DLGpicwin::Load error"); break;
		}
	}
}
//卸载图片
void DLGpicwin::UnLoad(int i)
{	
	if(false==PicWinData[i].LoadFlag)
		return;

	memset(PicWinData[i].path,0,ZOG_MAX_PATH_STR*sizeof(char));

	cvReleaseImage(&PicWinData[i].Image); 
	PicWinData[i].Image=NULL;

	m_tooltip.RemoveTool(PicWinData[i].buttonres);
	PicWinData[i].LoadFlag=false;
}
//为结果窗口设计的TOOLTIP
void DLGpicwin::ResultToolTipLoad(int i,char* title)
{
	int limitw=500;
	int limith=500;

	int width = PicWinData[i].Image->width;
	int height = PicWinData[i].Image->height;

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
	cvResize(PicWinData[i].Image,miniImage);
	//转换
	HBITMAP	hbitmap ;
	IplImage2Bmp(miniImage,hbitmap);

	char str[1024];
	//宽高限制
	//file=\"%s\"
	sprintf(str,"<center><h2>%s</h2></center><br><hr color=green><br><bmp handle=0x%x mask hotstyle=s width=%d height=%d>",
		title,hbitmap,dstw,dsth);
	//TOOLTIP
	m_tooltip.AddTool(PicWinData[i].buttonres,str);
	//释放
	cvReleaseImage(&miniImage); 
	miniImage=NULL;
}

////////////////////////////////////////////////////////
//点击按钮事件
void DLGpicwin::PicButtonClick(int i) 
{
	//未载入
	if(!PicWinData[i].LoadFlag)
		return ;

	switch(flag)
	{
	case FLAG_WIN_RESULT:	
		//跳到INFO信息
		break;
	case FLAG_WIN_ADULT	:
	case FLAG_WIN_LARVA	:
	case FLAG_WIN_PUPA	:
	case FLAG_WIN_OVUM	:
	case FLAG_WIN_OTHER	:
		//弹大图
		ShellExecute(this->m_hWnd,NULL,PicWinData[i].path,NULL,NULL,SW_NORMAL);
		break;
	default:MessageBox("DLGpicwin::AutoSize error"); break;
	}
}
/////////
void DLGpicwin::OnButtonPicwin1() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(0);
}

void DLGpicwin::OnButtonPicwin2() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(1);
}

void DLGpicwin::OnButtonPicwin3() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(2);
}

void DLGpicwin::OnButtonPicwin4() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(3);
}

void DLGpicwin::OnButtonPicwin5() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(4);
}

void DLGpicwin::OnButtonPicwin6() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(5);
}

void DLGpicwin::OnButtonPicwin7() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(6);
}

void DLGpicwin::OnButtonPicwin8() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(7);
}

void DLGpicwin::OnButtonPicwin9() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(8);
}

void DLGpicwin::OnButtonPicwin10() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(9);
}

void DLGpicwin::OnButtonPicwin11() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(10);
}

void DLGpicwin::OnButtonPicwin12() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(11);
}

void DLGpicwin::OnButtonPicwin13() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(12);
}

void DLGpicwin::OnButtonPicwin14() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(13);
}

void DLGpicwin::OnButtonPicwin15() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(14);
}

void DLGpicwin::OnButtonPicwin16() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(15);
}

void DLGpicwin::OnButtonPicwin17() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(16);
}

void DLGpicwin::OnButtonPicwin18() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(17);
}

void DLGpicwin::OnButtonPicwin19() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(18);
}

void DLGpicwin::OnButtonPicwin20() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(19);
}

void DLGpicwin::OnButtonPicwin21() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(20);
}

void DLGpicwin::OnButtonPicwin22() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(21);
}

void DLGpicwin::OnButtonPicwin23() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(22);
}

void DLGpicwin::OnButtonPicwin24() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(23);
}

void DLGpicwin::OnButtonPicwin25() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(24);
}

void DLGpicwin::OnButtonPicwin26() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(25);
}

void DLGpicwin::OnButtonPicwin27() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(26);
}

void DLGpicwin::OnButtonPicwin28() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(27);
}

void DLGpicwin::OnButtonPicwin29() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(28);
}

void DLGpicwin::OnButtonPicwin30() 
{
	// TODO: Add your control notification handler code here
	PicButtonClick(29);
}

