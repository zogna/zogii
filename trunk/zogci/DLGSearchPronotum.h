#if !defined(AFX_DLGSEARCHPRONOTUM_H__FE316DDE_0CD0_4C50_8E99_6F0BEB10133D__INCLUDED_)
#define AFX_DLGSEARCHPRONOTUM_H__FE316DDE_0CD0_4C50_8E99_6F0BEB10133D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGSearchPronotum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGSearchPronotum dialog

class CDLGSearchPronotum : public CDialog
{
// Construction
public:
	CDLGSearchPronotum(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGSearchPronotum)
	enum { IDD = IDD_SEARCH_PRONOTUM };
	CButton	m_pronotum_spots;
	CButton	m_pronotum_solid;
	CButton	m_pronotum_2big;
	BOOL	m_pronotum_any;
	BOOL	m_pronotum_other;
	//}}AFX_DATA

	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGSearchPronotum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGSearchPronotum)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSEARCHPRONOTUM_H__FE316DDE_0CD0_4C50_8E99_6F0BEB10133D__INCLUDED_)
