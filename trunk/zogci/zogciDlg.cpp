// zogciDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "zogciDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZogciDlg dialog


CZogciDlg::CZogciDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZogciDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZogciDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CZogciDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZogciDlg)
	DDX_Control(pDX, IDC_TREE, m_Tree);
	DDX_Control(pDX, IDC_TAB_MAIN, m_TabMain);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZogciDlg, CDialog)
	//{{AFX_MSG_MAP(CZogciDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnSelchangeTabMain)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZogciDlg message handlers

BOOL CZogciDlg::OnInitDialog()
{
	Set_AllPath();
	Language_ReadUserInfo();

	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	TabMainInit();
	OnSelchangeTabMain(NULL,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZogciDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZogciDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CZogciDlg::OnOK()
{
	// TODO: Add your control notification handler code here
}
//窗口改变时的处理
void CZogciDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	//窗口最小化与窗口大小无变化不处理
	if ((cx ==0 && cy == 0) || 
		(cx == m_clientRect.Width() && cy == m_clientRect.Height())) 
	{
		return;
	}
	else
	{
		UpdatePannelPosition();
		Invalidate();
	}
}

void CZogciDlg::UpdatePannelPosition()
{
	GetClientRect(&m_clientRect);
	//树宽度
	int tree_width=200;
	//窗体边距
	int distance=5;
	//树
	CRect tree_Rect;
	tree_Rect.top = m_clientRect.top+distance/* + 5*/;
	tree_Rect.bottom = m_clientRect.bottom-distance/* - 10*/;
	tree_Rect.left = m_clientRect.left+distance/* + 10*/;
	tree_Rect.right = m_clientRect.left+tree_width+distance;
	//必须 样式=重叠，边框=调整大小
	GetDlgItem(IDC_TREE)->MoveWindow(tree_Rect);

	//切换栏
	CRect tab_Rect;
	tab_Rect.top = m_clientRect.top+distance/* + 5*/;
	tab_Rect.bottom = m_clientRect.bottom-distance/* - 10*/;
	tab_Rect.left = m_clientRect.left+tree_Rect.right+distance/* + 10*/;
	tab_Rect.right = m_clientRect.right-distance;
	//必须 样式=重叠，边框=调整大小
	GetDlgItem(IDC_TAB_MAIN)->MoveWindow(tab_Rect);

	DlgLink.AutoSize();
	DlgAbout.AutoSize();
	DlgInfo.AutoSize();
	DlgResult.AutoSize();
	DlgSearch.AutoSize();
}

//初始化切换栏
void CZogciDlg::TabMainInit(void)
{
	m_TabMain.InsertItem(0,Language_ConvertString("Rearch"));
	m_TabMain.InsertItem(1,Language_ConvertString("Result"));
	m_TabMain.InsertItem(2,Language_ConvertString("SpeciesInfo"));
	m_TabMain.InsertItem(3,Language_ConvertString("Link"));
	m_TabMain.InsertItem(4,Language_ConvertString("About"));
	
	DlgSearch.Create(IDD_SEARCH,&m_TabMain);
	DlgResult.Create(IDD_RESULT,&m_TabMain);
	DlgInfo.Create(IDD_INFO,&m_TabMain);
	DlgLink.Create(IDD_LINK,&m_TabMain);
	DlgAbout.Create(IDD_ABOUT,&m_TabMain);
}
//切换 切换栏
void CZogciDlg::OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	int i=m_TabMain.GetCurSel();

	switch(i)
	{
	case 0:
		DlgSearch.ShowWindow(SW_SHOW);
		DlgResult.ShowWindow(SW_HIDE);
		DlgInfo.ShowWindow(SW_HIDE);
		DlgLink.ShowWindow(SW_HIDE);
		DlgAbout.ShowWindow(SW_HIDE);
		break;
	case 1:
		DlgSearch.ShowWindow(SW_HIDE);
		DlgResult.ShowWindow(SW_SHOW);
		DlgInfo.ShowWindow(SW_HIDE);
		DlgLink.ShowWindow(SW_HIDE);
		DlgAbout.ShowWindow(SW_HIDE);
		break;
	case 2:
		DlgSearch.ShowWindow(SW_HIDE);
		DlgResult.ShowWindow(SW_HIDE);
		DlgInfo.ShowWindow(SW_SHOW);
		DlgLink.ShowWindow(SW_HIDE);
		DlgAbout.ShowWindow(SW_HIDE);
		break;
	case 3:
		DlgSearch.ShowWindow(SW_HIDE);
		DlgResult.ShowWindow(SW_HIDE);
		DlgInfo.ShowWindow(SW_HIDE);
		DlgLink.ShowWindow(SW_SHOW);
		DlgAbout.ShowWindow(SW_HIDE);
		break;
	case 4:
		DlgSearch.ShowWindow(SW_HIDE);
		DlgResult.ShowWindow(SW_HIDE);
		DlgInfo.ShowWindow(SW_HIDE);
		DlgLink.ShowWindow(SW_HIDE);
		DlgAbout.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
}
