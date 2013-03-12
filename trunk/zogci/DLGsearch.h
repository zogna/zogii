#if !defined(AFX_DLGSEARCH_H__A4D6EE7F_FCC1_42F3_A210_2275E3BE8871__INCLUDED_)
#define AFX_DLGSEARCH_H__A4D6EE7F_FCC1_42F3_A210_2275E3BE8871__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGsearch.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CDLGsearch dialog

class CDLGsearch : public CDialog
{
// Construction
public:
	CDLGsearch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGsearch)
	enum { IDD = IDD_SEARCH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	void AutoSize();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGsearch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	BOOL OnInitDialog();
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGsearch)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSEARCH_H__A4D6EE7F_FCC1_42F3_A210_2275E3BE8871__INCLUDED_)
