#if !defined(AFX_DLGINFO_H__AA38EFBA_C4E2_466D_AB5C_2FDD0407810F__INCLUDED_)
#define AFX_DLGINFO_H__AA38EFBA_C4E2_466D_AB5C_2FDD0407810F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGinfo.h : header file
//
#include "DLGMark.h"
#include "DLGInfoTxt.h"
#include "DLGresult.h"
#include "DLGMap.h"
/////////////////////////////////////////////////////////////////////////////
// CDLGinfo dialog

class CDLGinfo : public CDialog
{
// Construction
public:
	CDLGinfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGinfo)
	enum { IDD = IDD_INFO };
	CTabCtrl	m_tabinfo;

	//}}AFX_DATA
	void AutoSize();
	BOOL OnInitDialog();
	//字体 定义静态变量,也可以定义全局变量或者对话框的成员变量,临时变量或者局部变量是不行的
	CFont SFTextFont;
	CFont GETextFont;
	CFont SPTextFont;
	CFont SSPTextFont;

	CDLGMark DlgMark;

	void TabInfoInit(void);
	CDLGInfoTxt DlgInfoTxt;
	CDLGMap		DlgInfoMap;
	CDLGresult	DlgInfoAdult;
	CDLGresult	DlgInfoLarva;
	CDLGresult	DlgInfoPupa;
	CDLGresult	DlgInfoOvum;
	CDLGresult	DlgInfoOther;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGinfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGinfo)
	afx_msg void OnSelchangeTabInfo(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFO_H__AA38EFBA_C4E2_466D_AB5C_2FDD0407810F__INCLUDED_)
