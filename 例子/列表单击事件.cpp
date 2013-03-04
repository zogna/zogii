	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)

void CMy222Dlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
NM_LISTVIEW* p=	(NM_LISTVIEW *)pNMHDR;
 //ÐòºÅ p->iItem

	*pResult = 0;
}
