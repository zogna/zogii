// zogciDlg.h : header file
//

#if !defined(AFX_ZOGCIDLG_H__54182CA8_9085_4A3D_AC12_9873508E99B0__INCLUDED_)
#define AFX_ZOGCIDLG_H__54182CA8_9085_4A3D_AC12_9873508E99B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZogciDlg dialog
#include "zogiidb.h"

class CZogciDlg : public CDialog
{
// Construction
public:
	CZogciDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZogciDlg)
	enum { IDD = IDD_ZOGCI_DIALOG };
	CListCtrl	m_SearchReport;
	CListCtrl	m_ListPicture;
	CListCtrl	m_OtherName;
	CListCtrl	m_Food;
	CStatic	m_Picture;
	CTreeCtrl	m_tree;
	int		m_Calthrop;
	int		m_ColorA;
	int		m_ColorB;
	int		m_ColorC;
	int		m_ColorD;
	int		m_ColorNum;
	int		m_SetLanguage;
	int		m_Texture;
	int		m_TypeSearch;
	int		m_Villus;
	CString	m_DiscoverName;
	CString	m_DiscoverSearch;
	CString	m_FoodSearch;
	CString	m_Name;
	CString	m_PicturePath;
	CString	m_FoodType;
	CString	m_StartStrSearch;
	CString	m_StrSearch;
	CString	m_Text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZogciDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZogciDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAbout();
	afx_msg void OnBUTTONStartStrSearch();
	afx_msg void OnBUTTONStrSearch();
	afx_msg void OnBUTTONDiscoverSearch();
	afx_msg void OnBUTTONFoodSearch();
	afx_msg void OnBUTTONSeeAllPicture();
	afx_msg void OnBUTTONSeeSrcPicture();
	afx_msg void OnItemclickLISTPicture(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemclickLISTSearchReport(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONSeeSrcText();
	afx_msg void OnBUTTONLarva();
	afx_msg void OnBUTTONImago();
	afx_msg void OnBUTTONOvum();
	afx_msg void OnBUTTONPupa();
	afx_msg void OnBUTTONChoosePath();
	afx_msg void OnCloseupCOMBOSetLanguage();
	afx_msg void OnBUTTONSeeSearchPic();
	afx_msg void OnBUTTONHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	//Ä¿Â¼
	char CurrentDir[ZOGII_PAT_MAX];
	//Í¼Ïñ
	int PictureH;
	int PictureW;
	CDC *PictureCDC;
	CDC TempPictureCDC;
	
	//Êý¾Ý
	ZOGII_ULONG_TYPE DBtotal;
	struct ZOGII_Coccinellidae_SUBFamily *DBdata;
	ZOGII_ULONG_TYPE DBPictotal;
	struct ZOGII_Pic *DBPicdata;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGCIDLG_H__54182CA8_9085_4A3D_AC12_9873508E99B0__INCLUDED_)
