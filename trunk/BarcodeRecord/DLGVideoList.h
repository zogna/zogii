#if !defined(AFX_DLGVIDEOLIST_H__88EBD002_D91D_4EDE_8C43_D6E48DB549AB__INCLUDED_)
#define AFX_DLGVIDEOLIST_H__88EBD002_D91D_4EDE_8C43_D6E48DB549AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGVideoList.h : header file
//

//��Ƶ�ֶ�
struct VIDEO_INFO_ST
{
	unsigned long int nid;
	unsigned long int product_nid;

	//��ʼʱ��
	int start_year;
	int start_mon;
	int start_day;
	int start_hour;
	int start_min;
	int start_sec;
	//����ʱ��
	int end_year;
	int end_mon;
	int end_day;
	int end_hour;
	int end_min;
	int end_sec;

	unsigned long int size;	//�ļ���С
	char path[260];	//�ļ�·��
};

/////////////////////////////////////////////////////////////////////////////
// CDLGVideoList dialog

class CDLGVideoList : public CDialog
{
// Construction
public:
	CDLGVideoList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGVideoList)
	enum { IDD = IDD_VIDEOLIST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
BOOL CDLGVideoList::OnInitDialog();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGVideoList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGVideoList)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVIDEOLIST_H__88EBD002_D91D_4EDE_8C43_D6E48DB549AB__INCLUDED_)
