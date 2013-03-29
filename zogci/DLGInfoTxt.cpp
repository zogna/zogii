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
	m_edit_txt = _T("");
	//}}AFX_DATA_INIT
}


void CDLGInfoTxt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGInfoTxt)
	DDX_Text(pDX, IDC_EDIT_TXT, m_edit_txt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGInfoTxt, CDialog)
	//{{AFX_MSG_MAP(CDLGInfoTxt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGInfoTxt message handlers

BOOL CDLGInfoTxt::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	//显示窗口
	DlgInfotxtInfo.Create(IDD_INFOTXT_INFO,this);
	DlgInfotxtInfo.ShowWindow(SW_SHOW);

	DlgInfotxtPannel.Create(IDD_INFOTXT_PANNEL,this);
	DlgInfotxtPannel.ShowWindow(SW_SHOW);

	AutoSize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGInfoTxt::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	//Pannel
	CRect pannel_Rect;
	pannel_Rect.top = rc.bottom-50;
	pannel_Rect.bottom = rc.bottom;
	pannel_Rect.left = rc.left+50;
	pannel_Rect.right = rc.right;
	//必须 样式=重叠，边框=调整大小
	DlgInfotxtPannel.MoveWindow(pannel_Rect);

	//txt
	CRect txtwin_Rect;

	txtwin_Rect.top = rc.top+175;
	txtwin_Rect.bottom = rc.bottom-55;
	txtwin_Rect.left = rc.left-5;
	txtwin_Rect.right = rc.right-5;

	GetDlgItem(IDC_EDIT_TXT)->MoveWindow(txtwin_Rect);

	Invalidate();

}
