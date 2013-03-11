#if !defined(AFX_DLGINFO_H__AA38EFBA_C4E2_466D_AB5C_2FDD0407810F__INCLUDED_)
#define AFX_DLGINFO_H__AA38EFBA_C4E2_466D_AB5C_2FDD0407810F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGinfo.h : header file
//

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
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	BOOL OnInitDialog();

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
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFO_H__AA38EFBA_C4E2_466D_AB5C_2FDD0407810F__INCLUDED_)
