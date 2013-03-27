#if !defined(AFX_DLGPICWIN_H__C2F813A6_4058_43E9_8FA7_1C7F9797C6E6__INCLUDED_)
#define AFX_DLGPICWIN_H__C2F813A6_4058_43E9_8FA7_1C7F9797C6E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGpicwin.h : header file
//
#include "cv.h"		
#include "highgui.h"	 

#define UNM_HYPERLINK_CLICKED	(WM_APP + 0x100)
#include "PPTooltip.h"

#include "DLGResultPannel.h"

#define MAX_PICTURE_WIN	30
#define MID_PICTURE_WIN	20
#define MIN_PICTURE_WIN	12

#define FLAG_WIN_RESULT	1
#define FLAG_WIN_ADULT	2
#define FLAG_WIN_LARVA	3
#define FLAG_WIN_PUPA	4
#define FLAG_WIN_OVUM	5
#define FLAG_WIN_OTHER	6

/////////////////////////////////////////////////////////////////////////////
// DLGpicwin dialog

struct PICWIN_DATA_ST
{
	bool LoadFlag;
	char path[ZOG_MAX_PATH_STR];
	IplImage* Image;
	CButton *buttonres;
};

class DLGpicwin : public CDialog
{
// Construction
public:
	DLGpicwin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DLGpicwin)
	enum { IDD = IDD_PICWIN };
	//}}AFX_DATA
	CDLGResultPannel DlgResultPannel;
	int flag;

	BOOL	OnInitDialog();
	void AutoSize();

	int CurrentPicWinMax;
	void AutoSizePictureWin(CRect rc);

	struct PICWIN_DATA_ST PicWinData[MAX_PICTURE_WIN];
	void Load(int i,char *path,char* txt);
	void UnLoad(int i);


	void DLGpicwin::PicButtonClick(int i);
	///////////////	///////////////	///////////////

	IplImage* miniImage;

	void ReSizeShowImage(CButton *buttonres,IplImage *pImage);
	bool IplImage2Bmp(IplImage *pImage,HBITMAP &hBitmap);
	///////////////	///////////////	///////////////
	CPPToolTip m_tooltip;
	void InitToolTip(void);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void ResultToolTipLoad(int i,char* title);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLGpicwin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLGpicwin)
	afx_msg void OnButtonPicwin1();
	afx_msg void OnButtonPicwin2();
	afx_msg void OnButtonPicwin3();
	afx_msg void OnButtonPicwin4();
	afx_msg void OnButtonPicwin5();
	afx_msg void OnButtonPicwin6();
	afx_msg void OnButtonPicwin7();
	afx_msg void OnButtonPicwin8();
	afx_msg void OnButtonPicwin9();
	afx_msg void OnButtonPicwin10();
	afx_msg void OnButtonPicwin11();
	afx_msg void OnButtonPicwin12();
	afx_msg void OnButtonPicwin13();
	afx_msg void OnButtonPicwin14();
	afx_msg void OnButtonPicwin15();
	afx_msg void OnButtonPicwin16();
	afx_msg void OnButtonPicwin17();
	afx_msg void OnButtonPicwin18();
	afx_msg void OnButtonPicwin19();
	afx_msg void OnButtonPicwin20();
	afx_msg void OnButtonPicwin21();
	afx_msg void OnButtonPicwin22();
	afx_msg void OnButtonPicwin23();
	afx_msg void OnButtonPicwin24();
	afx_msg void OnButtonPicwin25();
	afx_msg void OnButtonPicwin26();
	afx_msg void OnButtonPicwin27();
	afx_msg void OnButtonPicwin28();
	afx_msg void OnButtonPicwin29();
	afx_msg void OnButtonPicwin30();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPICWIN_H__C2F813A6_4058_43E9_8FA7_1C7F9797C6E6__INCLUDED_)
