// DLGInfoTxt.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGInfoTxt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGInfoTxt dialog


CDLGInfoTxt::CDLGInfoTxt(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGInfoTxt::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGInfoTxt)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGInfoTxt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGInfoTxt)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGInfoTxt, CDialog)
	//{{AFX_MSG_MAP(CDLGInfoTxt)
	ON_BN_CLICKED(IDC_BUTTON_Previous, OnBUTTONPrevious)
	ON_BN_CLICKED(IDC_BUTTON_First, OnBUTTONFirst)
	ON_BN_CLICKED(IDC_BUTTON_Next, OnBUTTONNext)
	ON_BN_CLICKED(IDC_BUTTON_Last, OnBUTTONLast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGInfoTxt message handlers

BOOL CDLGInfoTxt::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	AutoSize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGInfoTxt::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);
}

void CDLGInfoTxt::OnBUTTONPrevious() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfoTxt::OnBUTTONFirst() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfoTxt::OnBUTTONNext() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfoTxt::OnBUTTONLast() 
{
	// TODO: Add your control notification handler code here
	
}
