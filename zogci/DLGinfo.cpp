// DLGinfo.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGinfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGinfo dialog


CDLGinfo::CDLGinfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGinfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGinfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGinfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGinfo, CDialog)
	//{{AFX_MSG_MAP(CDLGinfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGinfo message handlers

BOOL CDLGinfo::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);


	return TRUE;  // return TRUE  unless you set the focus to a control
}
