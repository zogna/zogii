
设置事件
ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST1, OnCustomDraw) 

增加函数
void CNetSDKDemoDlg::OnNMCustomdrawZogTempList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW lplvcd=(LPNMLVCUSTOMDRAW)pNMHDR;
	*pResult=CDRF_DODEFAULT;

	switch(lplvcd->nmcd.dwDrawStage)
	{
	case CDDS_PREPAINT:
		{
			*pResult=CDRF_NOTIFYITEMDRAW;
			return;
		}
	case CDDS_ITEMPREPAINT:
		{
			*pResult=CDRF_NOTIFYSUBITEMDRAW;
			return;
		}
	case CDDS_ITEMPREPAINT|CDDS_SUBITEM:
		{
#if 屏蔽此段为原色
			int nItem=static_cast<int>(lplvcd->nmcd.dwItemSpec);
			COLORREF clrNewTextColor,clrNewBkColor;
			clrNewTextColor=RGB(0,0,0);
			if(nItem%2==0)
			{
				clrNewBkColor=RGB(255,255,0);//偶数行背景色为灰色
			}
			else
			{
				clrNewBkColor=RGB(255,0,0);//奇数行背景色为白色
			}

			lplvcd->clrText=clrNewTextColor;
			lplvcd->clrTextBk=clrNewBkColor;
#else
			char str[260];
			int nItem=static_cast<int>(lplvcd->nmcd.dwItemSpec);
			COLORREF clrNewTextColor,clrNewBkColor;

			m_zogHistoryList.GetItemText(nItem,0,str,260);
			if(NULL!=strstr(str,"12"))
			{
				clrNewBkColor=RGB(255,255,0);//偶数行背景色为灰色
				lplvcd->clrTextBk=clrNewBkColor;
			}
#endif



			*pResult=CDRF_DODEFAULT;
			return;
		}
	}
}
