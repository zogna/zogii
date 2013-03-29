#if !defined(AFX_DLGINFOTXTINFO_H__6F27D0BB_8017_47DF_A6DB_6F44ED4B73A2__INCLUDED_)
#define AFX_DLGINFOTXTINFO_H__6F27D0BB_8017_47DF_A6DB_6F44ED4B73A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGInfotxtInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGInfotxtInfo dialog

class CDLGInfotxtInfo : public CDialog
{
// Construction
public:
	CDLGInfotxtInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGInfotxtInfo)
	enum { IDD = IDD_INFOTXT_INFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGInfotxtInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGInfotxtInfo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFOTXTINFO_H__6F27D0BB_8017_47DF_A6DB_6F44ED4B73A2__INCLUDED_)
