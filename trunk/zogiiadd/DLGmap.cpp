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

struct DiscoverMap_Enum
{
	char str[64];
	unsigned char id;
};

extern struct DiscoverMap_Enum DiscoverMap[];
extern unsigned int DiscoverMapTotal;
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
	for(i=0;i<DiscoverMapTotal;i++)
	{
		for(j=0;j<(*dsttotal);j++)
		{
			if(DiscoverMap[i].id==listdst[j])
				break;
		}
		//DST里找不到
		if(j==(*dsttotal))
			m_listboxSRC.AddString(DiscoverMap[i].str);
		else	//DST里找到了
			m_listboxDST.AddString(DiscoverMap[i].str);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGmap::OnButtonSrc2dst() 
{
	// TODO: Add your control notification handler code here
	unsigned int i;
	UpdateData(TRUE);
	//删除
	i=m_listboxSRC.GetCurSel();
	m_listboxSRC.GetText(i,str);
	m_listboxSRC.DeleteString(i);

	//插入
	for(i=0;i<DiscoverMapTotal;i++)
	{
		if(!strcmp(str,DiscoverMap[i].str))
		{
			m_listboxDST.AddString(DiscoverMap[i].str);
			break;
		}
	}
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
	for(i=0;i<DiscoverMapTotal;i++)
	{
		if(!strcmp(str,DiscoverMap[i].str))
		{
			m_listboxSRC.InsertString(DiscoverMap[i].id,DiscoverMap[i].str);
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

	(*dsttotal)=0;
	//遍历
	for(i=0;i<m_listboxDST.GetCount();i++)
	{
		m_listboxDST.GetText(i,str);

		for(j=0;j<DiscoverMapTotal;j++)
		{
			if(!strcmp(str,DiscoverMap[j].str))
			{
				listdst[(*dsttotal)]=DiscoverMap[j].id;
				(*dsttotal)++;
				break;
			}
		}
	}

	CDialog::OnCancel();
}
