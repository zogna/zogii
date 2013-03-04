
VC6��
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TREE, OnNMCustomdrawTreeDevicelist)
VS2008��
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TREE_DEVICELIST, &CNetSDKDemoDlg::OnNMCustomdrawTreeDevicelist)

��״ ������ɫ
void CNetSDKDemoDlg::OnNMCustomdrawTreeDevicelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVCUSTOMDRAW lplvcd=(LPNMTVCUSTOMDRAW)pNMHDR;
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
			//��״�˵��ȼ�
			switch (lplvcd->iLevel)
			{
				// painting all 0-level items blue,
				// and all 1-level items red (GGH)
			case 0:
				//��ѡ�е�״̬ Ĭ�ϰ� ���� δѡ�� ��
				if (lplvcd->nmcd.uItemState == (CDIS_FOCUS | CDIS_SELECTED)) // selected
					lplvcd->clrText = RGB(255, 255, 255);
				else
					lplvcd->clrText = RGB(0, 0, 255);
				break;
			case 1:
				if (lplvcd->nmcd.uItemState == (CDIS_FOCUS | CDIS_SELECTED)) // selected
					lplvcd->clrText = RGB(255, 255, 255);
				else
					lplvcd->clrText = RGB(255, 0, 0);
				break;
			}

			for(i=0;i<ListTotal;i++)
			{
				//	DataList{ HTREEITEM item; //��ָ��}
				if((nItem==(int)DataList[i].item) &&
					(TYPE_Species == DataList[i].type)	)
				{
						lplvcd->clrText = RGB(255,255, 0);
						break;
				}
			}

			*pResult=CDRF_DODEFAULT;
			return;
		}
	}

}
