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
	HTREEITEM Parent_item; //��ָ��
	HTREEITEM item; //��ָ��
	
	// 0=��Ч 1=��Ч
	unsigned char flag;
	unsigned char type;

	//����ָ��
	ZOGII_ULONG_TYPE sf;
	ZOGII_ULONG_TYPE ge;
	ZOGII_ULONG_TYPE na;
	ZOGII_ULONG_TYPE sp;

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
	CString	m_DiscoveryPicPath;
	CString	m_DiscoveryPicInfo;
	CString	m_DiscoveryName;
	CString	m_DataOutputPath;
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
	int		m_Size;
	int		m_Light;
	int		m_Living;
	CString	m_LivingNameB;
	CString	m_LivingNameA;
	CString	m_LivingNameC;
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
	afx_msg void OnBUTTONDiscoveryPicPath();
	afx_msg void OnBUTTONDiscoveryPicView();
	afx_msg void OnBUTTONDeleteData();
	afx_msg void OnBUTTONSaveData();
	afx_msg void OnBUTTONDataOutputPath();
	afx_msg void OnBUTTONDataOutput();
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
								unsigned char type,ZOGII_LONG_TYPE sf,ZOGII_LONG_TYPE ge,ZOGII_LONG_TYPE na,ZOGII_LONG_TYPE sp);
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
	/////////////////////////////////////////////////////////////////

	char CurrentDir[ZOGII_PAT_MAX];
	//�趨������ 
	// 0 =Ӣ�� ���� 
	// 1 =���ļ���
	// 2 =���ķ���	
	unsigned char language;
	//��
	ZOGII_LONG_TYPE ListTotal;
	ZOGII_LONG_TYPE ListbufTotal;
	DATALIST *DataList;
	//ѡ�����ѡ��
	DATALIST *curlist;
	//��ʱ //��ֹɾ��������
	DATALIST templist;

	//����
	ZOGII_ULONG_TYPE DBtotal;
	struct ZOGII_Coccinellidae_SUBFamily *DBdata;
	ZOGII_ULONG_TYPE DBPictotal;
	struct ZOGII_Pic *DBPicdata;
	//��ʱ����
	// 0-11ΪImago 
	// 12-23ΪLarva
	// 24-35ΪPupa
	// 36-47ΪOvum
	// 48 ΪMAP
	struct ZOGII_Pic NewPicdata[ZOGII_ALL_PIC]; 
	struct ZOGII_Coccinellidae_DATA Newdata;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGIIADDDLG_H__096C0B0E_E5CC_41EA_A1B6_05467B4FDF0D__INCLUDED_)
