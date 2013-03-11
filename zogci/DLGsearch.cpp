// DLGsearch.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGsearch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGsearch dialog


CDLGsearch::CDLGsearch(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGsearch::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGsearch)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGsearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGsearch)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGsearch, CDialog)
	//{{AFX_MSG_MAP(CDLGsearch)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGsearch message handlers
BOOL CDLGsearch::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);


	return TRUE;  // return TRUE  unless you set the focus to a control
}
