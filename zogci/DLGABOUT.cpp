// DLGabout.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGabout.h"
#include "DLGannounce.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern char LanguageFlag;
/////////////////////////////////////////////////////////////////////////////
// CDLGabout dialog


CDLGabout::CDLGabout(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGabout::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGabout)
	m_Language = 0;

	//}}AFX_DATA_INIT
}


void CDLGabout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGabout)
	DDX_CBIndex(pDX, IDC_Language, m_Language);
	DDX_Control(pDX, IDC_ADDR, m_addr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGabout, CDialog)
	//{{AFX_MSG_MAP(CDLGabout)
	ON_BN_CLICKED(IDC_Announce, OnAnnounce)
	ON_BN_CLICKED(IDC_LanguageButton, OnLanguageButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGabout message handlers

BOOL CDLGabout::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	Authors();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CDLGabout::OnAnnounce() 
{
	// TODO: Add your control notification handler code here
	CDLGannounce DlgAnnounce;
	DlgAnnounce.DoModal();
}

void CDLGabout::Authors(void)
{
	char temp[260];

	GetDlgItem(IDC_ADDR)->SetWindowText("code.google.com/p/zogci");
	//Set the target URL 
	m_addr.SetLinkUrl("http://code.google.com/p/zogci/");
	//Enable showing the Tooltip
	m_addr.ActiveToolTip(1);
	//Set the Tooltiptext
	m_addr.SetTootTipText("Click Here to go zogci");

	m_addr.SetLinkColor(RGB(255, 0, 0));
	m_addr.SetHoverColor(RGB(0, 0, 255));
	m_addr.SetVisitedColor(RGB(0, 13, 0));

	switch(LanguageFlag)
	{
	case 1:
		GetDlgItem(IDC_Authors)->SetWindowText("代码和数据收集: zogna (Guan Quan)");	
		GetDlgItem(IDC_EMAIL)->SetWindowText("电子邮箱: zognaproject@gmail.com");
		GetDlgItem(IDC_WEBSITE)->SetWindowText("网站:");
		sprintf(temp,"软件版本: 1.0 构建:%s,%s",__DATE__,__TIME__);
		GetDlgItem(IDC_SOFTVER)->SetWindowText(temp);
		GetDlgItem(IDC_DATABASEVER)->SetWindowText("数据版本: 1.0");
		break;
	case 2:
		GetDlgItem(IDC_Authors)->SetWindowText("代碼和數據收集: zogna (Guan Quan)");	
		GetDlgItem(IDC_EMAIL)->SetWindowText("電子郵箱: zognaproject@gmail.com");
		GetDlgItem(IDC_WEBSITE)->SetWindowText("網站:");
		sprintf(temp,"軟件版本: 1.0 構建:%s,%s",__DATE__,__TIME__);
		GetDlgItem(IDC_SOFTVER)->SetWindowText(temp);
		GetDlgItem(IDC_DATABASEVER)->SetWindowText("數據版本: 1.0");	
		break;
	default:
		GetDlgItem(IDC_Authors)->SetWindowText("Code and Data collect: zogna (Guan Quan)");	
		GetDlgItem(IDC_EMAIL)->SetWindowText("E-Mail: zognaproject@gmail.com");
		GetDlgItem(IDC_WEBSITE)->SetWindowText("WebSite:");
		sprintf(temp,"Soft Version: 1.0 Bulid:%s,%s",__DATE__,__TIME__);
		GetDlgItem(IDC_SOFTVER)->SetWindowText(temp);
		GetDlgItem(IDC_DATABASEVER)->SetWindowText("Data Version: 1.0");
		break;
	}
}

void CDLGabout::OnLanguageButton() 
{
	UpdateData(TRUE);
	LanguageFlag=(char)m_Language;
	// TODO: Add your control notification handler code here
	Language_WriteUserInfo();

	
	//开启另一个程序
	WinExec("zogci.exe",SW_NORMAL);
	//关闭本程序
	AfxGetMainWnd()->SendMessage(WM_CLOSE);



}
