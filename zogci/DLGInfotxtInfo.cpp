// DLGInfotxtInfo.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGInfotxtInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGInfotxtInfo dialog


CDLGInfotxtInfo::CDLGInfotxtInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGInfotxtInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGInfotxtInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGInfotxtInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGInfotxtInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGInfotxtInfo, CDialog)
	//{{AFX_MSG_MAP(CDLGInfotxtInfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGInfotxtInfo message handlers
BOOL CDLGInfotxtInfo::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}
