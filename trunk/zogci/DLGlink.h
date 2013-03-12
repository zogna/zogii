#if !defined(AFX_DLGLINK_H__4F065FD3_3199_4488_B791_989EAB5B9AC4__INCLUDED_)
#define AFX_DLGLINK_H__4F065FD3_3199_4488_B791_989EAB5B9AC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGlink.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLGlink dialog

class CDLGlink : public CDialog
{
// Construction
public:
	CDLGlink(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGlink)
	enum { IDD = IDD_LINK };
	CListCtrl	m_bbs;
	CListCtrl	m_book;
	CListCtrl	m_flickr;
	CListCtrl	m_website;
	//}}AFX_DATA

	void AutoSize();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGlink)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	BOOL	OnInitDialog();
	void List(void);

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGlink)
	afx_msg void OnClickListWebsite(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListBbs(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListFlickr(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLINK_H__4F065FD3_3199_4488_B791_989EAB5B9AC4__INCLUDED_)
