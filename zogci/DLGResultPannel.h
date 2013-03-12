#if !defined(AFX_DLGRESULTPANNEL_H__130AEAEF_C766_4DF9_82A3_7111A5EDC24B__INCLUDED_)
#define AFX_DLGRESULTPANNEL_H__130AEAEF_C766_4DF9_82A3_7111A5EDC24B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGResultPannel.h : header file
//
#define MAX_PICTURE_WIN	36
#define MID_PICTURE_WIN	25
#define MIN_PICTURE_WIN	16

/////////////////////////////////////////////////////////////////////////////
// CDLGResultPannel dialog

class CDLGResultPannel : public CDialog
{
// Construction
public:
	CDLGResultPannel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGResultPannel)
	enum { IDD = IDD_RESULT_PANNEL };
	int		m_split;
	//}}AFX_DATA

	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGResultPannel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGResultPannel)
	afx_msg void OnBUTTONFirst();
	afx_msg void OnBUTTONPrevious();
	afx_msg void OnBUTTONNext();
	afx_msg void OnBUTTONLast();
	afx_msg void OnBUTTONJump();
	afx_msg void OnSelchangeCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRESULTPANNEL_H__130AEAEF_C766_4DF9_82A3_7111A5EDC24B__INCLUDED_)
