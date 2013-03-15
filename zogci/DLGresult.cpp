// DLGresult.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGresult.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGresult dialog


CDLGresult::CDLGresult(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGresult::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGresult)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGresult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGresult)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGresult, CDialog)
	//{{AFX_MSG_MAP(CDLGresult)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGresult message handlers

BOOL CDLGresult::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	DlgResultPannel.Create(IDD_RESULT_PANNEL,this);
	DlgResultPannel.ShowWindow(SW_SHOW);
	CurrentPicWinMax=MIN_PICTURE_WIN;

	int i;
	for(i=0;i<MAX_PICTURE_WIN;i++)
		DlgPicture[i].Create(IDD_PICTURE,this);
	
	//放在所有CREATE最后
	AutoSize();
	



	DlgPicture[0].Load("1.JPG","ok\r\ndown");


	DlgPicture[1].Load("22.JPG","ok\r\nup");

//	DlgPicture[0].UnLoad();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
void CDLGresult::ReadImage(char *path,unsigned char **image,unsigned long int *size)
{
	FILE *fp;
	fp=fopen(path,"rb");
	if(NULL == fp)
		return ;
	(*size)=0;
	fseek(fp,0,SEEK_END);
	(*size) = ftell(fp);

	*image=(unsigned char *)calloc(*size,sizeof(unsigned char));
	fseek(fp,0,SEEK_SET);
	fread(*image,(*size)*sizeof(unsigned char),1,fp);
	fclose(fp);
}
void CDLGresult::CloseImage(unsigned char **image)
{
	free(*image);
}
*/

void CDLGresult::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	//Pannel
	CRect website_Rect;
	website_Rect.top = rc.bottom-70/* + 5*/;
	website_Rect.bottom = rc.bottom/* - 10*/;
	website_Rect.left = rc.left+50/* + 10*/;
	website_Rect.right = rc.right;
	//必须 样式=重叠，边框=调整大小
	DlgResultPannel.MoveWindow(website_Rect);
	//调整窗口
	AutoSizePictureWin(rc);
	Invalidate();
}

void CDLGresult::AutoSizePictureWin(CRect rc)
{
	CRect rect;
	int i;

	int w;
	int h;

	rc.top-=20;
	rc.bottom-=65;
	rc.left-=5;

	switch(CurrentPicWinMax)
	{
	case MAX_PICTURE_WIN	:w=6;h=5;break;	
	case MID_PICTURE_WIN	:w=5;h=4;break;	
	case MIN_PICTURE_WIN	:w=4;h=3;break;	
	default:MessageBox("CDLGresult::AutoSizePictureWin ERROR");return;
	}

	int width=(rc.right-rc.left)/w;
	int hight=(rc.bottom-rc.top)/h;

	for(i=0;i<CurrentPicWinMax;i++)
	{
		//Pannel
		rect.top = rc.top+i/w*hight /* + 5*/;
		rect.bottom = rc.top+(i/w+1)*hight/* - 10*/;
		rect.left = rc.left+i%w*width/* + 10*/;
		rect.right = rc.left+(i%w+1)*width;
		//必须 样式=重叠，边框=调整大小
		DlgPicture[i].MoveWindow(rect);

		DlgPicture[i].AutoSize();
		DlgPicture[i].ShowWindow(SW_SHOW);
	}

	for(NULL;i<MAX_PICTURE_WIN;i++)
		DlgPicture[i].ShowWindow(SW_HIDE);

}