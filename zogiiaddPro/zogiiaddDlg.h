// zogiiaddDlg.h : header file
//

#if !defined(AFX_ZOGIIADDDLG_H__096C0B0E_E5CC_41EA_A1B6_05467B4FDF0D__INCLUDED_)
#define AFX_ZOGIIADDDLG_H__096C0B0E_E5CC_41EA_A1B6_05467B4FDF0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "zogiidb.h"

/////////////////////////////////////////////////////////////////////////////
// CZogiiaddDlg dialog
typedef struct 
{
	HTREEITEM Parent_item; //父指针
	HTREEITEM item; //本指针
	
	// 0=无效 1=有效
	unsigned char flag;
	unsigned char type;

	//数据指针
	ZOGII_ULONG_TYPE sf;
	ZOGII_ULONG_TYPE ge;
	ZOGII_ULONG_TYPE sp;
	ZOGII_ULONG_TYPE ssp;

}DATALIST;


class CZogiiaddDlg : public CDialog
{
// Construction
public:
	CZogiiaddDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZogiiaddDlg)
	enum { IDD = IDD_ZOGIIADD_DIALOG };
	CTreeCtrl	m_tree;
	CString	m_SubFamilyEN;
	CString	m_SpNameTW;
	CString	m_SpNameEN;
	CString	m_SpNameCN;
	CString	m_SubFamilyCN;
	CString	m_SubFamilyTW;
	CString	m_TextCNPath;
	CString	m_TextENPath;
	CString	m_TextTWPath;
	CString	m_PupaPicPath;
	CString	m_PupaPicInfo;
	CString	m_OvumPicPath;
	CString	m_OvumPicInfo;
	CString	m_OtherNameA;
	CString	m_OtherNameB;
	CString	m_OtherNameC;
	CString	m_OtherNameD;
	CString	m_OtherNameE;
	CString	m_OtherNameF;
	CString	m_NameCN;
	CString	m_NameEN;
	CString	m_NameTW;
	CString	m_LarvaPicPath;
	CString	m_LarvaPicInfo;
	CString	m_ImagoPicPath;
	CString	m_ImagoPicInfo;
	CTime	m_Date;
	CString	m_GenusTW;
	CString	m_GenusEN;
	CString	m_GenusCN;
	CString	m_FoodNameD;
	CString	m_FoodNameC;
	CString	m_FoodNameB;
	CString	m_FoodNameA;
	CString	m_DiscoveryName;
	int		m_Food;
	int		m_ImagoNo;
	int		m_ImagoSex;
	int		m_ImagoVillus;
	int		m_LarvaCalthrop;
	int		m_LarvaColorA;
	int		m_LarvaColorB;
	int		m_LarvaColorC;
	int		m_LarvaColorD;
	int		m_LarvaColorNum;
	int		m_LarvaInstar;
	int		m_LarvaNo;
	int		m_LarvaSex;
	int		m_OvumColor;
	int		m_OvumNo;
	int		m_OvumSex;
	int		m_PupaColorA;
	int		m_PupaColorB;
	int		m_PupaColorC;
	int		m_PupaColorD;
	int		m_PupaColorNum;
	int		m_PupaNo;
	int		m_PupaSex;
	CString	m_OtherNameG;
	UINT	m_code;
	CString	m_path;
	int		m_ImagoElytraColorA;
	int		m_ImagoElytraColorB;
	int		m_ImagoElytraColorC;
	int		m_ImagoElytraColorD;
	int		m_ImagoElytraColorNum;
	int		m_ImagoElytraTexture;
	int		m_ImagoPronotumColorA;
	int		m_ImagoPronotumColorB;
	int		m_ImagoPronotumColorC;
	int		m_ImagoPronotumColorD;
	int		m_ImagoPronotumColorNum;
	int		m_ImagoPronotumPointNum;
	int		m_ImagoPronotumTexture;
	int		m_ImagoElytraPointNum;
	int		m_ImagobellyColor;
	int		m_Light;
	int		m_Living;
	CString	m_LivingNameB;
	CString	m_LivingNameA;
	CString	m_LivingNameC;
	int		m_PupaType;
	int		m_OverWinter;
	int		m_CloseupNo;
	int		m_CloseupType;
	CString	m_CloseupPicInfo;
	CString	m_CloseupPicPath;
	int		m_minsize;
	int		m_maxsize;
	CString	m_search;
	int		m_codeSearchSF;
	int		m_codeSearchGE;
	int		m_codeSearchSP;
	int		m_codeSearchSSP;
	int		m_Contour;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZogiiaddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZogiiaddDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONDeleteData();
	afx_msg void OnBUTTONSaveData();
	afx_msg void OnBUTTONTextTWPath();
	afx_msg void OnBUTTONTextTWView();
	afx_msg void OnBUTTONTextCNPath();
	afx_msg void OnBUTTONTextCNView();
	afx_msg void OnBUTTONTextENPath();
	afx_msg void OnBUTTONTextENView();
	afx_msg void OnBUTTONImagoPicView();
	afx_msg void OnBUTTONImagoPicPath();
	afx_msg void OnBUTTONSaveImago();
	afx_msg void OnBUTTONDeleteImago();
	afx_msg void OnBUTTONLarvaPicView();
	afx_msg void OnBUTTONLarvaPicPath();
	afx_msg void OnBUTTONDeleteLarva();
	afx_msg void OnBUTTONSaveLarva();
	afx_msg void OnBUTTONOvumPicView();
	afx_msg void OnBUTTONOvumPicPath();
	afx_msg void OnBUTTONSaveOvum();
	afx_msg void OnBUTTONDeleteOvum();
	afx_msg void OnBUTTONPupaPicPath();
	afx_msg void OnBUTTONPupaPicView();
	afx_msg void OnBUTTONSavePupa();
	afx_msg void OnBUTTONDeletePupa();
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONSaveDB();
	afx_msg void OnCloseupCOMBOImagoNo();
	afx_msg void OnCloseupCOMBOLarvaNo();
	afx_msg void OnCloseupCOMBOOvumNo();
	afx_msg void OnCloseupCOMBOPupaNo();
	afx_msg void OnBUTTONOpenPath();
	afx_msg void OnBUTTONCloseupPicPath();
	afx_msg void OnBUTTONCloseupPicView();
	afx_msg void OnBUTTONSaveCloseup();
	afx_msg void OnBUTTONDeleteCloseup();
	afx_msg void OnCloseupCOMBOCloseupNo();
	afx_msg void OnButtonDataout();
	afx_msg void OnButtonDatain();
	afx_msg void OnButtonDiscoverymap();
	afx_msg void OnButtonTreeout();
	afx_msg ZOGII_ULONG_TYPE OnBUTTONNEWImago();
	afx_msg ZOGII_ULONG_TYPE OnBUTTONNEWLarva();
	afx_msg ZOGII_ULONG_TYPE OnBUTTONNEWCloseup();
	afx_msg ZOGII_ULONG_TYPE OnBUTTONNEWOvum();
	afx_msg ZOGII_ULONG_TYPE OnBUTTONNEWPupa();
	afx_msg void OnButtonFastmap();
	afx_msg void OnButtonFaststr();
	afx_msg void OnCustomdrawSliderMaxsize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawSliderMinsize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonSortsavedb();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonCodesearch();
	afx_msg void OnButtonMerge();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	void OnOK();
	/////////////////////////////////////////////////////////////////
//	int SaveToFile(int idc);
	int OpenToPicFile(int idc);
	int OpenToTxtFile(int idc);
	int SaveToDir(int idc);
	void ViewText(CString filename);
	void ViewPic(CString filename);
	/////////////////////////////
	void AddListBuf();
	HTREEITEM AddTree(HTREEITEM parent,char *str,	\
								unsigned char type,ZOGII_LONG_TYPE sf,ZOGII_LONG_TYPE ge,ZOGII_LONG_TYPE sp,ZOGII_LONG_TYPE ssp);
	void BuildTree();
	void BuildNewTree(DATALIST * dl);
	void BuildDeleteTree(DATALIST *dl);
	void BuildDeleteTreeMove(DATALIST *dl);
	/////////////////////////////
	void InitInfoData();
	void CopyInfoDBData2M(struct ZOGII_Coccinellidae_DATA* d);
	void CopyInfoM2NewData();
	/////////////////////////////
	void CleanImago2M();
	void SaveM2Imago(int i);
	void ReadImago2M(int i);
	void ReadDB2Imago(struct ZOGII_Coccinellidae_DATA* d);
	/////////////////////////////
	void CleanLarva2M();
	void SaveM2Larva(int i);
	void ReadLarva2M(int i);
	void ReadDB2Larva(struct ZOGII_Coccinellidae_DATA* d);
	/////////////////////////////
	void CleanPupa2M();
	void SaveM2Pupa(int i);
	void ReadPupa2M(int i);
	void ReadDB2Pupa(struct ZOGII_Coccinellidae_DATA* d);
	/////////////////////////////
	void CleanOvum2M();
	void SaveM2Ovum(int i);
	void ReadOvum2M(int i);
	void ReadDB2Ovum(struct ZOGII_Coccinellidae_DATA* d);
	/////////////////////////////
	void CleanCloseup2M();
	void SaveM2Closeup(int i);
	void ReadCloseup2M(int i);
	void ReadDB2Closeup(struct ZOGII_Coccinellidae_DATA* d);
	/////////////////////////////////////////////////////////////////
	void OnButtonFastmapLite(unsigned char v);


	char CurrentDir[ZOGII_PAT_MAX];
	//设定树语言 
	// 0 =英语 拉丁 
	// 1 =中文简体
	// 2 =中文繁体	
	unsigned char language;
	//树
	ZOGII_LONG_TYPE ListTotal;
	ZOGII_LONG_TYPE ListbufTotal;
	DATALIST *DataList;
	//选择的树选项
	DATALIST *curlist;
	//临时 //防止删除树出错
	DATALIST templist;

	//数据
	ZOGII_ULONG_TYPE DBtotal;
	struct ZOGII_Coccinellidae_SUBFamily *DBdata;

	ZOGII_ULONG_TYPE DBImagototal;
	struct ZOGII_Imago *DBImagodata;

	ZOGII_ULONG_TYPE DBLarvatotal;
	struct ZOGII_Larva *DBLarvadata;

	ZOGII_ULONG_TYPE DBPupatotal;
	struct ZOGII_Pupa *DBPupadata;

	ZOGII_ULONG_TYPE DBOvumtotal;
	struct ZOGII_Ovum *DBOvumdata;

	ZOGII_ULONG_TYPE DBCloseuptotal;
	struct ZOGII_Closeup *DBCloseupdata;

	//临时数据
	struct ZOGII_Imago NewImagodata[ZOGII_PIC_Imago_MAX]; 
	struct ZOGII_Larva NewLarvadata[ZOGII_PIC_Larva_MAX]; 
	struct ZOGII_Pupa NewPupadata[ZOGII_PIC_Pupa_MAX]; 
	struct ZOGII_Ovum NewOvumdata[ZOGII_PIC_Ovum_MAX]; 
	struct ZOGII_Closeup NewCloseupdata[ZOGII_PIC_Closeup_MAX]; 

	struct ZOGII_Coccinellidae_DATA Newdata;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGIIADDDLG_H__096C0B0E_E5CC_41EA_A1B6_05467B4FDF0D__INCLUDED_)
