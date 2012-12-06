#if !defined(AFX_MYFILEDIALOG_H__6B1124AB_C90B_4956_B574_F0097AF02388__INCLUDED_)
#define AFX_MYFILEDIALOG_H__6B1124AB_C90B_4956_B574_F0097AF02388__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyFileDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyFileDialog dialog
#include "dlgs.h"

#define MYWM_POSTINIT WM_USER + 100

#define FILEDLG_W 443
#define FILEDLG_H 250

class CMyFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CMyFileDialog)
/*
	stc3,stc2 控件的标签（文件名和文件类型）
	edt1,cmb1 编辑框控件和滚动条
	IDOK，IDCANCEL OK和CANCEL按钮
	lst1 显示文件名的窗口
	lst2 预览模式的列表
*/
	
	// reverse-engineered command codes for SHELLDLL_DefView
	enum LISTVIEWCMD
	{	ODM_VIEW_ICONS = 0x7029,
		ODM_VIEW_LIST  = 0x702b,
		ODM_VIEW_DETAIL= 0x702c,
		ODM_VIEW_THUMBS= 0x702d,
		ODM_VIEW_TILES = 0x702e,
	};
public:
	CMyFileDialog(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL,
		int w=FILEDLG_W,
		int h=FILEDLG_H);
	
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnMYWM_POSTINIT(WPARAM wParam, LPARAM lParam);
	
	int neww;
	int newh;

protected:
	//{{AFX_MSG(CMyFileDialog)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFILEDIALOG_H__6B1124AB_C90B_4956_B574_F0097AF02388__INCLUDED_)
