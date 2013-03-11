// zogci.h : main header file for the ZOGCI application
//

#if !defined(AFX_ZOGCI_H__D6027772_1C90_4BA9_8E30_ECA48D4C398D__INCLUDED_)
#define AFX_ZOGCI_H__D6027772_1C90_4BA9_8E30_ECA48D4C398D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZogciApp:
// See zogci.cpp for the implementation of this class
//

class CZogciApp : public CWinApp
{
public:
	CZogciApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZogciApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZogciApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



};

#define  ZOG_MAX_PATH_STR 260
void Set_AllPath(void);
	TCHAR* Language_GetIniPath(void);
	CString Language_ConvertString(CString strText);
	void Language_SetWndStaticText(CWnd * pWnd);
	void Language_ConvertComboBox(CComboBox &stuComboBox);

	void Language_WriteUserInfo(void);
	void Language_ReadUserInfo(void);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGCI_H__D6027772_1C90_4BA9_8E30_ECA48D4C398D__INCLUDED_)
