#if !defined(AFX_DLGRESULT_H__E1F5D879_0FE4_4B71_A628_B87FF279AFF4__INCLUDED_)
#define AFX_DLGRESULT_H__E1F5D879_0FE4_4B71_A628_B87FF279AFF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGresult.h : header file
//
#include "DLGResultPannel.h"
#include "DLGpicture.h"
/////////////////////////////////////////////////////////////////////////////
// CDLGresult dialog

class CDLGresult : public CDialog
{
// Construction
public:
	CDLGresult(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGresult)
	enum { IDD = IDD_RESULT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CDLGResultPannel  DlgResultPannel;
	CDLGpicture		DlgPicture[MAX_PICTURE_WIN];
	int CurrentPicWinMax;

	void AutoSize();
	void AutoSizePictureWin(CRect rc);


	void CloseImage(unsigned char **image);
	void ReadImage(char *path,unsigned char **image,unsigned long int *size);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGresult)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	BOOL OnInitDialog();

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGresult)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRESULT_H__E1F5D879_0FE4_4B71_A628_B87FF279AFF4__INCLUDED_)
