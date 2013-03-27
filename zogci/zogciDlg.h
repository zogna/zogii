// zogciDlg.h : header file
//

#if !defined(AFX_ZOGCIDLG_H__36402ABF_9138_46EE_B0EC_469D85B463B5__INCLUDED_)
#define AFX_ZOGCIDLG_H__36402ABF_9138_46EE_B0EC_469D85B463B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZogciDlg dialog
#include "DLGabout.h"
#include "DLGinfo.h"
#include "DLGlink.h"
#include "DLGresult.h"
#include "DLGsearch.h"

class CZogciDlg : public CDialog
{
// Construction
public:
	CZogciDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZogciDlg)
	enum { IDD = IDD_ZOGCI_DIALOG };
	CTreeCtrl	m_Tree;
	CTabCtrl	m_TabMain;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZogciDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL


CDLGabout	DlgAbout;
CDLGinfo	DlgInfo;
CDLGlink	DlgLink;
CDLGresult	DlgResult;
CDLGsearch	DlgSearch;

	void TabMainInit(void);
	void OnOK();

	CRect		m_clientRect;		//程序界面区域位置

	void UpdatePannelPosition();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZogciDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGCIDLG_H__36402ABF_9138_46EE_B0EC_469D85B463B5__INCLUDED_)
