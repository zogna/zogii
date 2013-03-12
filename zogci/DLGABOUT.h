#if !defined(AFX_DLGABOUT_H__33723444_4631_4EBB_B16D_9515DE517650__INCLUDED_)
#define AFX_DLGABOUT_H__33723444_4631_4EBB_B16D_9515DE517650__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGabout.h : header file
//
#include "MyHyperLink.h"

/////////////////////////////////////////////////////////////////////////////
// CDLGabout dialog

class CDLGabout : public CDialog
{
// Construction
public:
	CDLGabout(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGabout)
	enum { IDD = IDD_ABOUT };
	int		m_Language;
	CMyHyperLink	m_addr;
	//}}AFX_DATA
	void AutoSize();
	BOOL OnInitDialog();
	void Authors(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGabout)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGabout)
	afx_msg void OnAnnounce();
	afx_msg void OnLanguageButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGABOUT_H__33723444_4631_4EBB_B16D_9515DE517650__INCLUDED_)
