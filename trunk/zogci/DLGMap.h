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
#include "PPTooltip.h"

struct MapRect_ST
{
	int top;
	int bottom;
	int left;
	int right;
	int width;
	int height;
	//Í¼ÏñËõ·ÅÂÊ
	float rate;
};

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
	IplImage* dstImage;
	IplImage* miniImage;

	void Load(int total,unsigned char *imap);

	void ReSizeShowImage(IplImage *pImage);
	bool IplImage2Bmp(IplImage *pImage,HBITMAP &hBitmap);

	struct MapRect_ST MapRect;
///////////////////////////////////////////////
	int MapTotal;
	unsigned char MapData[256];
///////////////////////////////////////////////
	CPPToolTip m_tooltip;
	void InitToolTip(void);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void NotifyDisplayTooltip(NMHDR * pNMHDR, LRESULT * result);
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
