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
	m_adult_size_02 = FALSE;
	m_adult_size_10 = FALSE;
	m_adult_size_25 = FALSE;
	m_adult_size_58 = FALSE;
	m_adult_size_810 = FALSE;
	m_adult_size_any = FALSE;
	m_allname = FALSE;
	m_doc = FALSE;
	m_ge = FALSE;
	m_sf = FALSE;
	m_sp = FALSE;
	m_ssp = FALSE;
	m_txt = _T("");
	m_larva_all = FALSE;
	m_pupa_all = FALSE;
	m_contour_any = FALSE;
	//}}AFX_DATA_INIT
}


void CDLGsearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGsearch)
	DDX_Control(pDX, IDC_CHECK_CONTOUR_RACTANGLE, m_contour_ractangle);
	DDX_Control(pDX, IDC_CHECK_CONTOUR_ELLIPSE, m_contour_ellipse);
	DDX_Control(pDX, IDC_CHECK_CONTOUR_CIRCLE, m_contour_circle);
	DDX_Control(pDX, IDC_CHECK_PUPA_SOFTTHORN, m_pupa_softthorn);
	DDX_Control(pDX, IDC_CHECK_PUPA_NORMAL, m_pupa_normal);
	DDX_Control(pDX, IDC_CHECK_PUPA_HARDTHORN, m_pupa_hardthorn);
	DDX_Control(pDX, IDC_CHECK_PUPA_HAIR, m_pupa_hair);
	DDX_Control(pDX, IDC_CHECK_LARVA_ALLHAIR, m_larva_allhair);
	DDX_Check(pDX, IDC_CHECK_ADULT_SIZE_02, m_adult_size_02);
	DDX_Check(pDX, IDC_CHECK_ADULT_SIZE_10, m_adult_size_10);
	DDX_Check(pDX, IDC_CHECK_ADULT_SIZE_25, m_adult_size_25);
	DDX_Check(pDX, IDC_CHECK_ADULT_SIZE_58, m_adult_size_58);
	DDX_Check(pDX, IDC_CHECK_ADULT_SIZE_810, m_adult_size_810);
	DDX_Check(pDX, IDC_CHECK_ADULT_SIZE_ANY, m_adult_size_any);
	DDX_Check(pDX, IDC_CHECK_ALLNAME, m_allname);
	DDX_Check(pDX, IDC_CHECK_DOC, m_doc);
	DDX_Check(pDX, IDC_CHECK_GE, m_ge);
	DDX_Check(pDX, IDC_CHECK_SF, m_sf);
	DDX_Check(pDX, IDC_CHECK_SP, m_sp);
	DDX_Check(pDX, IDC_CHECK_SSP, m_ssp);
	DDX_Text(pDX, IDC_EDIT_TXT, m_txt);
	DDV_MaxChars(pDX, m_txt, 256);
	DDX_Check(pDX, IDC_CHECK_LARVA_ALL, m_larva_all);
	DDX_Control(pDX, IDC_CHECK_LARVA_BRANCH, m_larva_branch);
	DDX_Control(pDX, IDC_CHECK_LARVA_FLAT, m_larva_flat);
	DDX_Control(pDX, IDC_CHECK_LARVA_HALFHAIR, m_larva_halfhair);
	DDX_Control(pDX, IDC_CHECK_LARVA_NORMAL, m_larva_normal);
	DDX_Control(pDX, IDC_CHECK_LARVA_NULLHAIR, m_larva_nullhair);
	DDX_Control(pDX, IDC_CHECK_LARVA_THORN, m_larva_thorn);
	DDX_Check(pDX, IDC_CHECK_PUPA_ALL, m_pupa_all);
	DDX_Check(pDX, IDC_CHECK_CONTOUR_ANY, m_contour_any);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGsearch, CDialog)
	//{{AFX_MSG_MAP(CDLGsearch)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_ADULT, OnButtonAdult)
	ON_BN_CLICKED(IDC_BUTTON_LARVA, OnButtonLarva)
	ON_BN_CLICKED(IDC_BUTTON_PUPA, OnButtonPupa)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGsearch message handlers
BOOL CDLGsearch::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	HINSTANCE hi=AfxGetApp()->m_hInstance;
	HBITMAP hbitmap;
/////////////////////////////
	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_ALLHAIR));
	m_larva_allhair.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_BRANCH));
	m_larva_branch.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_FLAT));
	m_larva_flat.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_HALFHAIR));
	m_larva_halfhair.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_NORMAL));
	m_larva_normal.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_NULLHAIR));
	m_larva_nullhair.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_LARVA_THORN));
	m_larva_thorn.SetBitmap(hbitmap);
/////////////////////////////
	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_PUPA_SOFTTHORN));
	m_pupa_softthorn.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_PUPA_NORMAL));
	m_pupa_normal.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_PUPA_HARDTHORN));
	m_pupa_hardthorn.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_PUPA_HAIR));
	m_pupa_hair.SetBitmap(hbitmap);
/////////////////////////////
	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_CONTOUR_CIRCLE));
	m_contour_circle.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_CONTOUR_ELLIPSE));
	m_contour_ellipse.SetBitmap(hbitmap);

	hbitmap = (HBITMAP)LoadBitmap(hi,	MAKEINTRESOURCE(IDB_CONTOUT_RACTANGLE));
	m_contour_ractangle.SetBitmap(hbitmap);
/////////////////////////////


	AutoSize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGsearch::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	Invalidate();
}



void CDLGsearch::OnButtonReset() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGsearch::OnButtonAdult() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGsearch::OnButtonLarva() 
{
	// TODO: Add your control notification handler code here
	
}

void CDLGsearch::OnButtonPupa() 
{
	// TODO: Add your control notification handler code here
	
}
