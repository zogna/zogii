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

	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);


	return TRUE;  // return TRUE  unless you set the focus to a control
}
