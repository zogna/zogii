#if !defined(AFX_DLGMAP_H__B35F6336_2AF2_4853_8BC2_F6D6AD4AD5A3__INCLUDED_)
#define AFX_DLGMAP_H__B35F6336_2AF2_4853_8BC2_F6D6AD4AD5A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGmap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGmap dialog

class CDLGmap : public CDialog
{
// Construction
public:
	CDLGmap(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGmap)
	enum { IDD = IDD_DIALOG_MAP };
	CListBox	m_listboxDST;
	CListBox	m_listboxSRC;
	//}}AFX_DATA

	void SetListDst(unsigned char *p,unsigned char *t);

	BOOL OnInitDialog();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGmap)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	unsigned char *dsttotal;
	unsigned char *listdst;
	char str[256];

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGmap)
	afx_msg void OnButtonSrc2dst();
	afx_msg void OnButtonDst2src();
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAP_H__B35F6336_2AF2_4853_8BC2_F6D6AD4AD5A3__INCLUDED_)
