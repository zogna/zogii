// DLGABOUT.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGABOUT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGABOUT dialog


CDLGABOUT::CDLGABOUT(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGABOUT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGABOUT)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGABOUT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGABOUT)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGABOUT, CDialog)
	//{{AFX_MSG_MAP(CDLGABOUT)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGABOUT message handlers
