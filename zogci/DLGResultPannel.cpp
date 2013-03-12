// DLGResultPannel.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGResultPannel.h"

#include "DLGresult.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern CDLGresult	DlgResult;
/////////////////////////////////////////////////////////////////////////////
// CDLGResultPannel dialog


CDLGResultPannel::CDLGResultPannel(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGResultPannel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGResultPannel)
	m_split = 0;
	//}}AFX_DATA_INIT
}


void CDLGResultPannel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGResultPannel)
	DDX_CBIndex(pDX, IDC_COMBO, m_split);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGResultPannel, CDialog)
	//{{AFX_MSG_MAP(CDLGResultPannel)
	ON_BN_CLICKED(IDC_BUTTON_First, OnBUTTONFirst)
	ON_BN_CLICKED(IDC_BUTTON_Previous, OnBUTTONPrevious)
	ON_BN_CLICKED(IDC_BUTTON_Next, OnBUTTONNext)
	ON_BN_CLICKED(IDC_BUTTON_Last, OnBUTTONLast)
	ON_BN_CLICKED(IDC_BUTTON_Jump, OnBUTTONJump)
	ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGResultPannel message handlers

BOOL CDLGResultPannel::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGResultPannel::OnBUTTONFirst() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGResultPannel::OnBUTTONPrevious() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGResultPannel::OnBUTTONNext() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGResultPannel::OnBUTTONLast() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGResultPannel::OnBUTTONJump() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGResultPannel::OnSelchangeCombo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	switch(m_split)
	{
	case 	0:	DlgResult.CurrentPicWinMax=MIN_PICTURE_WIN;break;	
	case 	1:	DlgResult.CurrentPicWinMax=MID_PICTURE_WIN;break;	
	case 	2:	DlgResult.CurrentPicWinMax=MAX_PICTURE_WIN;break;	
	default:break;
	}
	DlgResult.AutoSize();
}
