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

	Dlgpicwin.flag=FLAG_WIN_RESULT;
	Dlgpicwin.Create(IDD_PICWIN,this);
	Dlgpicwin.ShowWindow(SW_SHOW);

	//放在所有CREATE最后
	AutoSize();
	

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
	CRect picwin_Rect(rc);

	picwin_Rect.top = rc.top-15/* + 5*/;
	picwin_Rect.bottom = rc.bottom-25/* - 10*/;
	picwin_Rect.left = rc.left/* + 10*/;
	picwin_Rect.right = rc.right;

	Dlgpicwin.MoveWindow(picwin_Rect);
	Dlgpicwin.AutoSize();

	Invalidate();
}
