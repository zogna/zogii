#if !defined(AFX_DLGINFOTXTPANNEL_H__C80BD597_B8C9_4863_9982_E2AD91F4931A__INCLUDED_)
#define AFX_DLGINFOTXTPANNEL_H__C80BD597_B8C9_4863_9982_E2AD91F4931A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGInfotxtPannel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGInfotxtPannel dialog

class CDLGInfotxtPannel : public CDialog
{
// Construction
public:
	CDLGInfotxtPannel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGInfotxtPannel)
	enum { IDD = IDD_INFOTXT_PANNEL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGInfotxtPannel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGInfotxtPannel)
	afx_msg void OnBUTTONFirst();
	afx_msg void OnBUTTONPrevious();
	afx_msg void OnBUTTONNext();
	afx_msg void OnBUTTONLast();
	afx_msg void OnBUTTONJump();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFOTXTPANNEL_H__C80BD597_B8C9_4863_9982_E2AD91F4931A__INCLUDED_)
