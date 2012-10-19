// zogciDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "zogciDlg.h"
#include "DLGABOUT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/*
	CDC *aa=m_Picture.GetDC();
	CBitmap bitmap;

	tagRECT r;
	m_Picture.GetWindowRect(&r);
	int h=r.bottom-r.top;
	int w=r.right-r.left;

	HBITMAP hbitmap = (HBITMAP)LoadImage(
		NULL,				// handle of the instance that contains the image
	"haha.bmp",
		IMAGE_BITMAP,		// type of image-- can also be IMAGE_CURSOR or IMAGE_ICON 
		0,0,				// desired width and height
		LR_LOADFROMFILE);	// load flags-- with LR_LOADTRANSPARENT makes transparent to bkgrnd
 
	bitmap.Attach(hbitmap);

	CDC dcComp;
	dcComp.CreateCompatibleDC(aa);

	CBitmap *oldbmp=dcComp.SelectObject(&bitmap);
bitmap.CreateBitmap(1280,720,1,32,data);
aa->SetStretchBltMode(COLORONCOLOR);
	aa->StretchBlt(0,0,w,h, &dcComp, 0,0,1280,720,SRCCOPY);

	dcComp.SelectObject(oldbmp);
	dcComp.DeleteDC();
	m_Picture.ReleaseDC(aa);
*/
/////////////////////////////////////////////////////////////////////////////
// CZogciDlg dialog

CZogciDlg::CZogciDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZogciDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZogciDlg)
	m_Calthrop = -1;
	m_ColorA = -1;
	m_ColorB = -1;
	m_ColorC = -1;
	m_ColorD = -1;
	m_ColorNum = -1;
	m_SetLanguage = -1;
	m_Texture = -1;
	m_TypeSearch = -1;
	m_Villus = -1;
	m_DiscoverName = _T("");
	m_DiscoverSearch = _T("");
	m_FoodSearch = _T("");
	m_Name = _T("");
	m_PicturePath = _T("");
	m_FoodType = _T("");
	m_StartStrSearch = _T("");
	m_StrSearch = _T("");
	m_Text = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZogciDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZogciDlg)
	DDX_Control(pDX, IDC_LIST_SearchReport, m_SearchReport);
	DDX_Control(pDX, IDC_LIST_Picture, m_ListPicture);
	DDX_Control(pDX, IDC_LIST_OtherName, m_OtherName);
	DDX_Control(pDX, IDC_LIST_Food, m_Food);
	DDX_Control(pDX, IDC_STATIC_Picture, m_Picture);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_CBIndex(pDX, IDC_COMBO_Calthrop, m_Calthrop);
	DDX_CBIndex(pDX, IDC_COMBO_ColorA, m_ColorA);
	DDX_CBIndex(pDX, IDC_COMBO_ColorB, m_ColorB);
	DDX_CBIndex(pDX, IDC_COMBO_ColorC, m_ColorC);
	DDX_CBIndex(pDX, IDC_COMBO_ColorD, m_ColorD);
	DDX_CBIndex(pDX, IDC_COMBO_ColorNum, m_ColorNum);
	DDX_CBIndex(pDX, IDC_COMBO_SetLanguage, m_SetLanguage);
	DDX_CBIndex(pDX, IDC_COMBO_Texture, m_Texture);
	DDX_CBIndex(pDX, IDC_COMBO_TypeSearch, m_TypeSearch);
	DDX_CBIndex(pDX, IDC_COMBO_Villus, m_Villus);
	DDX_Text(pDX, IDC_EDIT_DiscoverName, m_DiscoverName);
	DDV_MaxChars(pDX, m_DiscoverName, 128);
	DDX_Text(pDX, IDC_EDIT_DiscoverSearch, m_DiscoverSearch);
	DDV_MaxChars(pDX, m_DiscoverSearch, 128);
	DDX_Text(pDX, IDC_EDIT_FoodSearch, m_FoodSearch);
	DDV_MaxChars(pDX, m_FoodSearch, 128);
	DDX_Text(pDX, IDC_EDIT_Name, m_Name);
	DDV_MaxChars(pDX, m_Name, 128);
	DDX_Text(pDX, IDC_EDIT_PicturePath, m_PicturePath);
	DDV_MaxChars(pDX, m_PicturePath, 260);
	DDX_Text(pDX, IDC_STATIC_FoodType, m_FoodType);
	DDV_MaxChars(pDX, m_FoodType, 128);
	DDX_Text(pDX, IDC_EDIT_StartStrSearch, m_StartStrSearch);
	DDV_MaxChars(pDX, m_StartStrSearch, 128);
	DDX_Text(pDX, IDC_EDIT_StrSearch, m_StrSearch);
	DDV_MaxChars(pDX, m_StrSearch, 128);
	DDX_Text(pDX, IDC_EDIT_Text, m_Text);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZogciDlg, CDialog)
	//{{AFX_MSG_MAP(CZogciDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_StartStrSearch, OnBUTTONStartStrSearch)
	ON_BN_CLICKED(IDC_BUTTON_StrSearch, OnBUTTONStrSearch)
	ON_BN_CLICKED(IDC_BUTTON_DiscoverSearch, OnBUTTONDiscoverSearch)
	ON_BN_CLICKED(IDC_BUTTON_FoodSearch, OnBUTTONFoodSearch)
	ON_BN_CLICKED(IDC_BUTTON_SeeAllPicture, OnBUTTONSeeAllPicture)
	ON_BN_CLICKED(IDC_BUTTON_SeeSrcPicture, OnBUTTONSeeSrcPicture)
	ON_NOTIFY(HDN_ITEMCLICK, IDC_LIST_Picture, OnItemclickLISTPicture)
	ON_NOTIFY(HDN_ITEMCLICK, IDC_LIST_SearchReport, OnItemclickLISTSearchReport)
	ON_BN_CLICKED(IDC_BUTTON_SeeSrcText, OnBUTTONSeeSrcText)
	ON_BN_CLICKED(IDC_BUTTON_Larva, OnBUTTONLarva)
	ON_BN_CLICKED(IDC_BUTTON_Imago, OnBUTTONImago)
	ON_BN_CLICKED(IDC_BUTTON_Ovum, OnBUTTONOvum)
	ON_BN_CLICKED(IDC_BUTTON_Pupa, OnBUTTONPupa)
	ON_BN_CLICKED(IDC_BUTTON_ChoosePath, OnBUTTONChoosePath)
	ON_CBN_CLOSEUP(IDC_COMBO_SetLanguage, OnCloseupCOMBOSetLanguage)
	ON_BN_CLICKED(IDC_BUTTON_SeeSearchPic, OnBUTTONSeeSearchPic)
	ON_BN_CLICKED(IDC_BUTTON_Help, OnBUTTONHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZogciDlg message handlers

BOOL CZogciDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//图像显示
	tagRECT r;
	m_Picture.GetWindowRect(&r);
	PictureH=r.bottom-r.top;
	PictureW=r.right-r.left;
	PictureCDC=m_Picture.GetDC();
	TempPictureCDC.CreateCompatibleDC(PictureCDC);
	//
	GetCurrentDirectory(ZOGII_PAT_MAX,CurrentDir);
	zogiiSetDirectory(CurrentDir);
	// TODO: Add extra initialization here
	zogiiReadDB(&DBtotal,DBdata,&DBPictotal,DBPicdata);

  	char str[250];
    sprintf(str,"zogci_db@zogna      Build:%s,%s     DataBaseVersion:%d    亚科%d属%d种%d亚种%d",	\
			__DATE__,__TIME__,zogiiVersionDB(),	\
			zogiiSFTotalDB(),zogiiGETotalDB(),zogiiNATotalDB(),zogiiSPTotalDB());
    SetWindowText(str);
	// TODO: Add extra initialization here
	
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

void CZogciDlg::OnButtonAbout() 
{
	// TODO: Add your control notification handler code here
	CDLGABOUT dlgAbout;
	dlgAbout.DoModal();
}

void CZogciDlg::OnBUTTONStartStrSearch() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONStrSearch() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONDiscoverSearch() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONFoodSearch() 
{
	// TODO: Add your control notification handler code here
	
}


void CZogciDlg::OnBUTTONSeeAllPicture() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONSeeSrcPicture() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnItemclickLISTPicture(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CZogciDlg::OnItemclickLISTSearchReport(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CZogciDlg::OnBUTTONSeeSrcText() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONLarva() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONImago() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONOvum() 
{
	
}

void CZogciDlg::OnBUTTONPupa() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONChoosePath() 
{
	// TODO: Add your control notification handler code here
	
}


void CZogciDlg::OnCloseupCOMBOSetLanguage() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONSeeSearchPic() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogciDlg::OnBUTTONHelp() 
{
	// TODO: Add your control notification handler code here
	
}
