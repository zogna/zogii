// zogci.h : main header file for the ZOGCI application
//

#if !defined(AFX_ZOGCI_H__0D57A32B_CEE2_4B69_BC16_9F759A368A02__INCLUDED_)
#define AFX_ZOGCI_H__0D57A32B_CEE2_4B69_BC16_9F759A368A02__INCLUDED_

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


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOGCI_H__0D57A32B_CEE2_4B69_BC16_9F759A368A02__INCLUDED_)
