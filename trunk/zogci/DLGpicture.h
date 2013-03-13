#if !defined(AFX_DLGPICTURE_H__553E2BF2_8C77_4D51_89EA_049532EE564C__INCLUDED_)
#define AFX_DLGPICTURE_H__553E2BF2_8C77_4D51_89EA_049532EE564C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGpicture.h : header file
//
#include "cv.h"		
#include "highgui.h"	 

/////////////////////////////////////////////////////////////////////////////
// CDLGpicture dialog

class CDLGpicture : public CDialog
{
// Construction
public:
	CDLGpicture(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGpicture)
	enum { IDD = IDD_PICTURE };
	CStatic	m_pic;
	//}}AFX_DATA
	BOOL OnInitDialog();
	void AutoSize();

	CRect pic_Rect;
	bool LoadFlag;
	char *txtbuf;
	char *picpath;

	void Load(char *path,char *txt);
	void UnLoad(void);
	void Show(void);
	void ReShow(void);

	IplImage* m_Image;

	void ReadImage(CString imgPath);
void ResizeImage(IplImage* img);
void ShowImage(IplImage* img, UINT ID);
// Overrides

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGpicture)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGpicture)
	afx_msg void OnTxtwin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPICTURE_H__553E2BF2_8C77_4D51_89EA_049532EE564C__INCLUDED_)
