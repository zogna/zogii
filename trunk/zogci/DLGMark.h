#if !defined(AFX_DLGMARK_H__2D35D8F2_35CD_4A57_9B90_C21FE5EC70B2__INCLUDED_)
#define AFX_DLGMARK_H__2D35D8F2_35CD_4A57_9B90_C21FE5EC70B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGMark.h : header file
//
#include "ColourPickerCB.h"
/////////////////////////////////////////////////////////////////////////////
// CDLGMark dialog

class CDLGMark : public CDialog
{
// Construction
public:
	CDLGMark(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGMark)
	enum { IDD = IDD_MARK };

	//}}AFX_DATA
	CColourPickerCB	m_crColour;
	COLORREF m_Colour;
	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGMark)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGMark)
	afx_msg void OnButtonMark();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMARK_H__2D35D8F2_35CD_4A57_9B90_C21FE5EC70B2__INCLUDED_)
