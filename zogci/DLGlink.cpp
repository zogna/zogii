// DLGlink.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGlink.h"
#include "link.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGlink dialog


CDLGlink::CDLGlink(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGlink::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGlink)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLGlink::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGlink)
	DDX_Control(pDX, IDC_LIST_BBS, m_bbs);
	DDX_Control(pDX, IDC_LIST_BOOK, m_book);
	DDX_Control(pDX, IDC_LIST_FLICKR, m_flickr);
	DDX_Control(pDX, IDC_LIST_WEBSITE, m_website);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGlink, CDialog)
	//{{AFX_MSG_MAP(CDLGlink)
	ON_NOTIFY(NM_CLICK, IDC_LIST_WEBSITE, OnClickListWebsite)
	ON_NOTIFY(NM_CLICK, IDC_LIST_BBS, OnClickListBbs)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FLICKR, OnClickListFlickr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGlink message handlers

BOOL CDLGlink::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();

	AutoSize();

	List();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGlink::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetParent()->GetClientRect(&rc);
	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
	MoveWindow(&rc);

	//列表移动
	//宽度
	int list_width=210;

	//WEBSITE
	CRect website_Rect;
	website_Rect.top = rc.top-10/* + 5*/;
	website_Rect.bottom = rc.bottom-25/* - 10*/;
	website_Rect.left = rc.left/* + 10*/;
	website_Rect.right = rc.left+list_width;
	//必须 样式=重叠，边框=调整大小
	GetDlgItem(IDC_LIST_WEBSITE)->MoveWindow(website_Rect);

	//BBS
	CRect bbs_Rect;
	bbs_Rect.top = rc.top-10/* + 5*/;
	bbs_Rect.bottom = rc.bottom-25/* - 10*/;
	bbs_Rect.left = website_Rect.right+5/* + 10*/;
	bbs_Rect.right = bbs_Rect.left+list_width;
	//必须 样式=重叠，边框=调整大小
	GetDlgItem(IDC_LIST_BBS)->MoveWindow(bbs_Rect);

	//flickr
	CRect flickr_Rect;
	flickr_Rect.top = rc.top-10/* + 5*/;
	flickr_Rect.bottom = rc.bottom-25/* - 10*/;
	flickr_Rect.left = bbs_Rect.right+5/* + 10*/;
	flickr_Rect.right = flickr_Rect.left+list_width;
	//必须 样式=重叠，边框=调整大小
	GetDlgItem(IDC_LIST_FLICKR)->MoveWindow(flickr_Rect);

	//BOOK
	CRect book_Rect;
	book_Rect.top = rc.top-10/* + 5*/;
	book_Rect.bottom = rc.bottom-25/* - 10*/;
	book_Rect.left = flickr_Rect.right+5/* + 10*/;
	book_Rect.right = rc.right;
	//必须 样式=重叠，边框=调整大小
	GetDlgItem(IDC_LIST_BOOK)->MoveWindow(book_Rect);

	Invalidate();
}


void CDLGlink::List(void)
{
	//加序号便于排序
	m_bbs.InsertColumn(0, "No.", LVCFMT_LEFT, 30);
	m_flickr.InsertColumn(0, "No.", LVCFMT_LEFT, 30);
	m_website.InsertColumn(0, "No.", LVCFMT_LEFT, 30);

	m_bbs.InsertColumn(1, Language_ConvertString("China and Taiwan Website"), LVCFMT_LEFT, 160);
	m_flickr.InsertColumn(1, Language_ConvertString("Flickr"), LVCFMT_LEFT, 160);
	m_website.InsertColumn(1, Language_ConvertString("Other Website"), LVCFMT_LEFT, 160);

	m_book.InsertColumn(0, Language_ConvertString("Books"), LVCFMT_LEFT, 140);
	m_book.InsertColumn(1, Language_ConvertString("Authors"), LVCFMT_LEFT,250);

	m_bbs.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_book.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_flickr.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_website.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	int i;
	int nItem;
	char temp[8];

	for(i=0;i<chswebsiteTotal;i++)
	{
		sprintf(temp,"%03d",i+1);
		nItem=m_bbs.InsertItem(0,temp);
		m_bbs.SetItemText(nItem,1,chswebsite[i][0]);
	}

	for(i=0;i<flickrTotal;i++)
	{
		sprintf(temp,"%03d",i+1);
		nItem=m_flickr.InsertItem(0,temp);
		m_flickr.SetItemText(nItem,1,flickr[i][0]);
	}

	for(i=0;i<intwebsiteTotal;i++)
	{
		sprintf(temp,"%03d",i+1);
		nItem=m_website.InsertItem(0,temp);
		m_website.SetItemText(nItem,1,intwebsite[i][0]);
	}
	//图书没有连接
	for(i=0;i<bookTotal;i++)
	{
		nItem=m_book.InsertItem(0,book[i][0]);
		m_book.SetItemText(nItem,1,book[i][1]);
	}
}
//单击直接跳转
void CDLGlink::OnClickListWebsite(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* p=	(NM_LISTVIEW *)pNMHDR;
	ShellExecute(this->m_hWnd,NULL,intwebsite[p->iItem][1],NULL,NULL,SW_NORMAL);
}

void CDLGlink::OnClickListBbs(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* p=	(NM_LISTVIEW *)pNMHDR;
	ShellExecute(this->m_hWnd,NULL,chswebsite[p->iItem][1],NULL,NULL,SW_NORMAL);
}

void CDLGlink::OnClickListFlickr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* p=	(NM_LISTVIEW *)pNMHDR;
	ShellExecute(this->m_hWnd,NULL,flickr[p->iItem][1],NULL,NULL,SW_NORMAL);
}

/* 双击事件
void CZogHistory::OnLvnItemActivateZogHistoryList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here

	char str[260];
	m_zogHistoryList.GetItemText(pNMIA->iItem,8,str,260);
	ShellExecute(this->m_hWnd,NULL,str,NULL,NULL,SW_NORMAL);

	*pResult = 0;
}
*/