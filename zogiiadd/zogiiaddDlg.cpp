// zogiiaddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zogiiadd.h"
#include "zogiiaddDlg.h"
#include "zogiidb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZogiiaddDlg dialog

CZogiiaddDlg::CZogiiaddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZogiiaddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZogiiaddDlg)
	m_SubFamilyEN = _T("");
	m_SpNameTW = _T("");
	m_SpNameEN = _T("");
	m_SpNameCN = _T("");
	m_SubFamilyCN = _T("");
	m_SubFamilyTW = _T("");
	m_TextCNPath = _T("");
	m_TextENPath = _T("");
	m_TextTWPath = _T("");
	m_PupaPicPath = _T("");
	m_PupaPicInfo = _T("");
	m_OvumPicPath = _T("");
	m_OvumPicInfo = _T("");
	m_OtherNameA = _T("");
	m_OtherNameB = _T("");
	m_OtherNameC = _T("");
	m_OtherNameD = _T("");
	m_OtherNameE = _T("");
	m_OtherNameF = _T("");
	m_NameCN = _T("");
	m_NameEN = _T("");
	m_NameTW = _T("");
	m_LarvaPicPath = _T("");
	m_LarvaPicInfo = _T("");
	m_ImagoPicPath = _T("");
	m_ImagoPicInfo = _T("");
	m_Date = 0;
	m_Code = 0;
	m_GenusTW = _T("");
	m_GenusEN = _T("");
	m_GenusCN = _T("");
	m_FoodNameF = _T("");
	m_FoodNameE = _T("");
	m_FoodNameD = _T("");
	m_FoodNameC = _T("");
	m_FoodNameB = _T("");
	m_FoodNameA = _T("");
	m_DiscoveryPicPath = _T("");
	m_DiscoveryPicInfo = _T("");
	m_DiscoveryName = _T("");
	m_DataOutputPath = _T("");
	m_Food = -1;
	m_ImagoColorA = -1;
	m_ImagoColorB = -1;
	m_ImagoColorC = -1;
	m_ImagoColorD = -1;
	m_ImagoColorNum = -1;
	m_ImagoNo = -1;
	m_ImagoSex = -1;
	m_ImagoTexture = -1;
	m_ImagoVillus = -1;
	m_LarvaCalthrop = -1;
	m_LarvaColorA = -1;
	m_LarvaColorB = -1;
	m_LarvaColorC = -1;
	m_LarvaColorD = -1;
	m_LarvaColorNum = -1;
	m_LarvaInstar = -1;
	m_LarvaNo = -1;
	m_LarvaSex = -1;
	m_OvumColor = -1;
	m_OvumNo = -1;
	m_OvumSex = -1;
	m_PupaColorA = -1;
	m_PupaColorB = -1;
	m_PupaColorC = -1;
	m_PupaColorD = -1;
	m_PupaColorNum = -1;
	m_PupaNo = -1;
	m_PupaSex = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	DBtotal=0;
	DBdata=NULL;
}

void CZogiiaddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZogiiaddDlg)
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Text(pDX, IDC_EDIT_SubFamilyEN, m_SubFamilyEN);
	DDV_MaxChars(pDX, m_SubFamilyEN, 128);
	DDX_Text(pDX, IDC_EDIT_SpNameTW, m_SpNameTW);
	DDV_MaxChars(pDX, m_SpNameTW, 128);
	DDX_Text(pDX, IDC_EDIT_SpNameEN, m_SpNameEN);
	DDV_MaxChars(pDX, m_SpNameEN, 128);
	DDX_Text(pDX, IDC_EDIT_SpNameCN, m_SpNameCN);
	DDV_MaxChars(pDX, m_SpNameCN, 128);
	DDX_Text(pDX, IDC_EDIT_SubFamilyCN, m_SubFamilyCN);
	DDV_MaxChars(pDX, m_SubFamilyCN, 128);
	DDX_Text(pDX, IDC_EDIT_SubFamilyTW, m_SubFamilyTW);
	DDV_MaxChars(pDX, m_SubFamilyTW, 128);
	DDX_Text(pDX, IDC_EDIT_TextCNPath, m_TextCNPath);
	DDV_MaxChars(pDX, m_TextCNPath, 260);
	DDX_Text(pDX, IDC_EDIT_TextENPath, m_TextENPath);
	DDV_MaxChars(pDX, m_TextENPath, 260);
	DDX_Text(pDX, IDC_EDIT_TextTWPath, m_TextTWPath);
	DDV_MaxChars(pDX, m_TextTWPath, 260);
	DDX_Text(pDX, IDC_EDIT_PupaPicPath, m_PupaPicPath);
	DDV_MaxChars(pDX, m_PupaPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_PupaPicInfo, m_PupaPicInfo);
	DDV_MaxChars(pDX, m_PupaPicInfo, 128);
	DDX_Text(pDX, IDC_EDIT_OvumPicPath, m_OvumPicPath);
	DDV_MaxChars(pDX, m_OvumPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_OvumPicInfo, m_OvumPicInfo);
	DDV_MaxChars(pDX, m_OvumPicInfo, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameA, m_OtherNameA);
	DDV_MaxChars(pDX, m_OtherNameA, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameB, m_OtherNameB);
	DDV_MaxChars(pDX, m_OtherNameB, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameC, m_OtherNameC);
	DDV_MaxChars(pDX, m_OtherNameC, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameD, m_OtherNameD);
	DDV_MaxChars(pDX, m_OtherNameD, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameE, m_OtherNameE);
	DDV_MaxChars(pDX, m_OtherNameE, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameF, m_OtherNameF);
	DDV_MaxChars(pDX, m_OtherNameF, 128);
	DDX_Text(pDX, IDC_EDIT_NameCN, m_NameCN);
	DDV_MaxChars(pDX, m_NameCN, 128);
	DDX_Text(pDX, IDC_EDIT_NameEN, m_NameEN);
	DDV_MaxChars(pDX, m_NameEN, 128);
	DDX_Text(pDX, IDC_EDIT_NameTW, m_NameTW);
	DDV_MaxChars(pDX, m_NameTW, 128);
	DDX_Text(pDX, IDC_EDIT_LarvaPicPath, m_LarvaPicPath);
	DDV_MaxChars(pDX, m_LarvaPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_LarvaPicInfo, m_LarvaPicInfo);
	DDV_MaxChars(pDX, m_LarvaPicInfo, 128);
	DDX_Text(pDX, IDC_EDIT_ImagoPicPath, m_ImagoPicPath);
	DDV_MaxChars(pDX, m_ImagoPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_ImagoPicInfo, m_ImagoPicInfo);
	DDV_MaxChars(pDX, m_ImagoPicInfo, 128);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_Date, m_Date);
	DDX_Text(pDX, IDC_EDIT_Code, m_Code);
	DDV_MinMaxLong(pDX, m_Code, 0, 2147483647);
	DDX_Text(pDX, IDC_EDIT_GenusTW, m_GenusTW);
	DDV_MaxChars(pDX, m_GenusTW, 128);
	DDX_Text(pDX, IDC_EDIT_GenusEN, m_GenusEN);
	DDV_MaxChars(pDX, m_GenusEN, 128);
	DDX_Text(pDX, IDC_EDIT_GenusCN, m_GenusCN);
	DDV_MaxChars(pDX, m_GenusCN, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameF, m_FoodNameF);
	DDV_MaxChars(pDX, m_FoodNameF, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameE, m_FoodNameE);
	DDV_MaxChars(pDX, m_FoodNameE, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameD, m_FoodNameD);
	DDV_MaxChars(pDX, m_FoodNameD, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameC, m_FoodNameC);
	DDV_MaxChars(pDX, m_FoodNameC, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameB, m_FoodNameB);
	DDV_MaxChars(pDX, m_FoodNameB, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameA, m_FoodNameA);
	DDV_MaxChars(pDX, m_FoodNameA, 128);
	DDX_Text(pDX, IDC_EDIT_DiscoveryPicPath, m_DiscoveryPicPath);
	DDV_MaxChars(pDX, m_DiscoveryPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_DiscoveryPicInfo, m_DiscoveryPicInfo);
	DDV_MaxChars(pDX, m_DiscoveryPicInfo, 128);
	DDX_Text(pDX, IDC_EDIT_DiscoveryName, m_DiscoveryName);
	DDV_MaxChars(pDX, m_DiscoveryName, 128);
	DDX_Text(pDX, IDC_EDIT_DataOutputPath, m_DataOutputPath);
	DDV_MaxChars(pDX, m_DataOutputPath, 260);
	DDX_CBIndex(pDX, IDC_COMBO_Food, m_Food);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoColorA, m_ImagoColorA);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoColorB, m_ImagoColorB);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoColorC, m_ImagoColorC);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoColorD, m_ImagoColorD);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoColorNum, m_ImagoColorNum);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoNo, m_ImagoNo);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoSex, m_ImagoSex);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoTexture, m_ImagoTexture);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoVillus, m_ImagoVillus);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaCalthrop, m_LarvaCalthrop);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaColorA, m_LarvaColorA);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaColorB, m_LarvaColorB);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaColorC, m_LarvaColorC);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaColorD, m_LarvaColorD);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaColorNum, m_LarvaColorNum);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaInstar, m_LarvaInstar);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaNo, m_LarvaNo);
	DDX_CBIndex(pDX, IDC_COMBO_LarvaSex, m_LarvaSex);
	DDX_CBIndex(pDX, IDC_COMBO_OvumColor, m_OvumColor);
	DDX_CBIndex(pDX, IDC_COMBO_OvumNo, m_OvumNo);
	DDX_CBIndex(pDX, IDC_COMBO_OvumSex, m_OvumSex);
	DDX_CBIndex(pDX, IDC_COMBO_PupaColorA, m_PupaColorA);
	DDX_CBIndex(pDX, IDC_COMBO_PupaColorB, m_PupaColorB);
	DDX_CBIndex(pDX, IDC_COMBO_PupaColorC, m_PupaColorC);
	DDX_CBIndex(pDX, IDC_COMBO_PupaColorD, m_PupaColorD);
	DDX_CBIndex(pDX, IDC_COMBO_PupaColorNum, m_PupaColorNum);
	DDX_CBIndex(pDX, IDC_COMBO_PupaNo, m_PupaNo);
	DDX_CBIndex(pDX, IDC_COMBO_PupaSex, m_PupaSex);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZogiiaddDlg, CDialog)
	//{{AFX_MSG_MAP(CZogiiaddDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DiscoveryPicPath, OnBUTTONDiscoveryPicPath)
	ON_BN_CLICKED(IDC_BUTTON_DiscoveryPicView, OnBUTTONDiscoveryPicView)
	ON_BN_CLICKED(IDC_BUTTON_DeleteData, OnBUTTONDeleteData)
	ON_BN_CLICKED(IDC_BUTTON_SaveData, OnBUTTONSaveData)
	ON_BN_CLICKED(IDC_BUTTON_DataOutputPath, OnBUTTONDataOutputPath)
	ON_BN_CLICKED(IDC_BUTTON_DataOutput, OnBUTTONDataOutput)
	ON_BN_CLICKED(IDC_BUTTON_TextTWPath, OnBUTTONTextTWPath)
	ON_BN_CLICKED(IDC_BUTTON_TextTWView, OnBUTTONTextTWView)
	ON_BN_CLICKED(IDC_BUTTON_TextCNPath, OnBUTTONTextCNPath)
	ON_BN_CLICKED(IDC_BUTTON_TextCNView, OnBUTTONTextCNView)
	ON_BN_CLICKED(IDC_BUTTON_TextENPath, OnBUTTONTextENPath)
	ON_BN_CLICKED(IDC_BUTTON_TextENView, OnBUTTONTextENView)
	ON_BN_CLICKED(IDC_BUTTON_ImagoPicView, OnBUTTONImagoPicView)
	ON_BN_CLICKED(IDC_BUTTON_ImagoPicPath, OnBUTTONImagoPicPath)
	ON_BN_CLICKED(IDC_BUTTON_SaveImago, OnBUTTONSaveImago)
	ON_BN_CLICKED(IDC_BUTTON_DeleteImago, OnBUTTONDeleteImago)
	ON_BN_CLICKED(IDC_BUTTON_LarvaPicView, OnBUTTONLarvaPicView)
	ON_BN_CLICKED(IDC_BUTTON_LarvaPicPath, OnBUTTONLarvaPicPath)
	ON_BN_CLICKED(IDC_BUTTON_DeleteLarva, OnBUTTONDeleteLarva)
	ON_BN_CLICKED(IDC_BUTTON_SaveLarva, OnBUTTONSaveLarva)
	ON_BN_CLICKED(IDC_BUTTON_SaveFood, OnBUTTONSaveFood)
	ON_BN_CLICKED(IDC_BUTTON_SaveOtherName, OnBUTTONSaveOtherName)
	ON_BN_CLICKED(IDC_BUTTON_OvumPicView, OnBUTTONOvumPicView)
	ON_BN_CLICKED(IDC_BUTTON_OvumPicPath, OnBUTTONOvumPicPath)
	ON_BN_CLICKED(IDC_BUTTON_SaveOvum, OnBUTTONSaveOvum)
	ON_BN_CLICKED(IDC_BUTTON_DeleteOvum, OnBUTTONDeleteOvum)
	ON_BN_CLICKED(IDC_BUTTON_PupaPicPath, OnBUTTONPupaPicPath)
	ON_BN_CLICKED(IDC_BUTTON_PupaPicView, OnBUTTONPupaPicView)
	ON_BN_CLICKED(IDC_BUTTON_SavePupa, OnBUTTONSavePupa)
	ON_BN_CLICKED(IDC_BUTTON_DeletePupa, OnBUTTONDeletePupa)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZogiiaddDlg message handlers

BOOL CZogiiaddDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	zogiiReadDB(&DBtotal,DBdata);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZogiiaddDlg::OnPaint() 
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
HCURSOR CZogiiaddDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CZogiiaddDlg::OnBUTTONDiscoveryPicPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_DiscoveryPicPath);
}

void CZogiiaddDlg::OnBUTTONDiscoveryPicView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewPic(m_DiscoveryPicPath);
}

void CZogiiaddDlg::OnBUTTONDeleteData() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONSaveData() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONDataOutputPath() 
{
	// TODO: Add your control notification handler code here
	SaveToDir(IDC_EDIT_DataOutputPath);
}

void CZogiiaddDlg::OnBUTTONDataOutput() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONTextTWPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_TextTWPath);
}

void CZogiiaddDlg::OnBUTTONTextTWView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewText(m_TextTWPath);
}

void CZogiiaddDlg::OnBUTTONTextCNPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_TextCNPath);
}

void CZogiiaddDlg::OnBUTTONTextCNView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewText(m_TextCNPath);
}

void CZogiiaddDlg::OnBUTTONTextENPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_TextENPath);
}

void CZogiiaddDlg::OnBUTTONTextENView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewText(m_TextENPath);
}

void CZogiiaddDlg::OnBUTTONImagoPicView() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONImagoPicPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_ImagoPicPath);
}

void CZogiiaddDlg::OnBUTTONSaveImago() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewPic(m_ImagoPicPath);
}

void CZogiiaddDlg::OnBUTTONDeleteImago() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONLarvaPicPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_LarvaPicPath);
}

void CZogiiaddDlg::OnBUTTONLarvaPicView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewPic(m_LarvaPicPath);
}

void CZogiiaddDlg::OnBUTTONDeleteLarva() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONSaveLarva() 
{
	// TODO: Add your control notification handler code here
	
}


void CZogiiaddDlg::OnBUTTONSaveFood() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONSaveOtherName() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONOvumPicPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_OvumPicPath);
}

void CZogiiaddDlg::OnBUTTONOvumPicView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewPic(m_OvumPicPath);
}

void CZogiiaddDlg::OnBUTTONSaveOvum() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONDeleteOvum() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONPupaPicPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_PupaPicPath);	
}

void CZogiiaddDlg::OnBUTTONPupaPicView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewPic(m_PupaPicPath);
}

void CZogiiaddDlg::OnBUTTONSavePupa() 
{
	// TODO: Add your control notification handler code here
	
}

void CZogiiaddDlg::OnBUTTONDeletePupa() 
{
	// TODO: Add your control notification handler code here
	
}

/////////////////////////////////////////////////////////////////////////////////////
int CZogiiaddDlg::SaveToFile(int idc)
{
	// TODO: Add your control notification handler code here

	char szFilter[]="*.*||";
	//保存文件
	//CFileDialog dlg(FALSE,"*.*","",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter);
	//打开文件
	CFileDialog dlg(TRUE,"*.*","",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter);

	if(dlg.DoModal()==IDOK)
	{
		char filename[MAX_PATH];
		GetDlgItem(idc)->SetWindowText(dlg.GetPathName());
		GetDlgItem(idc)->GetWindowText(filename,sizeof(unsigned char)*MAX_PATH);
		return 1;
	}
	else
		return 0;
}

int CZogiiaddDlg::SaveToDir(int idc)
{
	//保存目录
	BROWSEINFO   bi;                           //创建BROWSEINFO结构体
	char   Buffer[MAX_PATH]= " ";
	char   FullPath[MAX_PATH]= " ";
	bi.hwndOwner   =   CZogiiaddDlg::GetSafeHwnd();               //窗口句柄
	bi.pidlRoot   =   NULL;
	bi.pszDisplayName   =   Buffer;            //返回选择的目录名的缓冲区
	bi.lpszTitle   =   "Selection ";           //弹出的窗口的文字提示
	bi.ulFlags   =   BIF_RETURNONLYFSDIRS   ;  //只返回目录。其他标志看MSDN
	bi.lpfn   =   NULL;               //回调函数，有时很有用
	bi.lParam   =   0;
	bi.iImage   =   0;
	ITEMIDLIST*   pidl   =   ::SHBrowseForFolder(&bi);   //显示弹出窗口，ITEMIDLIST很重要
	if(::SHGetPathFromIDList(pidl,FullPath)) //在ITEMIDLIST中得到目录名的整个路径
	{
		GetDlgItem(idc)->SetWindowText(FullPath);
		return 1;
	}
	else
		return 0;
}

void CZogiiaddDlg::ViewText(CString filename)
{
	char str[300];
	sprintf(str,"wordpad.exe \"%s\"",filename.GetBuffer(0));
	WinExec(str,SW_NORMAL);
}

void CZogiiaddDlg::ViewPic(CString filename)
{
	char str[300];
	sprintf(str,"mspaint.exe \"%s\"",filename.GetBuffer(0));
	WinExec(str,SW_NORMAL);
}

void CZogiiaddDlg::BulidTree()
{


}
