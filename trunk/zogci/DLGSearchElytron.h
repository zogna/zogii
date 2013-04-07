#if !defined(AFX_DLGSEARCHELYTRON_H__ACD6AE14_B4C3_4845_A21F_D858870E53FF__INCLUDED_)
#define AFX_DLGSEARCHELYTRON_H__ACD6AE14_B4C3_4845_A21F_D858870E53FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGSearchElytron.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGSearchElytron dialog

class CDLGSearchElytron : public CDialog
{
// Construction
public:
	CDLGSearchElytron(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGSearchElytron)
	enum { IDD = IDD_SEARCH_ELYTRON };
	CButton	m_elytron_striped;
	CButton	m_elytron_spots;
	CButton	m_elytron_solid;
	CButton	m_elytron_eye;
	CButton	m_elytron_circle;
	CButton	m_elytron_banded;
	BOOL	m_colornum_1;
	BOOL	m_colornum_2;
	BOOL	m_colornum_3;
	BOOL	m_colornum_4;
	BOOL	m_colornum_any;
	BOOL	m_colornum_m4;
	BOOL	m_spot_1316;
	BOOL	m_spot_14;
	BOOL	m_spot_1720;
	BOOL	m_spot_58;
	BOOL	m_spot_912;
	BOOL	m_spot_any;
	BOOL	m_spot_m20;
	BOOL	m_striped_1;
	BOOL	m_striped_1012;
	BOOL	m_striped_23;
	BOOL	m_striped_46;
	BOOL	m_striped_79;
	BOOL	m_striped_any;
	BOOL	m_striped_m12;
	BOOL	m_elytron_other;
	BOOL	m_elytron_any;
	//}}AFX_DATA

	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGSearchElytron)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGSearchElytron)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSEARCHELYTRON_H__ACD6AE14_B4C3_4845_A21F_D858870E53FF__INCLUDED_)
