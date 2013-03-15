// DLGinfo.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGinfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGinfo dialog


CDLGinfo::CDLGinfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGinfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGinfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGinfo)
	DDX_Control(pDX, IDC_TAB_INFO, m_tabinfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGinfo, CDialog)
	//{{AFX_MSG_MAP(CDLGinfo)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_INFO, OnSelchangeTabInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGinfo message handlers

BOOL CDLGinfo::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	DlgMark.Create(IDD_MARK,this);
	DlgMark.ShowWindow(SW_SHOW);

	TabInfoInit();

	AutoSize();


	SFTextFont.CreatePointFont(160,_T("����"));
	GetDlgItem(IDC_STATIC_SF)->SetFont(&SFTextFont,true);
	//�ı���ʾ
	GetDlgItem(IDC_STATIC_SF)->SetWindowText("Microweisepqae(Sticholotidinae)");

	GETextFont.CreatePointFont(140,_T("����"));
	GetDlgItem(IDC_STATIC_GE)->SetFont(&GETextFont,true);
	//�ı���ʾ
	GetDlgItem(IDC_STATIC_GE)->SetWindowText("Microweiseinaap(Sticholotidinae)");

	SPTextFont.CreatePointFont(150,_T("����"));
	GetDlgItem(IDC_STATIC_SP)->SetFont(&SPTextFont,true);
	//�ı���ʾ
	GetDlgItem(IDC_STATIC_SP)->SetWindowText("Microweipqnae(Sticholotidinae)");

	SSPTextFont.CreatePointFont(100,_T("����"));
	GetDlgItem(IDC_STATIC_SSP)->SetFont(&SSPTextFont,true);
	//�ı���ʾ
	GetDlgItem(IDC_STATIC_SSP)->SetWindowText("Micrpqseinae(Sticholotidinae)");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGinfo::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	//�л���
	CRect tab_Rect;
	tab_Rect.top = rc.top+70/* + 5*/;
	tab_Rect.bottom = rc.bottom-25/* - 10*/;
	tab_Rect.left = rc.left/* + 10*/;
	tab_Rect.right = rc.right-5;
	//���� ��ʽ=�ص����߿�=������С
	GetDlgItem(IDC_TAB_INFO)->MoveWindow(tab_Rect);

	//��ǲ˵�
	CRect mark_Rect;
	mark_Rect.top = rc.top-30/* + 5*/;
	mark_Rect.bottom = mark_Rect.top+80/* - 10*/;
	mark_Rect.left =rc.right-90 /* + 10*/;
	mark_Rect.right = rc.right;
	//���� ��ʽ=�ص����߿�=������С
	DlgMark.MoveWindow(mark_Rect);

//	DlgInfoTxt.AutoSize();
//	DlgInfoMap.AutoSize();

	DlgInfoAdult.AutoSize();
	DlgInfoLarva.AutoSize();
	DlgInfoPupa.AutoSize();
	DlgInfoOvum.AutoSize();
	DlgInfoOther.AutoSize();

	Invalidate();
}

//��ʼ���л���
void CDLGinfo::TabInfoInit(void)
{
	m_tabinfo.InsertItem(0,Language_ConvertString("Document"));
	m_tabinfo.InsertItem(1,Language_ConvertString("Map"));
	m_tabinfo.InsertItem(2,Language_ConvertString("Adult Picture"));
	m_tabinfo.InsertItem(3,Language_ConvertString("Larva Picture"));
	m_tabinfo.InsertItem(4,Language_ConvertString("Pupa Picture"));
	m_tabinfo.InsertItem(5,Language_ConvertString("Ovum Picture"));
	m_tabinfo.InsertItem(6,Language_ConvertString("Other Picture"));

	DlgInfoTxt.Create(IDD_INFO_TXT,&m_tabinfo);
	DlgInfoMap.Create(IDD_MAP,&m_tabinfo);
	DlgInfoAdult.Create(IDD_RESULT,&m_tabinfo);
	DlgInfoLarva.Create(IDD_RESULT,&m_tabinfo);
	DlgInfoPupa.Create(IDD_RESULT,&m_tabinfo);
	DlgInfoOvum.Create(IDD_RESULT,&m_tabinfo);
	DlgInfoOther.Create(IDD_RESULT,&m_tabinfo);
}

//�л� �л���
void CDLGinfo::OnSelchangeTabInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	int i=m_tabinfo.GetCurSel();

	switch(i)
	{
	case 0:
		DlgInfoTxt.ShowWindow(SW_SHOW);
		DlgInfoMap.ShowWindow(SW_HIDE);
		DlgInfoAdult.ShowWindow(SW_HIDE);
		DlgInfoLarva.ShowWindow(SW_HIDE);
		DlgInfoPupa.ShowWindow(SW_HIDE);
		DlgInfoOvum.ShowWindow(SW_HIDE);
		DlgInfoOther.ShowWindow(SW_HIDE);
		break;
	case 1:
		DlgInfoTxt.ShowWindow(SW_HIDE);
		DlgInfoMap.ShowWindow(SW_SHOW);
		DlgInfoAdult.ShowWindow(SW_HIDE);
		DlgInfoLarva.ShowWindow(SW_HIDE);
		DlgInfoPupa.ShowWindow(SW_HIDE);
		DlgInfoOvum.ShowWindow(SW_HIDE);
		DlgInfoOther.ShowWindow(SW_HIDE);
		break;
	case 2:
		DlgInfoTxt.ShowWindow(SW_HIDE);
		DlgInfoMap.ShowWindow(SW_HIDE);
		DlgInfoAdult.ShowWindow(SW_SHOW);
		DlgInfoLarva.ShowWindow(SW_HIDE);
		DlgInfoPupa.ShowWindow(SW_HIDE);
		DlgInfoOvum.ShowWindow(SW_HIDE);
		DlgInfoOther.ShowWindow(SW_HIDE);
		break;
	case 3:
		DlgInfoTxt.ShowWindow(SW_HIDE);
		DlgInfoMap.ShowWindow(SW_HIDE);
		DlgInfoAdult.ShowWindow(SW_HIDE);
		DlgInfoLarva.ShowWindow(SW_SHOW);
		DlgInfoPupa.ShowWindow(SW_HIDE);
		DlgInfoOvum.ShowWindow(SW_HIDE);
		DlgInfoOther.ShowWindow(SW_HIDE);
		break;
	case 4:
		DlgInfoTxt.ShowWindow(SW_HIDE);
		DlgInfoMap.ShowWindow(SW_HIDE);
		DlgInfoAdult.ShowWindow(SW_HIDE);
		DlgInfoLarva.ShowWindow(SW_HIDE);
		DlgInfoPupa.ShowWindow(SW_SHOW);
		DlgInfoOvum.ShowWindow(SW_HIDE);
		DlgInfoOther.ShowWindow(SW_HIDE);
		break;
	case 5:
		DlgInfoTxt.ShowWindow(SW_HIDE);
		DlgInfoMap.ShowWindow(SW_HIDE);
		DlgInfoAdult.ShowWindow(SW_HIDE);
		DlgInfoLarva.ShowWindow(SW_HIDE);
		DlgInfoPupa.ShowWindow(SW_HIDE);
		DlgInfoOvum.ShowWindow(SW_SHOW);
		DlgInfoOther.ShowWindow(SW_HIDE);
		break;
	case 6:
		DlgInfoTxt.ShowWindow(SW_HIDE);
		DlgInfoMap.ShowWindow(SW_HIDE);
		DlgInfoAdult.ShowWindow(SW_HIDE);
		DlgInfoLarva.ShowWindow(SW_HIDE);
		DlgInfoPupa.ShowWindow(SW_HIDE);
		DlgInfoOvum.ShowWindow(SW_HIDE);
		DlgInfoOther.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}

}
