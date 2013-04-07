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
	CButton	m_contour_ractangle;
	CButton	m_contour_ellipse;
	CButton	m_contour_circle;
	CButton	m_pupa_softthorn;
	CButton	m_pupa_normal;
	CButton	m_pupa_hardthorn;
	CButton	m_pupa_hair;
	CButton	m_larva_allhair;
	BOOL	m_adult_size_02;
	BOOL	m_adult_size_25;
	BOOL	m_adult_size_58;
	BOOL	m_adult_size_810;
	BOOL	m_adult_size_any;
	BOOL	m_allname;
	BOOL	m_doc;
	BOOL	m_ge;
	BOOL	m_sf;
	BOOL	m_sp;
	BOOL	m_ssp;
	CString	m_txt;
	BOOL	m_larva_all;
	CButton	m_larva_branch;
	CButton	m_larva_flat;
	CButton	m_larva_halfhair;
	CButton	m_larva_normal;
	CButton	m_larva_nullhair;
	CButton	m_larva_thorn;
	BOOL	m_pupa_all;
	BOOL	m_contour_any;
	BOOL	m_adult_size_m10;
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
	afx_msg void OnButtonReset();
	afx_msg void OnButtonAdult();
	afx_msg void OnButtonLarva();
	afx_msg void OnButtonPupa();
	afx_msg void OnButtonElytron();
	afx_msg void OnButtonPronotum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSEARCH_H__A4D6EE7F_FCC1_42F3_A210_2275E3BE8871__INCLUDED_)
