// DLGmap.cpp : implementation file
//

#include "stdafx.h"
#include "zogiiadd.h"
#include "DLGmap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern char DiscoverMapEnum[][64];
extern unsigned int DiscoverMapEnumTotal;
/////////////////////////////////////////////////////////////////////////////
// CDLGmap dialog


CDLGmap::CDLGmap(CWnd* pParent /*=NULL*/)
: CDialog(CDLGmap::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGmap)
	//}}AFX_DATA_INIT
}


void CDLGmap::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGmap)
	DDX_Control(pDX, IDC_LISTBOX_DST, m_listboxDST);
	DDX_Control(pDX, IDC_LISTBOX_SRC, m_listboxSRC);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGmap, CDialog)
//{{AFX_MSG_MAP(CDLGmap)
ON_BN_CLICKED(IDC_BUTTON_SRC2DST, OnButtonSrc2dst)
ON_BN_CLICKED(IDC_BUTTON_DST2SRC, OnButtonDst2src)
ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGmap message handlers
void CDLGmap::SetListDst(unsigned char *p,unsigned char *t) 
{
	listdst=p;
	dsttotal=t;
}

BOOL CDLGmap::OnInitDialog()
{
	CDialog::OnInitDialog();

	unsigned int i,j;
	//画SRC列表
	for(i=0;i<DiscoverMapEnumTotal;i++)
	{
		for(j=0;j<(*dsttotal);j++)
		{
			if(i==listdst[j])
				break;
		}
		if(j==(*dsttotal))
			m_listboxSRC.AddString(DiscoverMapEnum[i]);
	}
	//画DST列表
	for(j=0;j<(*dsttotal);j++)
		m_listboxDST.AddString(DiscoverMapEnum[listdst[j]]);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGmap::OnButtonSrc2dst() 
{
	// TODO: Add your control notification handler code here
	unsigned int i;
	UpdateData(TRUE);
	//删除
	i=m_listboxSRC.GetCurSel();
	m_listboxSRC.DeleteString(i);
	//插入
	m_listboxDST.AddString(DiscoverMapEnum[i]);
}

void CDLGmap::OnButtonDst2src() 
{
	// TODO: Add your control notification handler code here
	unsigned int i;
	char str[256];
	UpdateData(TRUE);
	//删除
	i=m_listboxDST.GetCurSel();
	m_listboxDST.GetText(i,str);
	m_listboxDST.DeleteString(i);
	//插入
	for(i=0;i<DiscoverMapEnumTotal;i++)
	{
		if(!strcmp(str,DiscoverMapEnum[i]))
		{
			m_listboxSRC.InsertString(i,DiscoverMapEnum[i]);
			break;
		}
	}
}

void CDLGmap::OnButtonOk() 
{
	// TODO: Add your control notification handler code here
	int i;
	unsigned int j;
	char str[256];

	*dsttotal=0;
	//遍历
	for(i=0;i<m_listboxDST.GetCount();i++)
	{
		m_listboxDST.GetText(i,str);

		for(j=0;j<DiscoverMapEnumTotal;j++)
		{
			if(!strcmp(str,DiscoverMapEnum[j]))
			{
				listdst[(*dsttotal)]=(unsigned char)j;
				(*dsttotal)++;
				break;
			}
		}
	}
	CDialog::OnCancel();
}
