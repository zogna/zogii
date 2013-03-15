// DLGMark.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGMark.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGMark dialog


CDLGMark::CDLGMark(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGMark::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGMark)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGMark::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGMark)
	DDX_Control(pDX, IDC_COMBO_COLOR, m_crColour);
	//}}AFX_DATA_MAP
	DDX_ColourPickerCB( pDX, IDC_COMBO_COLOR, m_Colour );
}


BEGIN_MESSAGE_MAP(CDLGMark, CDialog)
	//{{AFX_MSG_MAP(CDLGMark)
	ON_BN_CLICKED(IDC_BUTTON_MARK, OnButtonMark)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGMark message handlers
BOOL CDLGMark::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGMark::OnButtonMark() 
{
	// TODO: Add your control notification handler code here
		UpdateData();

	CString strText;
	strText.Format( "Colour = RGB( 0x%X, 0x%X, 0x%X )",
		GetRValue( m_Colour ), GetGValue( m_Colour ), GetBValue( m_Colour ) );

	AfxMessageBox( strText );
	
}
