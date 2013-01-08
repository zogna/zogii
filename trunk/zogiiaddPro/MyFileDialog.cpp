// MyFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MyFileDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFileDialog

IMPLEMENT_DYNAMIC(CMyFileDialog, CFileDialog)

CMyFileDialog::CMyFileDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd,int w,int h) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	neww=w;
	newh=h;
}

BOOL CMyFileDialog::OnInitDialog()
{
	int difw,difh;
	int w,h;

	if(neww<FILEDLG_W)
	{
		difw=0;
		w=FILEDLG_W;
	}
	else
	{
		difw=neww-FILEDLG_W;
		w=neww;
	}

	if(newh<FILEDLG_H)
	{
		difh=0;
		h=FILEDLG_H;
	}
	else
	{
		difh=newh-FILEDLG_H;
		h=newh;
	}

	RECT Rect;
	CWnd *wndDlg = GetParent();
	wndDlg->SetWindowPos(NULL, 0, 0,w,h,SWP_NOMOVE);

	CWnd *wndCtrl;

	wndCtrl = wndDlg->GetDlgItem(lst1);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	// Move all the controls according to the new size of the dialog.
	wndCtrl->SetWindowPos(NULL, 0, 0,w-24,h-130,SWP_NOMOVE);
	
	wndCtrl = wndDlg->GetDlgItem(edt1);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	wndCtrl->SetWindowPos(NULL, Rect.left, Rect.top+difh,0,0,SWP_NOSIZE);

	wndCtrl = wndDlg->GetDlgItem(cmb1);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	wndCtrl->SetWindowPos(NULL, Rect.left, Rect.top+difh,0,0,SWP_NOSIZE);

	wndCtrl = wndDlg->GetDlgItem(stc3);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	wndCtrl->SetWindowPos(NULL, Rect.left, Rect.top+difh,0,0,SWP_NOSIZE);

	wndCtrl = wndDlg->GetDlgItem(stc2);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	wndCtrl->SetWindowPos(NULL, Rect.left, Rect.top+difh,0,0,SWP_NOSIZE);

	wndCtrl = wndDlg->GetDlgItem(IDOK);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	wndCtrl->SetWindowPos(NULL, Rect.left, Rect.top+difh,0,0,SWP_NOSIZE);
	wndCtrl->SetWindowPos(NULL, 0, 0,Rect.right-Rect.left+difw,Rect.bottom-Rect.top,SWP_NOMOVE);

	wndCtrl = wndDlg->GetDlgItem(IDCANCEL);
	wndCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect); // Remember it is child controls
	wndCtrl->SetWindowPos(NULL, Rect.left, Rect.top+difh,0,0,SWP_NOSIZE);

	CFileDialog::OnInitDialog(); 
	
	//自定义消息
	PostMessage(MYWM_POSTINIT,0,0); 

	return TRUE;
}

LRESULT CMyFileDialog::OnMYWM_POSTINIT(WPARAM wParam, LPARAM lParam)
{
	GetParent()->GetDlgItem(lst2)->SendMessage(WM_COMMAND, ODM_VIEW_THUMBS);
	return 1;
}

BEGIN_MESSAGE_MAP(CMyFileDialog,CFileDialog	)
	//{{AFX_MSG_MAP(CMyFileDialog)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_MESSAGE(MYWM_POSTINIT, OnMYWM_POSTINIT)//注意这条语句的后面没有分号
END_MESSAGE_MAP()

