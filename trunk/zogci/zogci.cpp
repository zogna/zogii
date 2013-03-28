// zogci.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "zogci.h"
#include "zogciDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZogciApp

BEGIN_MESSAGE_MAP(CZogciApp, CWinApp)
	//{{AFX_MSG_MAP(CZogciApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZogciApp construction

CZogciApp::CZogciApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CZogciApp object

CZogciApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CZogciApp initialization

BOOL CZogciApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CZogciDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

TCHAR CurrentDir[ZOG_MAX_PATH_STR]="";
TCHAR LanguageChsDir[ZOG_MAX_PATH_STR]="";
TCHAR LanguageChtDir[ZOG_MAX_PATH_STR]="";
TCHAR UserInfoDir[ZOG_MAX_PATH_STR]="";
TCHAR MapPath[ZOG_MAX_PATH_STR]="";
// 0=Ӣ�� 1=���� 2=����
char LanguageFlag=1;

void Set_AllPath(void)
{
	GetCurrentDirectory(ZOG_MAX_PATH_STR, CurrentDir);
	sprintf(LanguageChsDir, "%s\\langchs.ini", CurrentDir);
	sprintf(LanguageChtDir, "%s\\langcht.ini", CurrentDir);
	sprintf(UserInfoDir, "%s\\userinfo.ini", CurrentDir);
	sprintf(MapPath, "%s\\map.bmp", CurrentDir);
}

//��ȡ����·��
//���ļ��Ի���󣬵�ǰ·���ᷢ���仯��������Ҫ��ʼ���Ի����ʱ�򱣴�·��
TCHAR* Language_GetIniPath(void)
{
	/*
	static TCHAR* pszIniPath = NULL;//��ָ�����׳�ʼ��,
	if( NULL == pszIniPath)
	{
		TCHAR szDirBuf[512] = {0};
		pszIniPath = new TCHAR[512];//���ͷž��ڴ�й¶
		memset(pszIniPath, 0, 512);
		GetCurrentDirectory(512, szDirBuf);
		sprintf(pszIniPath, "%s\\langchn.ini", szDirBuf);
	}
	return pszIniPath;
	*/

	switch(LanguageFlag)
	{
	case 1:	return LanguageChsDir;
	case 2: return LanguageChtDir;
	default: return "";
	}
}

//��Ӣ���ַ�����ת��Ϊ����ǰ�������͵��ַ�����
CString Language_ConvertString(CString strText)
{
	if(0==LanguageFlag)
		return strText;

	char val[ZOG_MAX_PATH_STR];
	CString strIniPath,strRet;

	memset(val,0,ZOG_MAX_PATH_STR);
	GetPrivateProfileString("String", strText, "", val, ZOG_MAX_PATH_STR, Language_GetIniPath());
	strRet = val;
	if(strRet.GetLength()==0)
	{
		//���ini�ļ��в����ڶ�Ӧ���ַ���������ΪĬ��ֵ��Ӣ�ģ�
		return strText;
	}
	return strRet;
}

//���öԻ����еľ�̬�ı�(Ӣ��-->��ǰ����)   
void Language_SetWndStaticText(CWnd * pWnd)
{
	CString strCaption,strText;

	//���������ڵı���
	pWnd->GetWindowText(strCaption);
	if(strCaption.GetLength()>0)
	{
		strText=Language_ConvertString(strCaption);
		pWnd->SetWindowText(strText);
	}

	//�����Ӵ��ڵı���
	CWnd * pChild=pWnd->GetWindow(GW_CHILD);
	CString strClassName;
	while(pChild)
	{
		//////////////////////////////////////////////////////////////////////////		
		strClassName = ((CRuntimeClass*)pChild->GetRuntimeClass())->m_lpszClassName;
		if(strClassName == "CEdit")
		{
			//��һ���Ӵ���
			pChild=pChild->GetWindow(GW_HWNDNEXT);
			continue;
		}
		//////////////////////////////////////////////////////////////////////////	

		//�����Ӵ��ڵĵ�ǰ�����ı�
		pChild->GetWindowText(strCaption);
		strText=Language_ConvertString(strCaption);
		pChild->SetWindowText(strText);

		//��һ���Ӵ���
		pChild=pChild->GetWindow(GW_HWNDNEXT);
	}
}
/*
 *	��Ͽ�����ת��
 */
void Language_ConvertComboBox(CComboBox &stuComboBox)
{
	int nCount = stuComboBox.GetCount();
	if(nCount <= 0)
	{
		return;
	}
	CString* strText = new CString[nCount];
	int i;
	for( i = 0; i < nCount;i++)
	{
		stuComboBox.GetLBText(i, strText[i]);
		strText[i] = Language_ConvertString(strText[i]);
	}
	stuComboBox.ResetContent();
	for(i = 0; i< nCount; i++)
	{
		stuComboBox.AddString(strText[i]);
	}
	delete []strText;
}

void Language_WriteUserInfo(void)
{
	WritePrivateProfileStruct("UserInfo" , "Language" , &LanguageFlag, sizeof(char), UserInfoDir);
}

void Language_ReadUserInfo(void)
{
	char temp;
	if(GetPrivateProfileStruct("UserInfo" , "Language" , &temp, sizeof(char), UserInfoDir))
		LanguageFlag=temp;
}