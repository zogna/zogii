#if !defined(AFX_DLGANNOUNCE_H__711976DE_2D28_49D5_8A85_9D19596052CA__INCLUDED_)
#define AFX_DLGANNOUNCE_H__711976DE_2D28_49D5_8A85_9D19596052CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGannounce.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGannounce dialog

class CDLGannounce : public CDialog
{
// Construction
public:
	CDLGannounce(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGannounce)
	enum { IDD = IDD_Announce };
	CString	m_a;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGannounce)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	BOOL OnInitDialog();
	void Info(void);
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGannounce)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGANNOUNCE_H__711976DE_2D28_49D5_8A85_9D19596052CA__INCLUDED_)
