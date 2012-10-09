// zogiiaddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zogiiadd.h"
#include "zogiiaddDlg.h"


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
	m_FoodNameG = _T("");
	m_OtherNameG = _T("");
	m_code = 0;
	m_path = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
/////////////////////////////////////////////////////////////////////
	language=0;
	DBtotal=0;
	DBdata=NULL;
	DBPictotal=0;
	DBPicdata=NULL;

	ListTotal=0;
	ListbufTotal=256;
	DataList=(DATALIST *)calloc(ListbufTotal,sizeof(DATALIST));
	curlist=NULL;
	//第一个永远为无效
	NewPictotal=1;
	NewPicdata[0].flag=0;

	memset(&Newdata,0,sizeof(struct ZOGII_Coccinellidae_DATA));
	DataP=NULL;
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
	DDX_Text(pDX, IDC_EDIT_FoodNameG, m_FoodNameG);
	DDV_MaxChars(pDX, m_FoodNameG, 128);
	DDX_Text(pDX, IDC_EDIT_OtherNameG, m_OtherNameG);
	DDV_MaxChars(pDX, m_OtherNameG, 128);
	DDX_Text(pDX, IDC_EDIT_code, m_code);
	DDV_MinMaxUInt(pDX, m_code, 0, 600000);
	DDX_Text(pDX, IDC_EDIT_path, m_path);
	DDV_MaxChars(pDX, m_path, 260);
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
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_BN_CLICKED(IDC_BUTTON_SaveDB, OnBUTTONSaveDB)
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
	zogiiReadDB(&DBtotal,DBdata,&DBPictotal,DBPicdata);
	BuildTree();
	InitInfoData();

  	char str[250];
    sprintf(str,"zogci_db@zogna        Build:%s,%s        DataBaseVersion:%d",	\
			__DATE__,__TIME__,zogiiVersionDB());
    SetWindowText(str);

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
	UpdateData(TRUE);

	if(	(TYPE_NEW_SubFamily !=curlist->type) &&	\
		(TYPE_NEW_Genus !=curlist->type) &&		\
		(TYPE_NEW_Name !=curlist->type) &&		\
		(TYPE_NEW_SpName !=curlist->type))
	{
		zogiiDeleteDB(&DBtotal,DBdata,curlist->type,curlist->sf,curlist->ge,curlist->na,curlist->sp,DBPicdata);
		//这里做COPY是因为经过BuildDeleteTree函数以后，curlist指针被改变
		memcpy(&templist,curlist,sizeof(DATALIST));
		BuildDeleteTree(curlist);
		BuildDeleteTreeMove(&templist);
	}
	//清空数据
	InitInfoData();
	UpdateData(FALSE);
}

void CZogiiaddDlg::OnBUTTONSaveData() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CopyInfoM2D(&Newdata);

	zogiiAddSaveDB(&DBtotal,DBdata,&DBPictotal,DBPicdata,
					curlist->type,curlist->sf,curlist->ge,curlist->na,curlist->sp,
					&Newdata,NewPictotal,NewPicdata);

	BuildNewTree(curlist);

	UpdateData(FALSE);
	
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
	UpdateData(TRUE);
	ViewPic(m_ImagoPicPath);
}

void CZogiiaddDlg::OnBUTTONImagoPicPath() 
{
	// TODO: Add your control notification handler code here
	SaveToFile(IDC_EDIT_ImagoPicPath);
}

void CZogiiaddDlg::OnBUTTONSaveImago() 
{
	// TODO: Add your control notification handler code here

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

void CZogiiaddDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
//	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	HTREEITEM item_sel=m_tree.GetSelectedItem();

	unsigned int i;
	for(i=0;i<ListTotal;i++)
	{
		if((DataList[i].item == item_sel) && DataList[i].flag)
		{
			curlist=&DataList[i];
			InitInfoData();
			break;
		}
	}

//	*pResult = 0;
}

void CZogiiaddDlg::OnBUTTONSaveDB() 
{
	// TODO: Add your control notification handler code here
	zogiiWriteDB(DBtotal,DBdata,DBPictotal,DBPicdata);
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
//查看文本
void CZogiiaddDlg::ViewText(CString filename)
{
	char str[300];
	sprintf(str,"wordpad.exe \"%s\"",filename.GetBuffer(0));
	WinExec(str,SW_NORMAL);
}
//查看图片
void CZogiiaddDlg::ViewPic(CString filename)
{
	char str[300];
	sprintf(str,"mspaint.exe \"%s\"",filename.GetBuffer(0));
	WinExec(str,SW_NORMAL);
}
//为树建立BUF
void CZogiiaddDlg::AddListBuf()
{
	if(ListTotal >= ListbufTotal)
	{
		ListbufTotal+=256;
		DataList=(DATALIST *)realloc(DataList,ListbufTotal*sizeof(DATALIST));
	}
}
//增加树的一个项目
HTREEITEM CZogiiaddDlg::AddTree(HTREEITEM parent,char *str,	\
								unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,unsigned int sp)
{
	AddListBuf();

	DataList[ListTotal].Parent_item=parent;
	DataList[ListTotal].item=m_tree.InsertItem(str,parent);
	DataList[ListTotal].type=type;
	DataList[ListTotal].flag=1;

	if(TYPE_SubFamily == type)
	{
		DataList[ListTotal].sf=sf;
	}
	else 	if(TYPE_Genus == type)
	{
		DataList[ListTotal].sf=sf;
		DataList[ListTotal].ge=ge;
	}
	else 	if(TYPE_Name == type)
	{
		DataList[ListTotal].sf=sf;
		DataList[ListTotal].ge=ge;
		DataList[ListTotal].na=na;
	}	
	else 	if(TYPE_SpName == type)
	{
		DataList[ListTotal].sf=sf;
		DataList[ListTotal].ge=ge;
		DataList[ListTotal].na=na;
		DataList[ListTotal].sp=sp;
	}
	else 	if(TYPE_NEW_SubFamily == type)
	{
		NULL;
	}
	else 	if(TYPE_NEW_Genus == type)
	{
		DataList[ListTotal].sf=sf;
	}
	else 	if(TYPE_NEW_Name == type)
	{
		DataList[ListTotal].sf=sf;
		DataList[ListTotal].ge=ge;
	}
	else 	if(TYPE_NEW_SpName == type)
	{
		DataList[ListTotal].sf=sf;
		DataList[ListTotal].ge=ge;
		DataList[ListTotal].na=na;
	}

	ListTotal++;
	return DataList[ListTotal-1].item;
}
//初始化建立树
void CZogiiaddDlg::BuildTree()
{
	HTREEITEM hItemA,hItemB,hItemC;
	unsigned int i,j,k,m;

	m_tree.DeleteAllItems();

	ListTotal=0;
	for(i=0;i<DBtotal;i++)
	{
		hItemA=AddTree(TVI_ROOT,DBdata[i].SF.SubFamily[language],TYPE_SubFamily,i,0,0,0);
		for(j=0;j<DBdata[i].GenusTotal;j++)
		{
			hItemB=AddTree(hItemA,DBdata[i].GenusData[j].GE.Genus[language],TYPE_Genus,i,j,0,0);
			for(k=0;k<DBdata[i].GenusData[j].NameTotal;k++)
			{
				hItemC=AddTree(hItemB,DBdata[i].GenusData[j].NameData[k].NA.Name[language],TYPE_Name,i,j,k,0);
				for(m=0;m<DBdata[i].GenusData[j].NameData[k].SpTotal;m++)
				{
					AddTree(hItemC,DBdata[i].GenusData[j].NameData[k].SpData[m].SpName[language],TYPE_SpName,i,j,k,m);
				}
				AddTree(hItemC,NEWSpName_STR,TYPE_NEW_SpName,i,j,k,0);
			}
			AddTree(hItemB,NEWName_STR,TYPE_NEW_Name,i,j,0,0);
		}
		AddTree(hItemA,NEWGenus_STR,TYPE_NEW_Genus,i,0,0,0);
	}
	AddTree(TVI_ROOT,NEWSubFamily_STR,TYPE_NEW_SubFamily,0,0,0,0);

	curlist=&DataList[0];
}
//在新增完数据之后调用 之前要遍历树一次
void CZogiiaddDlg::BuildNewTree(DATALIST *dl)
{
	if(TYPE_SubFamily == dl->type)
	{
		//修改字符串
		m_tree.SetItemText(dl->item,DBdata[curlist->sf].SF.SubFamily[language]);
	}
	else 	if(TYPE_Genus == dl->type)
	{
		//修改字符串
		m_tree.SetItemText(dl->item,DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[language]);
	}
	else 	if(TYPE_Name == dl->type)
	{
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Name[language]);
	}	
	else 	if(TYPE_SpName == dl->type)
	{
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp].SpName[language]);
	}
	else if(TYPE_NEW_SubFamily == dl->type)
	{
		//修改状态
		dl->type=TYPE_SubFamily;
		dl->sf=DBtotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,DBdata[curlist->sf].SF.SubFamily[language]);

		//加一个兄弟
		AddTree(dl->Parent_item,NEWSubFamily_STR,TYPE_NEW_SubFamily,0,0,0,0);
		//加一个子
		AddTree(dl->item,NEWGenus_STR,TYPE_NEW_Genus,dl->sf,0,0,0);
	}
	else if(TYPE_NEW_Genus == dl->type)
	{
		//修改状态
		dl->type=TYPE_Genus;
		dl->ge=DBdata[dl->sf].GenusTotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[language]);
		//加一个兄弟
		AddTree(dl->Parent_item,NEWGenus_STR,TYPE_NEW_Genus,dl->sf,0,0,0);
		//加一个子
		AddTree(dl->item,NEWName_STR,TYPE_NEW_Name,dl->sf,dl->ge,0,0);
	}
	else if(TYPE_NEW_Name == dl->type)
	{
		//修改状态
		dl->type=TYPE_Name;
		dl->na=DBdata[dl->sf].GenusData[dl->ge].NameTotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Name[language]);
		//加一个兄弟
		AddTree(dl->Parent_item,NEWName_STR,TYPE_NEW_Name,dl->sf,dl->ge,0,0);
		//加一个子
		AddTree(dl->item,NEWSpName_STR,TYPE_NEW_SpName,dl->sf,dl->ge,dl->na,0);
	}	
	else if(TYPE_NEW_SpName == dl->type)
	{
		//修改状态
		dl->type=TYPE_SpName;
		dl->sp=DBdata[dl->sf].GenusData[dl->ge].NameData[dl->na].SpTotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp].SpName[language]);
	
		//加一个兄弟
		AddTree(dl->Parent_item,NEWSpName_STR,TYPE_NEW_SpName,dl->sf,dl->ge,dl->na,0);
	}
		
}


//在删除完数据之后调用  在调用之前判断NEW类型的不能删除
void CZogiiaddDlg::BuildDeleteTree(DATALIST *dl)
{
	unsigned int i;

	if( (TYPE_SubFamily == dl->type) || \
		(TYPE_Genus == dl->type) ||		\
		(TYPE_NEW_Genus == dl->type)||	\
		(TYPE_Name == dl->type) ||		\
		(TYPE_NEW_Name == dl->type) )
	{
		//修改状态
		for(i=0;i<ListTotal;i++)
		{
			if((DataList[i].Parent_item == dl->item) && DataList[i].flag)
			{
				//递归
				BuildDeleteTree(&DataList[i]);
				//被删除
				DataList[i].flag=0;
				m_tree.DeleteItem(DataList[i].item);
			}
		}
		//自己被删除
		dl->flag=0;
		m_tree.DeleteItem(dl->item);
	}
	else if((TYPE_SpName == dl->type) || (TYPE_NEW_SpName ==dl->type))
	{
		//自己被删除
		dl->flag=0;
		m_tree.DeleteItem(dl->item);
	}
}
void CZogiiaddDlg::BuildDeleteTreeMove(DATALIST *dl)
{
	unsigned int i;
	
	//移动具有相同父类的兄弟
	for(i=0;i<ListTotal;i++)
	{
		if((DataList[i].Parent_item == dl->Parent_item) &&	DataList[i].flag )
		{
			switch(dl->type)
			{
			case TYPE_SubFamily:
				if(	(DataList[i].sf > dl->sf) )
				{
					if(DataList[i].sf >0)
						DataList[i].sf--;
				}
				break;
				
			case TYPE_Genus:
				if(	(DataList[i].ge > dl->ge) )
				{
					if(DataList[i].ge >0)
						DataList[i].ge--;
				}
				break;
			case TYPE_Name:
				if(	(DataList[i].na > dl->na) )
				{
					if(DataList[i].na >0)
						DataList[i].na--;
				}
				break;
			case TYPE_SpName:
				if(	(DataList[i].sp > dl->sp) )
				{
					if(DataList[i].sp >0)
						DataList[i].sp--;
				}
				break;
			default:break;
			}
		}
	}
}

	

void CZogiiaddDlg::InitInfoData()
{
	if(TYPE_SubFamily == curlist->type)
	{
		CopyInfoD2M(&DBdata[curlist->sf].SF);
		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_Genus == curlist->type)
	{
		CopyInfoD2M(&DBdata[curlist->sf].GenusData[curlist->ge].GE);
		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_Name == curlist->type)
	{
		CopyInfoD2M(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);
		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_SpName == curlist->type)
	{
		CopyInfoD2M(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);
		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_NEW_SubFamily == curlist->type)
	{
		m_SubFamilyEN = _T("");
		m_SubFamilyCN = _T("");
		m_SubFamilyTW = _T("");

		m_GenusEN = _T("");
		m_GenusCN = _T("");
		m_GenusTW = _T("");

		m_NameEN = _T("");
		m_NameCN = _T("");
		m_NameTW = _T("");
	}
	else	if(TYPE_NEW_Genus == curlist->type)
	{
		m_SubFamilyEN = DBdata[curlist->sf].SF.SubFamily[0];
		m_SubFamilyCN = DBdata[curlist->sf].SF.SubFamily[1];
		m_SubFamilyTW = DBdata[curlist->sf].SF.SubFamily[2];

		m_GenusEN = _T("");
		m_GenusCN = _T("");
		m_GenusTW = _T("");

		m_NameEN = _T("");
		m_NameCN = _T("");
		m_NameTW = _T("");
	}
	else	if(TYPE_NEW_Name == curlist->type)
	{
		m_SubFamilyEN = DBdata[curlist->sf].SF.SubFamily[0];
		m_SubFamilyCN = DBdata[curlist->sf].SF.SubFamily[1];
		m_SubFamilyTW = DBdata[curlist->sf].SF.SubFamily[2];

		m_GenusEN = DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[0];
		m_GenusCN = DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[1];
		m_GenusTW = DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[2];

		m_NameEN = _T("");
		m_NameCN = _T("");
		m_NameTW = _T("");
	}
	else	if(TYPE_NEW_SpName == curlist->type)
	{
		m_SubFamilyEN = DBdata[curlist->sf].SF.SubFamily[0];
		m_SubFamilyCN = DBdata[curlist->sf].SF.SubFamily[1];
		m_SubFamilyTW = DBdata[curlist->sf].SF.SubFamily[2];

		m_GenusEN = DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[0];
		m_GenusCN = DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[1];
		m_GenusTW = DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[2];

		m_NameEN = DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Name[0];
		m_NameCN = DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Name[1];
		m_NameTW = DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Name[2];
	}

	m_code = 0;
	m_path = _T("");

	m_SpNameEN = _T("");
	m_SpNameCN = _T("");
	m_SpNameTW = _T("");

	m_TextENPath = _T("");
	m_TextCNPath = _T("");
	m_TextTWPath = _T("");

	m_OtherNameA = _T("");
	m_OtherNameB = _T("");
	m_OtherNameC = _T("");
	m_OtherNameD = _T("");
	m_OtherNameE = _T("");
	m_OtherNameF = _T("");
	m_OtherNameG = _T("");

	CTime s(2012,10,10,20,20,20); 
	m_Date = s;
	m_Food = -1;

	m_FoodNameA = _T("");
	m_FoodNameB = _T("");
	m_FoodNameC = _T("");
	m_FoodNameD = _T("");
	m_FoodNameE = _T("");
	m_FoodNameF = _T("");
	m_FoodNameG = _T("");

	m_DiscoveryName = _T("");
	UpdateData(FALSE);
	return ;
}

void CZogiiaddDlg::CopyInfoD2M(struct ZOGII_Coccinellidae_DATA* d)
{
	m_code = d->code;
	m_path = d->path;

	m_SubFamilyEN = d->SubFamily[0];
	m_SubFamilyCN = d->SubFamily[1];
	m_SubFamilyTW = d->SubFamily[2];

	m_GenusEN = d->Genus[0];
	m_GenusCN = d->Genus[1];
	m_GenusTW = d->Genus[2];
	
	m_NameEN = d->Name[0];
	m_NameCN = d->Name[1];
	m_NameTW = d->Name[2];

	m_SpNameEN = d->SpName[0];
	m_SpNameCN = d->SpName[1];
	m_SpNameTW = d->SpName[2];

	m_TextENPath = d->Text[0];
	m_TextCNPath = d->Text[1];
	m_TextTWPath = d->Text[2];

	m_OtherNameA = d->OtherName[0];
	m_OtherNameB = d->OtherName[1];
	m_OtherNameC = d->OtherName[2];
	m_OtherNameD = d->OtherName[3];
	m_OtherNameE = d->OtherName[4];
	m_OtherNameF = d->OtherName[5];
	m_OtherNameG = d->OtherName[6];

	CTime s(2000+d->year,d->month,d->day,20,20,20);

	m_Date = s;
	m_Food = d->FoodType;

	m_FoodNameA = d->FoodName[0];
	m_FoodNameB = d->FoodName[1];
	m_FoodNameC = d->FoodName[2];
	m_FoodNameD = d->FoodName[3];
	m_FoodNameE = d->FoodName[4];
	m_FoodNameF = d->FoodName[5];
	m_FoodNameG = d->FoodName[6];

	m_DiscoveryName = d->DiscoverName;

	UpdateData(FALSE);
}

void CZogiiaddDlg::CopyInfoM2D(struct ZOGII_Coccinellidae_DATA* d)
{
	UpdateData(TRUE);

	d->code = m_code;
	memcpy(d->path , m_path.GetBuffer(0),m_path.GetAllocLength()); 

	memcpy(d->SubFamily[0] , m_SubFamilyEN.GetBuffer(0),m_SubFamilyEN.GetAllocLength()); 
	memcpy(d->SubFamily[1] , m_SubFamilyCN.GetBuffer(0),m_SubFamilyCN.GetAllocLength()); 
	memcpy(d->SubFamily[2] , m_SubFamilyTW.GetBuffer(0),m_SubFamilyTW.GetAllocLength()); 

	memcpy(d->Genus[0] , m_GenusEN.GetBuffer(0),m_GenusEN.GetAllocLength()); 
	memcpy(d->Genus[1] , m_GenusCN.GetBuffer(0),m_GenusCN.GetAllocLength()); 
	memcpy(d->Genus[2] , m_GenusTW.GetBuffer(0),m_GenusTW.GetAllocLength()); 

	memcpy(d->Name[0] , m_NameEN.GetBuffer(0),m_NameEN.GetAllocLength()); 
	memcpy(d->Name[1] , m_NameCN.GetBuffer(0),m_NameCN.GetAllocLength()); 
	memcpy(d->Name[2] , m_NameTW.GetBuffer(0),m_NameTW.GetAllocLength()); 

	memcpy(d->SpName[0] , m_SpNameEN.GetBuffer(0),m_SpNameEN.GetAllocLength()); 
	memcpy(d->SpName[1] , m_SpNameCN.GetBuffer(0),m_SpNameCN.GetAllocLength()); 
	memcpy(d->SpName[2] , m_SpNameTW.GetBuffer(0),m_SpNameTW.GetAllocLength()); 

	memcpy(d->Text[0] , m_TextENPath.GetBuffer(0),m_TextENPath.GetAllocLength()); 
	memcpy(d->Text[1] , m_TextCNPath.GetBuffer(0),m_TextCNPath.GetAllocLength()); 
	memcpy(d->Text[2] , m_TextTWPath.GetBuffer(0),m_TextTWPath.GetAllocLength()); 

	memcpy(d->OtherName[0] , m_OtherNameA.GetBuffer(0),m_OtherNameA.GetAllocLength()); 
	memcpy(d->OtherName[1] , m_OtherNameB.GetBuffer(0),m_OtherNameB.GetAllocLength()); 
	memcpy(d->OtherName[2] , m_OtherNameC.GetBuffer(0),m_OtherNameC.GetAllocLength()); 
	memcpy(d->OtherName[3] , m_OtherNameD.GetBuffer(0),m_OtherNameD.GetAllocLength()); 
	memcpy(d->OtherName[4] , m_OtherNameE.GetBuffer(0),m_OtherNameE.GetAllocLength()); 
	memcpy(d->OtherName[5] , m_OtherNameF.GetBuffer(0),m_OtherNameF.GetAllocLength()); 
	memcpy(d->OtherName[6] , m_OtherNameG.GetBuffer(0),m_OtherNameG.GetAllocLength()); 

	d->year=(char)(m_Date.GetYear()-2000);
	d->month=(char)m_Date.GetMonth();
	d->day=(char)m_Date.GetDay();

	d->FoodType =(char)m_Food; 

	memcpy(d->FoodName[0] , m_FoodNameA.GetBuffer(0),m_FoodNameA.GetAllocLength()); 
	memcpy(d->FoodName[1] , m_FoodNameB.GetBuffer(0),m_FoodNameB.GetAllocLength()); 
	memcpy(d->FoodName[2] , m_FoodNameC.GetBuffer(0),m_FoodNameC.GetAllocLength()); 
	memcpy(d->FoodName[3] , m_FoodNameD.GetBuffer(0),m_FoodNameD.GetAllocLength()); 
	memcpy(d->FoodName[4] , m_FoodNameE.GetBuffer(0),m_FoodNameE.GetAllocLength()); 
	memcpy(d->FoodName[5] , m_FoodNameF.GetBuffer(0),m_FoodNameF.GetAllocLength()); 
	memcpy(d->FoodName[6] , m_FoodNameG.GetBuffer(0),m_FoodNameG.GetAllocLength()); 

	memcpy(d->DiscoverName , m_DiscoveryName.GetBuffer(0),m_DiscoveryName.GetAllocLength()); 

}

