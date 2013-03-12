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

/////////////////////////////////////////////////////////////////////////////
// CDLGpicture dialog


CDLGpicture::CDLGpicture(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGpicture::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGpicture)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGpicture::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGpicture)
		// NOTE: the ClassWizard will add DDX and DDV calls here
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
	CRect pic_Rect;
	pic_Rect.top = rc.top+5/* + 5*/;
	pic_Rect.bottom = rc.bottom-30/* - 10*/;
	pic_Rect.left = rc.left+3/* + 10*/;
	pic_Rect.right = rc.right-3;
	GetDlgItem(IDC_PICWIN)->MoveWindow(pic_Rect);

	CRect txt_Rect;
	txt_Rect.top = 	pic_Rect.bottom+5/* + 5*/;
	txt_Rect.bottom = rc.bottom/* - 10*/;
	txt_Rect.left = rc.left+3/* + 10*/;
	txt_Rect.right = rc.right-3;
	GetDlgItem(IDC_TXTWIN)->MoveWindow(txt_Rect);
}



void CDLGpicture::OnTxtwin() 
{
	// TODO: Add your control notification handler code here
	
}
