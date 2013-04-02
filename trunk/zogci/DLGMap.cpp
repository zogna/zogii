// DLGMap.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGMap.h"

#include "map.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern char LanguageFlag;

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
	dstImage=NULL;
	MapTotal=0;

}

CDLGMap::~CDLGMap()
{
	cvReleaseImage(&srcImage);
	srcImage=NULL;

	cvReleaseImage(&dstImage);
	dstImage=NULL;
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
	ON_NOTIFY (UDM_TOOLTIP_DISPLAY, NULL, NotifyDisplayTooltip)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGMap message handlers

BOOL CDLGMap::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	//����ԭʼͼƬ
	if(srcImage)
	{
		cvReleaseImage(&srcImage);
		srcImage=NULL;
	}
	srcImage = cvLoadImage(MapPath, CV_LOAD_IMAGE_UNCHANGED);
	if(NULL==srcImage)
		MessageBox("miss map.bmp file");

	if(dstImage)
	{
		cvReleaseImage(&dstImage);
		dstImage=NULL;
	}
	dstImage=cvCloneImage(srcImage);
	if(NULL==dstImage)
	{
		MessageBox("CDLGMap::OnInitDialog error");
		return TRUE;
	}

	
	Load(10,(unsigned char*)"0123456789");

	InitToolTip();

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

	ReSizeShowImage(dstImage);
}

//������С��ת����BMP����ʾ
void CDLGMap::Load(int total,unsigned char *imap)
{
	if(dstImage)
	{
		cvReleaseImage(&dstImage);
		dstImage=NULL;
	}
	dstImage=cvCloneImage(srcImage);
	if(NULL==dstImage)
	{
		MessageBox("CDLGMap::Load error");
		return ;
	}

	MapTotal=0;

	int i,j;
	for(i=0;i<total;i++)
	{
		j=imap[i];
		if(j >=0 && j < DiscoverMapTotal)
		{
			switch(DiscoverMap[j].flag)
			{
			case MAP_CONTINENT:
				cvCircle(dstImage,cvPoint(DiscoverMap[j].x,DiscoverMap[j].y),10,CV_RGB(255, 0, 255 ),-1);

				MapData[MapTotal]=j;
				MapTotal++;
				break;
			case  MAP_COUNTRY:
				cvCircle(dstImage,cvPoint(DiscoverMap[j].x,DiscoverMap[j].y),6,CV_RGB(127, 255,64),-1);
			
				MapData[MapTotal]=j;
				MapTotal++;
				break;
			case MAP_CITY:
				cvCircle(dstImage,cvPoint(DiscoverMap[j].x,DiscoverMap[j].y),4,CV_RGB(255, 127,0),-1);

				MapData[MapTotal]=j;
				MapTotal++;
				break;
			default:
				break;
			}
		}
	}

	//�ػ�
	ReSizeShowImage(dstImage);
}


//������С��ת����BMP����ʾ
void CDLGMap::ReSizeShowImage(IplImage *pImage)
{
	CRect rect;
	m_map.GetClientRect(&rect);

	//����Ӧ��С
	float ratew=(float)rect.Width()/(float)pImage->width;
	float rateh=(float)rect.Height()/(float)pImage->height;
	float rate=ratew < rateh? ratew:rateh;

	int dstw=(int)(pImage->width*rate);
	int dsth=(int)(pImage->height*rate);

	//̫С����
	if(dstw<=10 || dsth<=10)
		return ;

	//������С
	miniImage = cvCreateImage( cvSize(dstw,dsth), IPL_DEPTH_8U, 3 );
	cvResize(pImage,miniImage);
	//ת��
	HBITMAP	hbitmap ;
	IplImage2Bmp(miniImage,hbitmap);
	//��ʾ
	m_map.SetBitmap(hbitmap);
	//�ͷ�
	cvReleaseImage(&miniImage); 
	miniImage=NULL;

	//���� ��̬ͼƬ�ؼ���С
	rect.top+=(rect.Height()-dsth)/2;
	rect.bottom=rect.top+dsth;
	rect.right=rect.left+dstw;
	m_map.MoveWindow(&rect);

	//��ֵ
	MapRect.top=rect.top;
	MapRect.bottom=rect.bottom;
	MapRect.left=rect.left;
	MapRect.right=rect.right;
	MapRect.rate=rate;
	MapRect.width=dstw;
	MapRect.height=dsth;
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
/*
	RECT	m_rect [4]=
	{
		{0, 200, 100, 300},
		{100, 200, 200, 300},
		{0, 300, 100, 400},
		{100, 300, 200, 400},
	};
	
	dc.FillSolidRect(&(m_rect [0]), RGB(255, 0, 0));
	dc.FillSolidRect(&(m_rect [1]), RGB(0, 255, 0));
	dc.FillSolidRect(&(m_rect [2]), RGB(0, 0, 255));
	dc.FillSolidRect(&(m_rect [3]), RGB(0, 255, 255));
*/	

	// TODO: Add your message handler code here
	/*
	// Do not call CDialog::OnPaint() for painting messages
	//������ͼ	
	CRect    rect;     
	GetClientRect(&rect);     
	
	//����Դ������λͼ     
	CBitmap    bitmap;     
	bitmap.LoadBitmap(IDB_BITMAP_MAP);    
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	
	CDC    memdc;     
	memdc.CreateCompatibleDC(&dc);     
	memdc.SelectObject(bitmap); 
	dc.SetStretchBltMode(COLORONCOLOR);
	//����Ӧ��С
	float ratew=(float)rect.Width()/(float)bmp.bmWidth;
	float rateh=(float)rect.Height()/(float)bmp.bmHeight;
	float rate=ratew < rateh? ratew:rateh;

//	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	dc.StretchBlt(0,(rect.Height()-bmp.bmHeight*rate)/2,bmp.bmWidth*rate,bmp.bmHeight*rate,
		&memdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);

	memdc.DeleteDC();
	*/
}
void CDLGMap::InitToolTip(void)
{
	/*SetEffectBk();
	  SOLID =0
	  HGRADIENT=1
	  VGRADIENT=2
	  HCGRADIENT=3
	  HVGRADIENT=4
	  3HGRADIENT=5
	  3VGRADIENT=6
	  NOISE =����Ч=7
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
	m_tooltip.SetNotify();//����Ҫ�����

	m_tooltip.SetBehaviour(PPTOOLTIP_MULTIPLE_SHOW);
	m_tooltip.SetColorBk(RGB(255, 255, 255), RGB(242, 246, 251), RGB(202, 218, 239));
	//m_tooltip.SetCallbackHyperlink(this->GetSafeHwnd(), UNM_HYPERLINK_CLICKED);
	m_tooltip.SetEffectBk(15,10);
	m_tooltip.SetDirection(PPTOOLTIP_LEFTEDGE_VCENTER);
	//�ر���Ӱ
	m_tooltip.SetTooltipShadow(0, 0, 0, 0, 0, 0);
	//����͸����
	m_tooltip.SetTransparency(10);

	m_tooltip.AddTool(GetDlgItem(IDC_STATIC_MAP), "");
}

BOOL CDLGMap::PreTranslateMessage(MSG* pMsg) 
{
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

void CDLGMap::NotifyDisplayTooltip(NMHDR * pNMHDR, LRESULT * result)
{
	*result = 0;
	NM_PPTOOLTIP_DISPLAY * pNotify = (NM_PPTOOLTIP_DISPLAY*)pNMHDR;

	if (pNotify->hwndTool==	(GetDlgItem(IDC_STATIC_MAP)->m_hWnd))
	{
		CPoint pt = *pNotify->pt;
		//ӳ�䵽�������
		GetDlgItem(IDC_STATIC_MAP)->ScreenToClient(&pt);

		int i,j;
		for (i = 0; i < MapTotal; i++)
		{
			j=MapData[i];

			if(pt.x>=(DiscoverMap[j].x*MapRect.rate-4) 
				&& pt.x<=(DiscoverMap[j].x*MapRect.rate+4)
				&& 	pt.y>=(DiscoverMap[j].y*MapRect.rate-4)
				&& 	pt.y<=(DiscoverMap[j].y*MapRect.rate+4)
				)
			{
			//	CString str;
			//	str.Format(_T("Map x=%d, y=%d,mx=%f,my=%f"),
			//		pt.x, pt.y,DiscoverMap[j].x*MapRect.rate,DiscoverMap[j].y*MapRect.rate);
			//	pNotify->ti->sTooltip = str + _T("<br><hr color=green><br><font color=green>City was found</font>");
				switch(LanguageFlag)
				{
				case 1:		
					pNotify->ti->sTooltip.Format("<font color=navy><b>%s</b></font>",DiscoverMap[j].cn);
					break;
				case 2:		
					pNotify->ti->sTooltip.Format("<font color=navy><b>%s</b></font>",DiscoverMap[j].tw);
					break;
				default: 	
					pNotify->ti->sTooltip.Format("<font color=navy><b>%s</b></font>",DiscoverMap[j].en);
					break;
				}
				return;
			}
		}
	} //if
} //End NotifyDisplayTooltip