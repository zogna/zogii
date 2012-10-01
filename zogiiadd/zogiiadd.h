// zogiiadd.h : main header file for the ZOGIIADD application
//

#if !defined(AFX_ZOGIIADD_H__CC1C6803_07BF_4EFB_A5DC_9D6EF2E45050__INCLUDED_)
#define AFX_ZOGIIADD_H__CC1C6803_07BF_4EFB_A5DC_9D6EF2E45050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZogiiaddApp:
// See zogiiadd.cpp for the implementation of this class
//

class CZogiiaddApp : public CWinApp
{
public:
	CZogiiaddApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZogiiaddApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZogiiaddApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGIIADD_H__CC1C6803_07BF_4EFB_A5DC_9D6EF2E45050__INCLUDED_)
