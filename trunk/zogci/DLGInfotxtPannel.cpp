// DLGInfotxtPannel.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGInfotxtPannel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGInfotxtPannel dialog


CDLGInfotxtPannel::CDLGInfotxtPannel(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGInfotxtPannel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGInfotxtPannel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGInfotxtPannel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGInfotxtPannel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGInfotxtPannel, CDialog)
	//{{AFX_MSG_MAP(CDLGInfotxtPannel)
	ON_BN_CLICKED(IDC_BUTTON_First, OnBUTTONFirst)
	ON_BN_CLICKED(IDC_BUTTON_Previous, OnBUTTONPrevious)
	ON_BN_CLICKED(IDC_BUTTON_Next, OnBUTTONNext)
	ON_BN_CLICKED(IDC_BUTTON_Last, OnBUTTONLast)
	ON_BN_CLICKED(IDC_BUTTON_Jump, OnBUTTONJump)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGInfotxtPannel message handlers

BOOL CDLGInfotxtPannel::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGInfotxtPannel::OnBUTTONFirst() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfotxtPannel::OnBUTTONPrevious() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfotxtPannel::OnBUTTONNext() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfotxtPannel::OnBUTTONLast() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGInfotxtPannel::OnBUTTONJump() 
{
	// TODO: Add your control notification handler code here
	
}
