// zogiiaddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zogiiadd.h"
#include "zogiiaddDlg.h"
#include "DLGmap.h"

#include "MyFileDialog.h"

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
	//{{AFX_DATA_INIT(CZogiiaddDlg);
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
	m_FoodNameD = _T("");
	m_FoodNameC = _T("");
	m_FoodNameB = _T("");
	m_FoodNameA = _T("");
	m_DiscoveryName = _T("");
	m_Food = -1;
	m_ImagoNo = 0;
	m_ImagoSex = -1;
	m_ImagoVillus = -1;
	m_LarvaCalthrop = -1;
	m_LarvaColorA = -1;
	m_LarvaColorB = -1;
	m_LarvaColorC = -1;
	m_LarvaColorD = -1;
	m_LarvaColorNum = -1;
	m_LarvaInstar = -1;
	m_LarvaNo = 0;
	m_LarvaSex = -1;
	m_OvumColor = -1;
	m_OvumNo = 0;
	m_OvumSex = -1;
	m_PupaColorA = -1;
	m_PupaColorB = -1;
	m_PupaColorC = -1;
	m_PupaColorD = -1;
	m_PupaColorNum = -1;
	m_PupaNo = 0;
	m_PupaSex = -1;
	m_OtherNameG = _T("");
	m_code = 0;
	m_path = _T("");
	m_ImagoElytraColorA = -1;
	m_ImagoElytraColorB = -1;
	m_ImagoElytraColorC = -1;
	m_ImagoElytraColorD = -1;
	m_ImagoElytraColorNum = -1;
	m_ImagoElytraTexture = -1;
	m_ImagoPronotumColorA = -1;
	m_ImagoPronotumColorB = -1;
	m_ImagoPronotumColorC = -1;
	m_ImagoPronotumColorD = -1;
	m_ImagoPronotumColorNum = -1;
	m_ImagoPronotumPointNum = -1;
	m_ImagoPronotumTexture = -1;
	m_ImagoElytraPointNum = -1;
	m_ImagobellyColor = -1;
	m_Light = -1;
	m_Living = -1;
	m_LivingNameB = _T("");
	m_LivingNameA = _T("");
	m_LivingNameC = _T("");
	m_PupaType = -1;
	m_OverWinter = -1;
	m_CloseupNo = -1;
	m_CloseupType = -1;
	m_CloseupPicInfo = _T("");
	m_CloseupPicPath = _T("");
	m_minsize = 0;
	m_maxsize = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
/////////////////////////////////////////////////////////////////////
	language=0;
	DBtotal=0;
	DBdata=NULL;
	
	DBImagototal=0;
	DBImagodata=NULL;
	
	DBLarvatotal=0;
	DBLarvadata=NULL;
	
	DBPupatotal=0;
	DBPupadata=NULL;
	
	DBOvumtotal=0;
	DBOvumdata=NULL;
	
	DBCloseuptotal=0;
	DBCloseupdata=NULL;

	ListTotal=0;
	ListbufTotal=5120;
	DataList=(DATALIST *)calloc(ListbufTotal,sizeof(DATALIST));
	curlist=NULL;

	memset(&Newdata,0,sizeof(struct ZOGII_Coccinellidae_DATA));
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
	DDV_MaxChars(pDX, m_PupaPicInfo, 260);
	DDX_Text(pDX, IDC_EDIT_OvumPicPath, m_OvumPicPath);
	DDV_MaxChars(pDX, m_OvumPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_OvumPicInfo, m_OvumPicInfo);
	DDV_MaxChars(pDX, m_OvumPicInfo, 260);
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
	DDV_MaxChars(pDX, m_LarvaPicInfo, 260);
	DDX_Text(pDX, IDC_EDIT_ImagoPicPath, m_ImagoPicPath);
	DDV_MaxChars(pDX, m_ImagoPicPath, 260);
	DDX_Text(pDX, IDC_EDIT_ImagoPicInfo, m_ImagoPicInfo);
	DDV_MaxChars(pDX, m_ImagoPicInfo, 260);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_Date, m_Date);
	DDX_Text(pDX, IDC_EDIT_GenusTW, m_GenusTW);
	DDV_MaxChars(pDX, m_GenusTW, 128);
	DDX_Text(pDX, IDC_EDIT_GenusEN, m_GenusEN);
	DDV_MaxChars(pDX, m_GenusEN, 128);
	DDX_Text(pDX, IDC_EDIT_GenusCN, m_GenusCN);
	DDV_MaxChars(pDX, m_GenusCN, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameD, m_FoodNameD);
	DDV_MaxChars(pDX, m_FoodNameD, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameC, m_FoodNameC);
	DDV_MaxChars(pDX, m_FoodNameC, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameB, m_FoodNameB);
	DDV_MaxChars(pDX, m_FoodNameB, 128);
	DDX_Text(pDX, IDC_EDIT_FoodNameA, m_FoodNameA);
	DDV_MaxChars(pDX, m_FoodNameA, 128);
	DDX_Text(pDX, IDC_EDIT_DiscoveryName, m_DiscoveryName);
	DDV_MaxChars(pDX, m_DiscoveryName, 128);
	DDX_CBIndex(pDX, IDC_COMBO_Food, m_Food);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoNo, m_ImagoNo);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoSex, m_ImagoSex);
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
	DDX_Text(pDX, IDC_EDIT_OtherNameG, m_OtherNameG);
	DDV_MaxChars(pDX, m_OtherNameG, 128);
	DDX_Text(pDX, IDC_EDIT_code, m_code);
	DDV_MinMaxUInt(pDX, m_code, 0, 600000);
	DDX_Text(pDX, IDC_EDIT_path, m_path);
	DDV_MaxChars(pDX, m_path, 260);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraColorA, m_ImagoElytraColorA);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraColorB, m_ImagoElytraColorB);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraColorC, m_ImagoElytraColorC);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraColorD, m_ImagoElytraColorD);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraColorNum, m_ImagoElytraColorNum);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraTexture, m_ImagoElytraTexture);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumColorA, m_ImagoPronotumColorA);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumColorB, m_ImagoPronotumColorB);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumColorC, m_ImagoPronotumColorC);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumColorD, m_ImagoPronotumColorD);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumColorNum, m_ImagoPronotumColorNum);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumPointNum, m_ImagoPronotumPointNum);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoPronotumTexture, m_ImagoPronotumTexture);
	DDX_CBIndex(pDX, IDC_COMBO_ImagoElytraPointNum, m_ImagoElytraPointNum);
	DDX_CBIndex(pDX, IDC_COMBO_ImagobellyColor, m_ImagobellyColor);
	DDX_CBIndex(pDX, IDC_COMBO_LIGHT, m_Light);
	DDX_CBIndex(pDX, IDC_COMBO_LIVING, m_Living);
	DDX_Text(pDX, IDC_EDIT_LivingNameB, m_LivingNameB);
	DDV_MaxChars(pDX, m_LivingNameB, 128);
	DDX_Text(pDX, IDC_EDIT_LivingNameA, m_LivingNameA);
	DDV_MaxChars(pDX, m_LivingNameA, 128);
	DDX_Text(pDX, IDC_EDIT_LivingNameC, m_LivingNameC);
	DDV_MaxChars(pDX, m_LivingNameC, 128);
	DDX_CBIndex(pDX, IDC_COMBO_PupaType, m_PupaType);
	DDX_CBIndex(pDX, IDC_COMBO_OVERWINTER, m_OverWinter);
	DDX_CBIndex(pDX, IDC_COMBO_CloseupNo, m_CloseupNo);
	DDX_CBIndex(pDX, IDC_COMBO_CloseupType, m_CloseupType);
	DDX_Text(pDX, IDC_EDIT_CloseupPicInfo, m_CloseupPicInfo);
	DDV_MaxChars(pDX, m_CloseupPicInfo, 260);
	DDX_Text(pDX, IDC_EDIT_CloseupPicPath, m_CloseupPicPath);
	DDV_MaxChars(pDX, m_CloseupPicPath, 260);
	DDX_Slider(pDX, IDC_SLIDER_MINSIZE, m_minsize);
	DDX_Slider(pDX, IDC_SLIDER_MAXSIZE, m_maxsize);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZogiiaddDlg, CDialog)
	//{{AFX_MSG_MAP(CZogiiaddDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DeleteData, OnBUTTONDeleteData)
	ON_BN_CLICKED(IDC_BUTTON_SaveData, OnBUTTONSaveData)
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
	ON_CBN_CLOSEUP(IDC_COMBO_ImagoNo, OnCloseupCOMBOImagoNo)
	ON_CBN_CLOSEUP(IDC_COMBO_LarvaNo, OnCloseupCOMBOLarvaNo)
	ON_CBN_CLOSEUP(IDC_COMBO_OvumNo, OnCloseupCOMBOOvumNo)
	ON_CBN_CLOSEUP(IDC_COMBO_PupaNo, OnCloseupCOMBOPupaNo)
	ON_BN_CLICKED(IDC_BUTTON_OpenPath, OnBUTTONOpenPath)
	ON_BN_CLICKED(IDC_BUTTON_CloseupPicPath, OnBUTTONCloseupPicPath)
	ON_BN_CLICKED(IDC_BUTTON_CloseupPicView, OnBUTTONCloseupPicView)
	ON_BN_CLICKED(IDC_BUTTON_SaveCloseup, OnBUTTONSaveCloseup)
	ON_BN_CLICKED(IDC_BUTTON_DeleteCloseup, OnBUTTONDeleteCloseup)
	ON_CBN_CLOSEUP(IDC_COMBO_CloseupNo, OnCloseupCOMBOCloseupNo)
	ON_BN_CLICKED(IDC_BUTTON_DATAOUT, OnButtonDataout)
	ON_BN_CLICKED(IDC_BUTTON_DATAIN, OnButtonDatain)
	ON_BN_CLICKED(IDC_BUTTON_DISCOVERYMAP, OnButtonDiscoverymap)
	ON_BN_CLICKED(IDC_BUTTON_TREEOUT, OnButtonTreeout)
	ON_BN_CLICKED(IDC_BUTTON_NEWImago, OnBUTTONNEWImago)
	ON_BN_CLICKED(IDC_BUTTON_NEWLarva, OnBUTTONNEWLarva)
	ON_BN_CLICKED(IDC_BUTTON_NEWCloseup, OnBUTTONNEWCloseup)
	ON_BN_CLICKED(IDC_BUTTON_NEWOvum, OnBUTTONNEWOvum)
	ON_BN_CLICKED(IDC_BUTTON_NEWPupa, OnBUTTONNEWPupa)
	ON_BN_CLICKED(IDC_BUTTON_FASTMAP, OnButtonFastmap)
	ON_BN_CLICKED(IDC_BUTTON_FASTSTR, OnButtonFaststr)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_MAXSIZE, OnCustomdrawSliderMaxsize)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_MINSIZE, OnCustomdrawSliderMinsize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZogiiaddDlg message handlers
//重载OK键 默认不关闭
void CZogiiaddDlg::OnOK()
{
}

BOOL CZogiiaddDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	GetCurrentDirectory(ZOGII_PAT_MAX,CurrentDir);
	zogiiSetDirectory(CurrentDir);
	// TODO: Add extra initialization here
	zogiiReadDB(&DBtotal,DBdata,
		&DBImagototal,DBImagodata,
		&DBLarvatotal,DBLarvadata,
		&DBPupatotal,DBPupadata,
		&DBOvumtotal,DBOvumdata,
		&DBCloseuptotal,DBCloseupdata);

	BuildTree();
	InitInfoData();

  	char str[250];

    sprintf(str,"zogci_db@zogna      Build:%s,%s     DataBaseVersion:%d    亚科%d属%d种%d亚种%d PicTotal:%d",	\
			__DATE__,__TIME__,zogiiVersionDB(),	\
			zogiiSFTotalDB(),zogiiGETotalDB(),zogiiNATotalDB(),zogiiSPTotalDB(),
				DBImagototal+DBLarvatotal+DBPupatotal+DBOvumtotal+DBCloseuptotal);
    SetWindowText(str);

	sprintf(str,"%d",Newdata.DiscoverMapTotal);
	GetDlgItem(IDC_STATIC_DISCOVERTOTAL)->SetWindowText(str);

	//插序号
	int i;

	CComboBox* comboctrl=(CComboBox*)GetDlgItem(IDC_COMBO_ImagoNo);
	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
	{
		sprintf(str,"%d",i); 
		comboctrl->AddString(str); 
	}

	comboctrl=(CComboBox*)GetDlgItem(IDC_COMBO_LarvaNo);
	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
	{
		sprintf(str,"%d",i); 
		comboctrl->AddString(str); 
	}

	comboctrl=(CComboBox*)GetDlgItem(IDC_COMBO_PupaNo);
	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
	{
		sprintf(str,"%d",i); 
		comboctrl->AddString(str); 
	}

	comboctrl=(CComboBox*)GetDlgItem(IDC_COMBO_OvumNo);
	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
	{
		sprintf(str,"%d",i); 
		comboctrl->AddString(str); 
	}

	comboctrl=(CComboBox*)GetDlgItem(IDC_COMBO_CloseupNo);
	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
	{
		sprintf(str,"%d",i); 
		comboctrl->AddString(str); 
	}

	CSliderCtrl* sliderctrl;

	sliderctrl=(CSliderCtrl*)GetDlgItem(IDC_SLIDER_MAXSIZE);
	sliderctrl->SetRange(0,200,TRUE); 

	sliderctrl=(CSliderCtrl*)GetDlgItem(IDC_SLIDER_MINSIZE);
	sliderctrl->SetRange(0,200,TRUE); 

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

void CZogiiaddDlg::OnBUTTONDeleteData() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if(	(TYPE_NEW_SubFamily !=curlist->type) &&	\
		(TYPE_NEW_Genus !=curlist->type) &&		\
		(TYPE_NEW_Name !=curlist->type) &&		\
		(TYPE_NEW_SpName !=curlist->type))
	{
		zogiiDeleteDB(&DBtotal,DBdata,
			curlist->type,curlist->sf,curlist->ge,curlist->na,curlist->sp,
			DBImagodata,DBLarvadata,DBPupadata,	DBOvumdata,DBCloseupdata);
		//这里做COPY是因为经过BuildDeleteTree函数以后，curlist指针被改变
		memcpy(&templist,curlist,sizeof(DATALIST));
		BuildDeleteTree(curlist);
		BuildDeleteTreeMove(&templist);
	}
	//清空数据
	InitInfoData();
	UpdateData(FALSE);
	MessageBox(_T("删除成功"), _T("删除"));

	char str[10];
	sprintf(str,"%d",Newdata.DiscoverMapTotal);
	GetDlgItem(IDC_STATIC_DISCOVERTOTAL)->SetWindowText(str);
}

void CZogiiaddDlg::OnBUTTONSaveData() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CopyInfoM2NewData();

	zogiiAddSaveDB(&DBtotal,DBdata,
		&DBImagototal,DBImagodata,
		&DBLarvatotal,DBLarvadata,
		&DBPupatotal,DBPupadata,
		&DBOvumtotal,DBOvumdata,
		&DBCloseuptotal,DBCloseupdata,
		curlist->type,curlist->sf,curlist->ge,curlist->na,curlist->sp,
		&Newdata,
		NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata);

	BuildNewTree(curlist);

	UpdateData(FALSE);
	MessageBox(_T("保存成功"), _T("保存"));
}
/*
void CZogiiaddDlg::OnBUTTONDataOutputPath() 
{
	// TODO: Add your control notification handler code here
	SaveToDir(IDC_EDIT_DataOutputPath);
}

void CZogiiaddDlg::OnBUTTONDataOutput() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	char str[600];
	if(m_DataOutputPath.IsEmpty())
		return ;
	//只会拷贝文件。 子文件夹不会被拷贝
	sprintf(str,"xcopy /y \"%s\\%s\" \"%s\"",CurrentDir,Newdata.Path,m_DataOutputPath);
	WinExec(str,SW_HIDE);
	MessageBox(_T("导出成功"), _T("导出"));
}
*/

void CZogiiaddDlg::OnBUTTONTextTWPath() 
{
	// TODO: Add your control notification handler code here
	OpenToTxtFile(IDC_EDIT_TextTWPath);
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
	OpenToTxtFile(IDC_EDIT_TextCNPath);
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
	OpenToTxtFile(IDC_EDIT_TextENPath);
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
	OpenToPicFile(IDC_EDIT_ImagoPicPath);
}

void CZogiiaddDlg::OnBUTTONSaveImago() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SaveM2Imago(m_ImagoNo);
}

void CZogiiaddDlg::OnBUTTONDeleteImago() 
{
	// TODO: Add your control notification handler code here
	CleanImago2M();
	UpdateData(FALSE);
	UpdateData(TRUE);
	SaveM2Imago(m_ImagoNo);
}

void CZogiiaddDlg::OnBUTTONLarvaPicPath() 
{
	// TODO: Add your control notification handler code here
	OpenToPicFile(IDC_EDIT_LarvaPicPath);
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
	CleanLarva2M();
	UpdateData(FALSE);
	UpdateData(TRUE);
	SaveM2Larva(m_LarvaNo);
}

void CZogiiaddDlg::OnBUTTONSaveLarva() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SaveM2Larva(m_LarvaNo);
}

void CZogiiaddDlg::OnBUTTONOvumPicPath() 
{
	// TODO: Add your control notification handler code here
	OpenToPicFile(IDC_EDIT_OvumPicPath);
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
	UpdateData(TRUE);
	SaveM2Ovum(m_OvumNo);
}

void CZogiiaddDlg::OnBUTTONDeleteOvum() 
{
	// TODO: Add your control notification handler code here
	CleanOvum2M();
	UpdateData(FALSE);
	UpdateData(TRUE);
	SaveM2Ovum(m_OvumNo);
}

void CZogiiaddDlg::OnBUTTONPupaPicPath() 
{
	// TODO: Add your control notification handler code here
	OpenToPicFile(IDC_EDIT_PupaPicPath);	
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
	UpdateData(TRUE);
	SaveM2Pupa(m_PupaNo);
}

void CZogiiaddDlg::OnBUTTONDeletePupa() 
{
	// TODO: Add your control notification handler code here
	CleanPupa2M();
	UpdateData(FALSE);
	UpdateData(TRUE);
	SaveM2Pupa(m_PupaNo);
}

void CZogiiaddDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
//	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	char str[10];

	HTREEITEM item_sel=m_tree.GetSelectedItem();

	ZOGII_LONG_TYPE i;
	for(i=0;i<ListTotal;i++)
	{
		if((DataList[i].item == item_sel) && DataList[i].flag)
		{
			curlist=&DataList[i];
			InitInfoData();
			
			sprintf(str,"%d",Newdata.DiscoverMapTotal);
			GetDlgItem(IDC_STATIC_DISCOVERTOTAL)->SetWindowText(str);
			break;
		}
	}

//	*pResult = 0;
}

void CZogiiaddDlg::OnBUTTONSaveDB() 
{
	// TODO: Add your control notification handler code here
	if(zogiiWriteDB(DBtotal,DBdata,
		DBImagototal,DBImagodata,
		DBLarvatotal,DBLarvadata,
		DBPupatotal,DBPupadata,
		DBOvumtotal,DBOvumdata,
		DBCloseuptotal,DBCloseupdata))
		MessageBox(_T("数据库保存成功"), _T("数据库保存"));
	else
		MessageBox(_T("数据库保存失败"), _T("数据库保存"));
}

void CZogiiaddDlg::OnCloseupCOMBOImagoNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ReadImago2M(m_ImagoNo);
	UpdateData(FALSE);
}

void CZogiiaddDlg::OnCloseupCOMBOLarvaNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ReadLarva2M(m_LarvaNo);
	UpdateData(FALSE);
}

void CZogiiaddDlg::OnCloseupCOMBOOvumNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ReadOvum2M(m_OvumNo);
	UpdateData(FALSE);
}

void CZogiiaddDlg::OnCloseupCOMBOPupaNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ReadPupa2M(m_PupaNo);
	UpdateData(FALSE);
}

void CZogiiaddDlg::OnBUTTONCloseupPicPath() 
{
	// TODO: Add your control notification handler code here
	OpenToPicFile(IDC_EDIT_CloseupPicPath);
}

void CZogiiaddDlg::OnBUTTONCloseupPicView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ViewPic(m_CloseupPicPath);
}

void CZogiiaddDlg::OnBUTTONSaveCloseup() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SaveM2Closeup(m_CloseupNo);
}

void CZogiiaddDlg::OnBUTTONDeleteCloseup() 
{
	// TODO: Add your control notification handler code here
	CleanCloseup2M();
	UpdateData(FALSE);
	UpdateData(TRUE);
	SaveM2Closeup(m_CloseupNo);
}

void CZogiiaddDlg::OnCloseupCOMBOCloseupNo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ReadCloseup2M(m_CloseupNo);
	UpdateData(FALSE);
}

void CZogiiaddDlg::OnBUTTONOpenPath() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	char str[300];
	if(m_path.IsEmpty())
		return ;
	sprintf(str,"explorer.exe \"%s\\%s\"",CurrentDir,m_path.GetBuffer(0));
	WinExec(str,SW_NORMAL);
}

/////////////////////////////////////////////////////////////////////////////////////

/*
int CZogiiaddDlg::SaveToFile(int idc)
{
	// TODO: Add your control notification handler code here
	char szFilter[]="Picture file(*.jpg;*.jpeg;*.bmp;*.png;*.dib;*.tga)|	\
							*.jpg;*.jpeg;*.bmp;*.png;*.dib;*.tga|	\
							Text files(*.txt)|*.txt|All files (*.*)|*.*||";
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
*/

int CZogiiaddDlg::OpenToPicFile(int idc)
{

	// TODO: Add your control notification handler code here
	char szFilter[]="Picture file(*.jpg;*.jpeg;*.bmp;*.png;*.dib;*.tga;*.gif)|*.jpg;*.jpeg;*.bmp;*.png;*.dib;*.tga;*.gif|All files (*.*)|*.*||";
#if 0
	//保存文件
	//CFileDialog dlg(FALSE,"*.*","",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter);
	//打开文件
	CFileDialog dlg(TRUE,"*.*","",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter);
#else
	CMyFileDialog dlg(TRUE,"*.*","",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter,NULL,720,480);
#endif

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

int CZogiiaddDlg::OpenToTxtFile(int idc)
{
	// TODO: Add your control notification handler code here
	char szFilter[]="Text files(*.txt)|*.txt|All files (*.*)|*.*||";
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

	if(filename.IsEmpty())
		return ;
	if('z'==filename[0])
		sprintf(str,"notepad.exe \"%s\\%s\"",CurrentDir,filename.GetBuffer(0));
	else
		sprintf(str,"notepad.exe \"%s\"",filename.GetBuffer(0));

	WinExec(str,SW_NORMAL);
}
//查看图片
void CZogiiaddDlg::ViewPic(CString filename)
{
	char str[300];

	if(filename.IsEmpty())
		return ;

	if('z'==filename[0])
		sprintf(str,"mspaint.exe \"%s\\%s\"",CurrentDir,filename.GetBuffer(0));
	else
		sprintf(str,"mspaint.exe \"%s\"",filename.GetBuffer(0));

	WinExec(str,SW_NORMAL);
}
//为树建立BUF
void CZogiiaddDlg::AddListBuf()
{
	if(ListTotal >= ListbufTotal)
	{
		ListbufTotal+=1024;
		DataList=(DATALIST *)realloc(DataList,ListbufTotal*sizeof(DATALIST));
	}
}
//增加树的一个项目
HTREEITEM CZogiiaddDlg::AddTree(HTREEITEM parent,char *str,	\
								unsigned char type,ZOGII_LONG_TYPE sf,ZOGII_LONG_TYPE ge,ZOGII_LONG_TYPE na,ZOGII_LONG_TYPE sp)
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
	ZOGII_ULONG_TYPE i,j,k,m;

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
				hItemC=AddTree(hItemB,DBdata[i].GenusData[j].NameData[k].NA.Species[language],TYPE_Name,i,j,k,0);
				for(m=0;m<DBdata[i].GenusData[j].NameData[k].SpTotal;m++)
				{
					AddTree(hItemC,DBdata[i].GenusData[j].NameData[k].SpData[m].Subspecies[language],TYPE_SpName,i,j,k,m);
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
	DATALIST tempdl;

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
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Species[language]);
	}	
	else 	if(TYPE_SpName == dl->type)
	{
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp].Subspecies[language]);
	}
	else if(TYPE_NEW_SubFamily == dl->type)
	{
		//修改状态
		dl->type=TYPE_SubFamily;
		dl->sf=DBtotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,DBdata[curlist->sf].SF.SubFamily[language]);
#if 1
		memcpy(&tempdl,dl,sizeof(DATALIST));
				//加一个兄弟
		AddTree(tempdl.Parent_item,NEWSubFamily_STR,TYPE_NEW_SubFamily,0,0,0,0);
		//加一个子
		AddTree(tempdl.item,NEWGenus_STR,TYPE_NEW_Genus,tempdl.sf,0,0,0);
#else
		//加一个兄弟
		AddTree(dl->Parent_item,NEWSubFamily_STR,TYPE_NEW_SubFamily,0,0,0,0);
		//加一个子
		AddTree(dl->item,NEWGenus_STR,TYPE_NEW_Genus,dl->sf,0,0,0);
#endif

	}
	else if(TYPE_NEW_Genus == dl->type)
	{
		//修改状态
		dl->type=TYPE_Genus;
		dl->ge=DBdata[dl->sf].GenusTotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,DBdata[curlist->sf].GenusData[curlist->ge].GE.Genus[language]);
#if 1
		memcpy(&tempdl,dl,sizeof(DATALIST));
		//加一个兄弟
		AddTree(tempdl.Parent_item,NEWGenus_STR,TYPE_NEW_Genus,tempdl.sf,0,0,0);
		//加一个子
		AddTree(tempdl.item,NEWName_STR,TYPE_NEW_Name,tempdl.sf,tempdl.ge,0,0);
#else
		//加一个兄弟
		AddTree(dl->Parent_item,NEWGenus_STR,TYPE_NEW_Genus,dl->sf,0,0,0);
		//加一个子
		AddTree(dl->item,NEWName_STR,TYPE_NEW_Name,dl->sf,dl->ge,0,0);
#endif
	}
	else if(TYPE_NEW_Name == dl->type)
	{
		//修改状态
		dl->type=TYPE_Name;
		dl->na=DBdata[dl->sf].GenusData[dl->ge].NameTotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Species[language]);
#if 1	
		memcpy(&tempdl,dl,sizeof(DATALIST));
		//加一个兄弟
		AddTree(tempdl.Parent_item,NEWName_STR,TYPE_NEW_Name,tempdl.sf,tempdl.ge,0,0);
		//加一个子
		AddTree(tempdl.item,NEWSpName_STR,TYPE_NEW_SpName,tempdl.sf,tempdl.ge,tempdl.na,0);
#else
		//加一个兄弟
		AddTree(dl->Parent_item,NEWName_STR,TYPE_NEW_Name,dl->sf,dl->ge,0,0);
		//加一个子
		AddTree(dl->item,NEWSpName_STR,TYPE_NEW_SpName,dl->sf,dl->ge,dl->na,0);
#endif
	}	
	else if(TYPE_NEW_SpName == dl->type)
	{
		//修改状态
		dl->type=TYPE_SpName;
		dl->sp=DBdata[dl->sf].GenusData[dl->ge].NameData[dl->na].SpTotal-1;
		//修改字符串
		m_tree.SetItemText(dl->item,	\
			DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp].Subspecies[language]);
#if 1	
		memcpy(&tempdl,dl,sizeof(DATALIST));
		//加一个兄弟
		AddTree(tempdl.Parent_item,NEWSpName_STR,TYPE_NEW_SpName,tempdl.sf,tempdl.ge,tempdl.na,0);
#else
		//加一个兄弟
		AddTree(dl->Parent_item,NEWSpName_STR,TYPE_NEW_SpName,dl->sf,dl->ge,dl->na,0);
#endif
	}
}

//在删除完数据之后调用  在调用之前判断NEW类型的不能删除
void CZogiiaddDlg::BuildDeleteTree(DATALIST *dl)
{
	ZOGII_LONG_TYPE i;

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
//移动树
void CZogiiaddDlg::BuildDeleteTreeMove(DATALIST *dl)
{
	ZOGII_LONG_TYPE i;
	
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
////////////////////////////////////////////////////////////////////////////////////////////
//初始化M 和临时数据
void CZogiiaddDlg::InitInfoData()
{
	ZOGII_ULONG_TYPE i;
	//初始化NEWDATA

	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
		NewImagodata[i].flag=0;

	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
		NewLarvadata[i].flag=0;

	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
		NewPupadata[i].flag=0;

	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
		NewOvumdata[i].flag=0;

	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
		NewCloseupdata[i].flag=0;

	memset(&Newdata,0,sizeof(struct ZOGII_Coccinellidae_DATA));

	m_ImagoNo = 0;
	m_LarvaNo = 0;
	m_PupaNo = 0;
	m_OvumNo = 0;
	m_CloseupNo = 0;

	//拷贝旧有数据到M
	if(TYPE_SubFamily == curlist->type)
	{
		CopyInfoDBData2M(&DBdata[curlist->sf].SF);

		ReadDB2Imago(&DBdata[curlist->sf].SF);
		ReadImago2M(m_ImagoNo);

		ReadDB2Larva(&DBdata[curlist->sf].SF);
		ReadLarva2M(m_LarvaNo);

		ReadDB2Pupa(&DBdata[curlist->sf].SF);
		ReadPupa2M(m_PupaNo);

		ReadDB2Ovum(&DBdata[curlist->sf].SF);
		ReadOvum2M(m_OvumNo);

		ReadDB2Closeup(&DBdata[curlist->sf].SF);
		ReadCloseup2M(m_CloseupNo);

		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_Genus == curlist->type)
	{
		CopyInfoDBData2M(&DBdata[curlist->sf].GenusData[curlist->ge].GE);

		ReadDB2Imago(&DBdata[curlist->sf].GenusData[curlist->ge].GE);
		ReadImago2M(m_ImagoNo);
		
		ReadDB2Larva(&DBdata[curlist->sf].GenusData[curlist->ge].GE);
		ReadLarva2M(m_LarvaNo);

		ReadDB2Pupa(&DBdata[curlist->sf].GenusData[curlist->ge].GE);
		ReadPupa2M(m_PupaNo);

		ReadDB2Ovum(&DBdata[curlist->sf].GenusData[curlist->ge].GE);
		ReadOvum2M(m_OvumNo);

		ReadDB2Closeup(&DBdata[curlist->sf].GenusData[curlist->ge].GE);
		ReadCloseup2M(m_CloseupNo);

		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_Name == curlist->type)
	{
		CopyInfoDBData2M(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);

		ReadDB2Imago(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);
		ReadImago2M(m_ImagoNo);
			
		ReadDB2Larva(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);
		ReadLarva2M(m_LarvaNo);

		ReadDB2Pupa(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);
		ReadPupa2M(m_PupaNo);

		ReadDB2Ovum(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);
		ReadOvum2M(m_OvumNo);

		ReadDB2Closeup(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA);
		ReadCloseup2M(m_CloseupNo);

		UpdateData(FALSE);
		return ;
	}
	else	if(TYPE_SpName == curlist->type)
	{
		CopyInfoDBData2M(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);

		ReadDB2Imago(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);
		ReadImago2M(m_ImagoNo);

		ReadDB2Larva(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);
		ReadLarva2M(m_LarvaNo);

		ReadDB2Pupa(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);
		ReadPupa2M(m_PupaNo);

		ReadDB2Ovum(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);
		ReadOvum2M(m_OvumNo);

		ReadDB2Closeup(&DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].SpData[curlist->sp]);
		ReadCloseup2M(m_CloseupNo);

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

		m_NameEN = DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Species[0];
		m_NameCN = DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Species[1];
		m_NameTW = DBdata[curlist->sf].GenusData[curlist->ge].NameData[curlist->na].NA.Species[2];
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

	m_Date = CTime::GetCurrentTime();
	m_Food = -1;

	m_FoodNameA = _T("");
	m_FoodNameB = _T("");
	m_FoodNameC = _T("");
	m_FoodNameD = _T("");

	m_LivingNameA = _T("");
	m_LivingNameB = _T("");
	m_LivingNameC = _T("");

	m_DiscoveryName = _T("");

	m_minsize = 0;
	m_maxsize = 0;

	m_Light = -1;
	m_Living = -1;
	m_ImagobellyColor = -1;
	m_ImagoVillus = -1;
	m_OverWinter = -1;

	CleanImago2M();
	CleanLarva2M();
	CleanPupa2M();
	CleanOvum2M();
	CleanCloseup2M();

	Newdata.DiscoverMapTotal=0;
	memset(Newdata.DiscoverMapList,0,ZOGII_DISCOVERY_MAX);

	UpdateData(FALSE);
	return ;
}
//将数据库信息拷贝到M
void CZogiiaddDlg::CopyInfoDBData2M(struct ZOGII_Coccinellidae_DATA* d)
{
	Newdata.code =d->code;
	memcpy(Newdata.Path,d->Path,ZOGII_PAT_MAX);
	m_code = d->code;
	m_path = d->Path;

	m_SubFamilyEN = d->SubFamily[0];
	m_SubFamilyCN = d->SubFamily[1];
	m_SubFamilyTW = d->SubFamily[2];

	m_GenusEN = d->Genus[0];
	m_GenusCN = d->Genus[1];
	m_GenusTW = d->Genus[2];
	
	m_NameEN = d->Species[0];
	m_NameCN = d->Species[1];
	m_NameTW = d->Species[2];

	m_SpNameEN = d->Subspecies[0];
	m_SpNameCN = d->Subspecies[1];
	m_SpNameTW = d->Subspecies[2];

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

	m_Date = CTime::GetCurrentTime();
	m_Food = d->FoodType;

	m_FoodNameA = d->FoodName[0];
	m_FoodNameB = d->FoodName[1];
	m_FoodNameC = d->FoodName[2];
	m_FoodNameD = d->FoodName[3];

	m_LivingNameA = d->LivingName[0];
	m_LivingNameB = d->LivingName[1];
	m_LivingNameC = d->LivingName[2];

	m_DiscoveryName = d->DiscoverName;

	m_minsize = d->MinSize;
	m_maxsize = d->MaxSize;
	m_Light = d->Light;
	m_Living = d->Living;
	m_ImagobellyColor = d->ImagobellyColor;
	m_ImagoVillus = d->ImagoVillus;
	m_OverWinter = d->OverWintering;

	//初始化
	if(255 == d->DiscoverMapTotal)
	{
		Newdata.DiscoverMapTotal=0;
		memset(Newdata.DiscoverMapList,0,ZOGII_DISCOVERY_MAX);
	}
	else
	{
		Newdata.DiscoverMapTotal= d->DiscoverMapTotal;
		memcpy(Newdata.DiscoverMapList,d->DiscoverMapList,ZOGII_DISCOVERY_MAX);
	}

	UpdateData(FALSE);
}
//将M拷贝到临时数据  必须按“保存本类信息” 才会保存到数据库
void CZogiiaddDlg::CopyInfoM2NewData()
{
	UpdateData(TRUE);

	Newdata.code = m_code;
	
	sprintf(Newdata.Path ,"%s",m_path.GetBuffer(0));

	sprintf(Newdata.SubFamily[0] , "%s", m_SubFamilyEN.GetBuffer(0)); 
	sprintf(Newdata.SubFamily[1] , "%s", m_SubFamilyCN.GetBuffer(0)); 
	sprintf(Newdata.SubFamily[2] , "%s", m_SubFamilyTW.GetBuffer(0)); 

	sprintf(Newdata.Genus[0] , "%s", m_GenusEN.GetBuffer(0)); 
	sprintf(Newdata.Genus[1] , "%s", m_GenusCN.GetBuffer(0)); 
	sprintf(Newdata.Genus[2] , "%s", m_GenusTW.GetBuffer(0)); 

	sprintf(Newdata.Species[0] , "%s", m_NameEN.GetBuffer(0)); 
	sprintf(Newdata.Species[1] , "%s", m_NameCN.GetBuffer(0)); 
	sprintf(Newdata.Species[2] , "%s", m_NameTW.GetBuffer(0)); 

	sprintf(Newdata.Subspecies[0] , "%s", m_SpNameEN.GetBuffer(0)); 
	sprintf(Newdata.Subspecies[1] , "%s", m_SpNameCN.GetBuffer(0)); 
	sprintf(Newdata.Subspecies[2] , "%s", m_SpNameTW.GetBuffer(0)); 

	sprintf(Newdata.Text[0] , "%s", m_TextENPath.GetBuffer(0)); 
	sprintf(Newdata.Text[1] , "%s", m_TextCNPath.GetBuffer(0)); 
	sprintf(Newdata.Text[2] , "%s", m_TextTWPath.GetBuffer(0)); 

	sprintf(Newdata.OtherName[0] , "%s", m_OtherNameA.GetBuffer(0)); 
	sprintf(Newdata.OtherName[1] , "%s", m_OtherNameB.GetBuffer(0)); 
	sprintf(Newdata.OtherName[2] , "%s", m_OtherNameC.GetBuffer(0)); 
	sprintf(Newdata.OtherName[3] , "%s", m_OtherNameD.GetBuffer(0)); 
	sprintf(Newdata.OtherName[4] , "%s", m_OtherNameE.GetBuffer(0)); 
	sprintf(Newdata.OtherName[5] , "%s", m_OtherNameF.GetBuffer(0)); 
	sprintf(Newdata.OtherName[6] , "%s", m_OtherNameG.GetBuffer(0)); 
	Newdata.year=(char)(m_Date.GetYear()-2000);
	Newdata.month=(char)m_Date.GetMonth();
	Newdata.day=(char)m_Date.GetDay();

	Newdata.FoodType =(char)m_Food; 

	sprintf(Newdata.FoodName[0] , "%s" , m_FoodNameA.GetBuffer(0)); 
	sprintf(Newdata.FoodName[1] , "%s" , m_FoodNameB.GetBuffer(0)); 
	sprintf(Newdata.FoodName[2] , "%s" , m_FoodNameC.GetBuffer(0)); 
	sprintf(Newdata.FoodName[3] , "%s" , m_FoodNameD.GetBuffer(0)); 
	sprintf(Newdata.LivingName[0] , "%s" , m_LivingNameA.GetBuffer(0)); 
	sprintf(Newdata.LivingName[1] , "%s" , m_LivingNameB.GetBuffer(0)); 
	sprintf(Newdata.LivingName[2] , "%s" , m_LivingNameC.GetBuffer(0)); 

	sprintf(Newdata.DiscoverName ,"%s" , m_DiscoveryName.GetBuffer(0)); 

	Newdata.MinSize=(char)m_minsize;
	Newdata.MaxSize=(char)m_maxsize;

	Newdata.Light=	(char)m_Light;
	Newdata.Living=	(char)m_Living ;
	Newdata.ImagobellyColor=(char)m_ImagobellyColor;
	Newdata.ImagoVillus=	(char)m_ImagoVillus;
	Newdata.OverWintering=	(char)m_OverWinter;

}

////////////////////Imago////////////////////////////////////////////////////////
//清除M
void CZogiiaddDlg::CleanImago2M()
{
	m_ImagoElytraColorA = -1;
	m_ImagoElytraColorB = -1;
	m_ImagoElytraColorC = -1;
	m_ImagoElytraColorD = -1;
	m_ImagoElytraColorNum = -1;
	m_ImagoSex = -1;
	m_ImagoElytraTexture = -1;

	m_ImagoPicPath = _T("");
	m_ImagoPicInfo = _T("");
	//ex
	m_ImagoElytraPointNum = -1;
	m_ImagoPronotumColorA = -1;
	m_ImagoPronotumColorB = -1;
	m_ImagoPronotumColorC = -1;
	m_ImagoPronotumColorD = -1;
	m_ImagoPronotumColorNum = -1;
	m_ImagoPronotumPointNum = -1;
	m_ImagoPronotumTexture = -1;
}

//M到临时数据 必须按“保存本类信息” 才会保存到数据库
void CZogiiaddDlg::SaveM2Imago(int i)
{
	if(i<0)
		return ;

	//为空
	if(m_ImagoPicPath.IsEmpty())
	{
		NewImagodata[i].flag=0;
		CleanImago2M();
		UpdateData(FALSE);
	}
	else	//不为空 
	{
		sprintf(NewImagodata[i].Path,"%s",m_ImagoPicPath.GetBuffer(0));
		sprintf(NewImagodata[i].Info,"%s",m_ImagoPicInfo.GetBuffer(0));

		NewImagodata[i].flag=1;
	}

	NewImagodata[i].ElytraColorNum =	(char)m_ImagoElytraColorNum;
	NewImagodata[i].ElytraColor[0] = (char)m_ImagoElytraColorA;
	NewImagodata[i].ElytraColor[1] =	(char)m_ImagoElytraColorB;
	NewImagodata[i].ElytraColor[2] =	(char)m_ImagoElytraColorC;
	NewImagodata[i].ElytraColor[3] =	(char)m_ImagoElytraColorD;
	NewImagodata[i].ElytraTexture = (char)m_ImagoElytraTexture;
	NewImagodata[i].Sex = (char)m_ImagoSex;

	NewImagodata[i].ElytraPointNum =	(char)m_ImagoElytraPointNum;
	NewImagodata[i].PronotumColor[0] = (char)m_ImagoPronotumColorA;
	NewImagodata[i].PronotumColor[1] =	(char)m_ImagoPronotumColorB;
	NewImagodata[i].PronotumColor[2] =	(char)m_ImagoPronotumColorC;
	NewImagodata[i].PronotumColor[3] =	(char)m_ImagoPronotumColorD;
	NewImagodata[i].PronotumColorNum = (char)m_ImagoPronotumColorNum;
	NewImagodata[i].PronotumPointNum =	(char)m_ImagoPronotumPointNum;
	NewImagodata[i].PronotumTexture =	(char)m_ImagoPronotumTexture;
}
//临时数据到M
void CZogiiaddDlg::ReadImago2M(int i)
{
	if(i<0)
		return ;
	//颜色数必须大于0
	if(NewImagodata[i].flag)
	{
		m_ImagoElytraColorNum = NewImagodata[i].ElytraColorNum;
		m_ImagoElytraColorA = NewImagodata[i].ElytraColor[0];
		m_ImagoElytraColorB = NewImagodata[i].ElytraColor[1];
		m_ImagoElytraColorC = NewImagodata[i].ElytraColor[2];
		m_ImagoElytraColorD = NewImagodata[i].ElytraColor[3];
		m_ImagoElytraTexture = NewImagodata[i].ElytraTexture;
		m_ImagoSex = NewImagodata[i].Sex;
		
		m_ImagoPicPath = NewImagodata[i].Path;
		m_ImagoPicInfo = NewImagodata[i].Info;

		m_ImagoElytraPointNum = NewImagodata[i].ElytraPointNum;
		m_ImagoPronotumColorA = NewImagodata[i].PronotumColor[0];
		m_ImagoPronotumColorB = NewImagodata[i].PronotumColor[1];
		m_ImagoPronotumColorC = NewImagodata[i].PronotumColor[2];
		m_ImagoPronotumColorD = NewImagodata[i].PronotumColor[3];
		m_ImagoPronotumColorNum=NewImagodata[i].PronotumColorNum;
		m_ImagoPronotumPointNum=NewImagodata[i].PronotumPointNum;
		m_ImagoPronotumTexture=NewImagodata[i].PronotumTexture;

	}
	else	if(0==i)
		CleanImago2M();
	else
		m_ImagoPicPath = _T("");

}
//读取数据库到临时数据
void CZogiiaddDlg::ReadDB2Imago(struct ZOGII_Coccinellidae_DATA* d)
{
	ZOGII_ULONG_TYPE i;

	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
		memcpy(&(NewImagodata[i]),&(DBImagodata[d->Imago[i]]),sizeof(struct ZOGII_Imago));
}

////////////////////Larva////////////////////////////////////////////////////////
//清除M
void CZogiiaddDlg::CleanLarva2M()
{
	m_LarvaColorA = -1;
	m_LarvaColorB = -1;
	m_LarvaColorC = -1;
	m_LarvaColorD = -1;
	m_LarvaColorNum = -1;
	m_LarvaInstar = -1;
	m_LarvaCalthrop = -1;
	m_LarvaSex = -1;
	m_LarvaPicPath = _T("");
	m_LarvaPicInfo = _T("");
}

//M到临时数据 必须按“保存本类信息” 才会保存到数据库
void CZogiiaddDlg::SaveM2Larva(int i)
{
	if(i<0)
		return ;

	//为空
	if(m_LarvaPicPath.IsEmpty())
	{
		NewLarvadata[i].flag=0;
		CleanLarva2M();
		UpdateData(FALSE);
	}
	else	//不为空 
	{
		sprintf(NewLarvadata[i].Path,"%s",m_LarvaPicPath.GetBuffer(0));
		sprintf(NewLarvadata[i].Info,"%s",m_LarvaPicInfo.GetBuffer(0));

		NewLarvadata[i].flag=1;
	}
	
	NewLarvadata[i].ColorNum =	(char)m_LarvaColorNum;
	NewLarvadata[i].Color[0] = (char)m_LarvaColorA;
	NewLarvadata[i].Color[1] =	(char)m_LarvaColorB;
	NewLarvadata[i].Color[2] =	(char)m_LarvaColorC;
	NewLarvadata[i].Color[3] =	(char)m_LarvaColorD;
	NewLarvadata[i].Sex = (char)m_LarvaSex;
	NewLarvadata[i].Instar = (char)m_LarvaInstar;
	NewLarvadata[i].Calthrop = (char)m_LarvaCalthrop;
}
//临时数据到M
void CZogiiaddDlg::ReadLarva2M(int i)
{
	if(i<0)
		return ;
	//必须有图片
	if(NewLarvadata[i].flag)
	{
		m_LarvaColorNum = NewLarvadata[i].ColorNum;
		m_LarvaColorA = NewLarvadata[i].Color[0];
		m_LarvaColorB = NewLarvadata[i].Color[1];
		m_LarvaColorC = NewLarvadata[i].Color[2];
		m_LarvaColorD = NewLarvadata[i].Color[3];
		m_LarvaSex = NewLarvadata[i].Sex;
		m_LarvaInstar = NewLarvadata[i].Instar;
		m_LarvaCalthrop =	NewLarvadata[i].Calthrop;
	
		m_LarvaPicPath = NewLarvadata[i].Path;
		m_LarvaPicInfo = NewLarvadata[i].Info;
	}
	else	if(0==i)
		CleanLarva2M();
	else
		m_LarvaPicPath = _T("");

}
//读取数据库到临时数据
void CZogiiaddDlg::ReadDB2Larva(struct ZOGII_Coccinellidae_DATA* d)
{
	ZOGII_ULONG_TYPE i;

	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
		memcpy(&(NewLarvadata[i]),&(DBLarvadata[d->Larva[i]]),sizeof(struct ZOGII_Larva));
}

////////////////////Pupa////////////////////////////////////////////////////////
//清除M
void CZogiiaddDlg::CleanPupa2M()
{
	m_PupaColorA = -1;
	m_PupaColorB = -1;
	m_PupaColorC = -1;
	m_PupaColorD = -1;
	m_PupaColorNum = -1;
	m_PupaSex = -1;
	m_PupaPicPath = _T("");
	m_PupaPicInfo = _T("");
	m_PupaType = -1;
}

//M到临时数据 必须按“保存本类信息” 才会保存到数据库
void CZogiiaddDlg::SaveM2Pupa(int i)
{
	if(i<0)
		return ;

	//为空
	if(m_PupaPicPath.IsEmpty())
	{
		NewPupadata[i].flag=0;
		CleanPupa2M();
		UpdateData(FALSE);
	}
	else	//不为空 
	{
		sprintf(NewPupadata[i].Path,"%s",m_PupaPicPath.GetBuffer(0));
		sprintf(NewPupadata[i].Info,"%s",m_PupaPicInfo.GetBuffer(0));

		NewPupadata[i].flag=1;
	}

	NewPupadata[i].ColorNum =	(char)m_PupaColorNum;
	NewPupadata[i].Color[0] = (char)m_PupaColorA;
	NewPupadata[i].Color[1] =	(char)m_PupaColorB;
	NewPupadata[i].Color[2] =	(char)m_PupaColorC;
	NewPupadata[i].Color[3] =	(char)m_PupaColorD;
	NewPupadata[i].Sex = (char)m_PupaSex;
	NewPupadata[i].Type = (char)m_PupaType;
}
//临时数据到M
void CZogiiaddDlg::ReadPupa2M(int i)
{
	if(i<0)
		return ;
	//必须有图片
	if(NewPupadata[i].flag)
	{
		m_PupaColorNum = NewPupadata[i].ColorNum;
		m_PupaColorA = NewPupadata[i].Color[0];
		m_PupaColorB = NewPupadata[i].Color[1];
		m_PupaColorC = NewPupadata[i].Color[2];
		m_PupaColorD = NewPupadata[i].Color[3];
		m_PupaSex = NewPupadata[i].Sex;
		m_PupaType =	NewPupadata[i].Type;

		m_PupaPicPath = NewPupadata[i].Path;
		m_PupaPicInfo = NewPupadata[i].Info;
	}
	else	if(0==i)
		CleanPupa2M();
	else
		m_PupaPicPath = _T("");
}

//读取数据库到临时数据
void CZogiiaddDlg::ReadDB2Pupa(struct ZOGII_Coccinellidae_DATA* d)
{
	ZOGII_ULONG_TYPE i;

	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
		memcpy(&(NewPupadata[i]),&(DBPupadata[d->Pupa[i]]),sizeof(struct ZOGII_Pupa));
}

////////////////////Ovum////////////////////////////////////////////////////////
//清除M
void CZogiiaddDlg::CleanOvum2M()
{
	m_OvumColor = -1;
	m_OvumSex = -1;
	m_OvumPicPath = _T("");
	m_OvumPicInfo = _T("");
}

//M到临时数据 必须按“保存本类信息” 才会保存到数据库
void CZogiiaddDlg::SaveM2Ovum(int i)
{
	if(i<0)
		return ;
	//为空
	if(m_OvumPicPath.IsEmpty())
	{
		NewOvumdata[i].flag=0;
		CleanOvum2M();
		UpdateData(FALSE);
	}
	else	//不为空 
	{
		sprintf(NewOvumdata[i].Path,"%s",m_OvumPicPath.GetBuffer(0));
		sprintf(NewOvumdata[i].Info,"%s",m_OvumPicInfo.GetBuffer(0));

		NewOvumdata[i].flag=1;
	}
	
	NewOvumdata[i].Color =	(char)m_OvumColor;
	NewOvumdata[i].Sex = (char)m_OvumSex;
}
//临时数据到M
void CZogiiaddDlg::ReadOvum2M(int i)
{
	if(i<0)
		return ;

	if(NewOvumdata[i].flag)
	{
		m_OvumColor = NewOvumdata[i].Color;
		m_OvumSex = NewOvumdata[i].Sex;
		m_OvumPicPath = NewOvumdata[i].Path;
		m_OvumPicInfo = NewOvumdata[i].Info;
	}
	else	if(0==i)
		CleanOvum2M();
	else
		m_OvumPicPath = _T("");

}
//读取数据库到临时数据
void CZogiiaddDlg::ReadDB2Ovum(struct ZOGII_Coccinellidae_DATA* d)
{
	ZOGII_ULONG_TYPE i;

	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
		memcpy(&(NewOvumdata[i]),&(DBOvumdata[d->Ovum[i]]),sizeof(struct ZOGII_Ovum));
}

////////////////////Closeup////////////////////////////////////////////////////////
//清除M
void CZogiiaddDlg::CleanCloseup2M()
{
	m_CloseupType = -1;
	m_CloseupPicPath = _T("");
	m_CloseupPicInfo = _T("");
}

//M到临时数据 必须按“保存本类信息” 才会保存到数据库
void CZogiiaddDlg::SaveM2Closeup(int i)
{
	if(i<0)
		return ;
	//为空
	if(m_CloseupPicPath.IsEmpty())
	{
		NewCloseupdata[i].flag=0;
		CleanCloseup2M();
		UpdateData(FALSE);
	}
	else	//不为空 
	{
		sprintf(NewCloseupdata[i].Path,"%s",m_CloseupPicPath.GetBuffer(0));
		sprintf(NewCloseupdata[i].Info,"%s",m_CloseupPicInfo.GetBuffer(0));

		NewCloseupdata[i].flag=1;
	}
	
	NewCloseupdata[i].Type =	(char)m_CloseupType ;

}
//临时数据到M
void CZogiiaddDlg::ReadCloseup2M(int i)
{
	if(i<0)
		return ;

	if(NewCloseupdata[i].flag)
	{
 		m_CloseupType=NewCloseupdata[i].Type ;

		m_CloseupPicPath = NewCloseupdata[i].Path;
		m_CloseupPicInfo = NewCloseupdata[i].Info;
	}
	else	if(0==i)
		CleanCloseup2M();
	else
		m_CloseupPicPath = _T("");

}
//读取数据库到临时数据
void CZogiiaddDlg::ReadDB2Closeup(struct ZOGII_Coccinellidae_DATA* d)
{
	ZOGII_ULONG_TYPE i;

	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
		memcpy(&(NewCloseupdata[i]),&(DBCloseupdata[d->Closeup[i]]),sizeof(struct ZOGII_Closeup));
}

///////////////////////////////////////////////////////////////////////////////////////////
void CZogiiaddDlg::OnButtonDataout() 
{
	// TODO: Add your control notification handler code here
	FILE *fp;
	char str[ZOGII_PAT_MAX];
	sprintf(str,"%s\\data.temp",CurrentDir);
	fp=fopen(str,"wb");
	if(fp)
	{
		UpdateData(TRUE);
		CopyInfoM2NewData();

		fwrite(NewImagodata,sizeof(struct ZOGII_Imago),ZOGII_PIC_Imago_MAX,fp);
		fwrite(NewLarvadata,sizeof(struct ZOGII_Larva),ZOGII_PIC_Larva_MAX,fp);
		fwrite(NewPupadata,sizeof(struct ZOGII_Pupa),ZOGII_PIC_Pupa_MAX,fp);
		fwrite(NewOvumdata,sizeof(struct ZOGII_Ovum),ZOGII_PIC_Ovum_MAX,fp);
		fwrite(NewCloseupdata,sizeof(struct ZOGII_Closeup),ZOGII_PIC_Closeup_MAX,fp);

		fwrite(&Newdata,sizeof(struct ZOGII_Coccinellidae_DATA),1,fp);

		fclose(fp);
		MessageBox(_T("导出成功"), _T("导出"));
	}
}

void CZogiiaddDlg::OnButtonDatain() 
{
	// TODO: Add your control notification handler code here
	FILE *fp;
	char str[ZOGII_PAT_MAX];
	sprintf(str,"%s\\data.temp",CurrentDir);
	fp=fopen(str,"rb");
	if(fp)
	{
		fread(NewImagodata,sizeof(struct ZOGII_Imago),ZOGII_PIC_Imago_MAX,fp);
		fread(NewLarvadata,sizeof(struct ZOGII_Larva),ZOGII_PIC_Larva_MAX,fp);
		fread(NewPupadata,sizeof(struct ZOGII_Pupa),ZOGII_PIC_Pupa_MAX,fp);
		fread(NewOvumdata,sizeof(struct ZOGII_Ovum),ZOGII_PIC_Ovum_MAX,fp);
		fread(NewCloseupdata,sizeof(struct ZOGII_Closeup),ZOGII_PIC_Closeup_MAX,fp);

		fread(&Newdata,sizeof(struct ZOGII_Coccinellidae_DATA),1,fp);

		fclose(fp);
		
		zogiiAddSaveDB(&DBtotal,DBdata,
			&DBImagototal,DBImagodata,
			&DBLarvatotal,DBLarvadata,
			&DBPupatotal,DBPupadata,
			&DBOvumtotal,DBOvumdata,
			&DBCloseuptotal,DBCloseupdata,
			curlist->type,curlist->sf,curlist->ge,curlist->na,curlist->sp,
			&Newdata,
			NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata);
		
		BuildNewTree(curlist);
		
		UpdateData(FALSE);
		//再导入一次 为了导入图像数据
		zogiiAddSaveDB(&DBtotal,DBdata,
			&DBImagototal,DBImagodata,
			&DBLarvatotal,DBLarvadata,
			&DBPupatotal,DBPupadata,
			&DBOvumtotal,DBOvumdata,
			&DBCloseuptotal,DBCloseupdata,
			curlist->type,curlist->sf,curlist->ge,curlist->na,curlist->sp,
			&Newdata,
			NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata);

		BuildNewTree(curlist);

		UpdateData(FALSE);

		MessageBox(_T("导入成功"), _T("导入"));
	}
}

void CZogiiaddDlg::OnButtonDiscoverymap() 
{
	// TODO: Add your control notification handler code here
	CDLGmap map;
	map.SetListDst(Newdata.DiscoverMapList,&(Newdata.DiscoverMapTotal));
	map.DoModal();
	
	char str[10];
	sprintf(str,"%d",Newdata.DiscoverMapTotal);
	GetDlgItem(IDC_STATIC_DISCOVERTOTAL)->SetWindowText(str);
}

void CZogiiaddDlg::OnButtonTreeout() 
{
	// TODO: Add your control notification handler code here
	if(zogiiPrintfDB(DBtotal,DBdata))
		MessageBox(_T("印树成功"), _T("印树"));
	else
		MessageBox(_T("印树失败"), _T("印树"));
}
///////////////////////////////////////////////////////////////////////////////////////////
void CZogiiaddDlg::OnBUTTONNEWImago() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
	{
		if(0==NewImagodata[i].flag)
		{
			m_ImagoNo=i;
			ReadImago2M(m_ImagoNo);
			UpdateData(FALSE);
			return ;
		}
	}

	MessageBox(_T("已满"), _T("图片"));
}


void CZogiiaddDlg::OnBUTTONNEWLarva() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
	{
		if(0==NewLarvadata[i].flag)
		{
			m_LarvaNo=i;
			ReadLarva2M(m_LarvaNo);
			UpdateData(FALSE);
			return ;
		}
	}

	MessageBox(_T("已满"), _T("图片"));
}

void CZogiiaddDlg::OnBUTTONNEWCloseup() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
	{
		if(0==NewCloseupdata[i].flag)
		{
			m_CloseupNo=i;
			ReadCloseup2M(m_CloseupNo);
			UpdateData(FALSE);
			return ;
		}
	}

	MessageBox(_T("已满"), _T("图片"));
}

void CZogiiaddDlg::OnBUTTONNEWOvum() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
	{
		if(0==NewOvumdata[i].flag)
		{
			m_OvumNo=i;
			ReadOvum2M(m_OvumNo);
			UpdateData(FALSE);
			return ;
		}
	}

	MessageBox(_T("已满"), _T("图片"));
}

void CZogiiaddDlg::OnBUTTONNEWPupa() 
{
	// TODO: Add your control notification handler code here
	int i;
	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
	{
		if(0==NewPupadata[i].flag)
		{
			m_PupaNo=i;
			ReadPupa2M(m_PupaNo);
			UpdateData(FALSE);
			return ;
		}
	}

	MessageBox(_T("已满"), _T("图片"));
}


void CZogiiaddDlg::OnButtonFastmap() 
{
	// TODO: Add your control notification handler code here
	int i;
	unsigned char v=60;
	//找重复
	for(i=0;i<Newdata.DiscoverMapTotal;i++)
	{
		if(v==Newdata.DiscoverMapList[i])
			break;
	}
	//找不到
	if(i==Newdata.DiscoverMapTotal)
	{
		Newdata.DiscoverMapList[Newdata.DiscoverMapTotal]=v;
		Newdata.DiscoverMapTotal++;
	}

	char str[32];
	sprintf(str,"%d",Newdata.DiscoverMapTotal);
	GetDlgItem(IDC_STATIC_DISCOVERTOTAL)->SetWindowText(str);
}

void CZogiiaddDlg::OnButtonFaststr() 
{
	// TODO: Add your control notification handler code here
	char *str="www.saveourwaterwaysnow.com.au";

	GetDlgItem(IDC_EDIT_ImagoPicInfo)->SetWindowText(str);
	GetDlgItem(IDC_EDIT_PupaPicInfo)->SetWindowText(str);
	GetDlgItem(IDC_EDIT_CloseupPicInfo)->SetWindowText(str);
	GetDlgItem(IDC_EDIT_OvumPicInfo)->SetWindowText(str);
	GetDlgItem(IDC_EDIT_LarvaPicInfo)->SetWindowText(str);
}

void CZogiiaddDlg::OnCustomdrawSliderMaxsize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CSliderCtrl* sliderctrl;

	sliderctrl=(CSliderCtrl*)GetDlgItem(IDC_SLIDER_MAXSIZE);
	int p= sliderctrl->GetPos(); 
	char str[8];
	sprintf(str,"%d mm",p);
	GetDlgItem(IDC_STATIC_MAXSIZE)->SetWindowText(str);
	*pResult = 0;
}

void CZogiiaddDlg::OnCustomdrawSliderMinsize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CSliderCtrl* sliderctrl;

	sliderctrl=(CSliderCtrl*)GetDlgItem(IDC_SLIDER_MINSIZE);
	int p= sliderctrl->GetPos(); 
	char str[8];
	sprintf(str,"%d mm",p);
	GetDlgItem(IDC_STATIC_MINSIZE)->SetWindowText(str);

	*pResult = 0;
}
