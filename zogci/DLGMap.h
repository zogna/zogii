#if !defined(AFX_DLGMAP_H__0093F516_7D2F_4F3C_8B65_9743D12B841E__INCLUDED_)
#define AFX_DLGMAP_H__0093F516_7D2F_4F3C_8B65_9743D12B841E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGMap.h : header file
//
#include "cv.h"		
#include "highgui.h"	 
/////////////////////////////////////////////////////////////////////////////
// CDLGMap dialog

class CDLGMap : public CDialog
{
// Construction
public:
	CDLGMap(CWnd* pParent = NULL);   // standard constructor
	~CDLGMap();
// Dialog Data
	//{{AFX_DATA(CDLGMap)
	enum { IDD = IDD_MAP };
	CStatic	m_map;
	//}}AFX_DATA

	BOOL	OnInitDialog();
	void AutoSize();

	IplImage* srcImage;
	IplImage* miniImage;

	void Load();
	void BuildMap();
	void ReSizeShowImage(IplImage *pImage);

	bool IplImage2Bmp(IplImage *pImage,HBITMAP &hBitmap);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGMap)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGMap)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAP_H__0093F516_7D2F_4F3C_8B65_9743D12B841E__INCLUDED_)
