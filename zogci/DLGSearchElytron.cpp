// DLGSearchElytron.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGSearchElytron.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGSearchElytron dialog


CDLGSearchElytron::CDLGSearchElytron(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGSearchElytron::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGSearchElytron)
	m_colornum_1 = FALSE;
	m_colornum_2 = FALSE;
	m_colornum_3 = FALSE;
	m_colornum_4 = FALSE;
	m_colornum_any = FALSE;
	m_colornum_m4 = FALSE;
	m_spot_1316 = FALSE;
	m_spot_14 = FALSE;
	m_spot_1720 = FALSE;
	m_spot_58 = FALSE;
	m_spot_912 = FALSE;
	m_spot_any = FALSE;
	m_spot_m20 = FALSE;
	m_striped_1 = FALSE;
	m_striped_1012 = FALSE;
	m_striped_23 = FALSE;
	m_striped_46 = FALSE;
	m_striped_79 = FALSE;
	m_striped_any = FALSE;
	m_striped_m12 = FALSE;
	m_elytron_other = FALSE;
	m_elytron_any = FALSE;
	//}}AFX_DATA_INIT
}


void CDLGSearchElytron::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGSearchElytron)
	DDX_Control(pDX, IDC_CHECK_ELYTRON_STRIPED, m_elytron_striped);
	DDX_Control(pDX, IDC_CHECK_ELYTRON_SPOTS, m_elytron_spots);
	DDX_Control(pDX, IDC_CHECK_ELYTRON_SOLID, m_elytron_solid);
	DDX_Control(pDX, IDC_CHECK_ELYTRON_EYE, m_elytron_eye);
	DDX_Control(pDX, IDC_CHECK_ELYTRON_CIRCLE, m_elytron_circle);
	DDX_Control(pDX, IDC_CHECK_ELYTRON_BANDED, m_elytron_banded);
	DDX_Check(pDX, IDC_CHECK_COLOR_NUM_1, m_colornum_1);
	DDX_Check(pDX, IDC_CHECK_COLOR_NUM_2, m_colornum_2);
	DDX_Check(pDX, IDC_CHECK_COLOR_NUM_3, m_colornum_3);
	DDX_Check(pDX, IDC_CHECK_COLOR_NUM_4, m_colornum_4);
	DDX_Check(pDX, IDC_CHECK_COLOR_NUM_ANY, m_colornum_any);
	DDX_Check(pDX, IDC_CHECK_COLOR_NUM_M4, m_colornum_m4);
	DDX_Check(pDX, IDC_CHECK_SPOT_1316, m_spot_1316);
	DDX_Check(pDX, IDC_CHECK_SPOT_14, m_spot_14);
	DDX_Check(pDX, IDC_CHECK_SPOT_1720, m_spot_1720);
	DDX_Check(pDX, IDC_CHECK_SPOT_58, m_spot_58);
	DDX_Check(pDX, IDC_CHECK_SPOT_912, m_spot_912);
	DDX_Check(pDX, IDC_CHECK_SPOT_ANY, m_spot_any);
	DDX_Check(pDX, IDC_CHECK_SPOT_M20, m_spot_m20);
	DDX_Check(pDX, IDC_CHECK_STRIPED_1, m_striped_1);
	DDX_Check(pDX, IDC_CHECK_STRIPED_1012, m_striped_1012);
	DDX_Check(pDX, IDC_CHECK_STRIPED_23, m_striped_23);
	DDX_Check(pDX, IDC_CHECK_STRIPED_46, m_striped_46);
	DDX_Check(pDX, IDC_CHECK_STRIPED_79, m_striped_79);
	DDX_Check(pDX, IDC_CHECK_STRIPED_ANY, m_striped_any);
	DDX_Check(pDX, IDC_CHECK_STRIPED_M12, m_striped_m12);
	DDX_Check(pDX, IDC_CHECK_ELYTRON_OTHER, m_elytron_other);
	DDX_Check(pDX, IDC_CHECK_ELYTRON_ANY, m_elytron_any);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGSearchElytron, CDialog)
	//{{AFX_MSG_MAP(CDLGSearchElytron)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGSearchElytron message handlers
BOOL CDLGSearchElytron::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	HINSTANCE hi=AfxGetApp()->m_hInstance;
	HBITMAP hbitmap;
/////////////////////////////
	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_ELYTRON_BANDED));
	m_elytron_banded.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_ELYTRON_STRIPED));
	m_elytron_striped.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_ELYTRON_SPOTS));
	m_elytron_spots.SetBitmap(hbitmap);
	
	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_ELYTRON_SOLID));
	m_elytron_solid.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_ELYTRON_EYE));
	m_elytron_eye.SetBitmap(hbitmap);
	
	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_ELYTRON_CIRCLE));
	m_elytron_circle.SetBitmap(hbitmap);

	return TRUE;  // return TRUE  unless you set the focus to a control
}
