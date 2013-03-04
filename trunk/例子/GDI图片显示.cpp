	init()
{
	int PictureH;
	int PictureW;
	CDC *PictureCDC;
	CDC TempPictureCDC;

tagRECT r;
	
	m_picture.GetWindowRect(&r);
		PictureH=r.bottom-r.top;
	PictureW=r.right-r.left;

		PictureCDC=m_picture.GetDC();

	PictureCDC->SetStretchBltMode(COLORONCOLOR);
	TempPictureCDC.CreateCompatibleDC(PictureCDC);

}



void CRealClientDemoDlg::displayerBMP(char *path)
{
		CBitmap bitmap;
				HBITMAP hbitmap;
	 hbitmap = (HBITMAP)LoadImage(
		NULL,				// handle of the instance that contains the image
		path,
		IMAGE_BITMAP,		// type of image-- can also be IMAGE_CURSOR or IMAGE_ICON 
		0,0,				// desired width and height
		LR_LOADFROMFILE);	// load flags-- with LR_LOADTRANSPARENT makes transparent to bkgrnd
 
	bitmap.Attach(hbitmap);

	oldbmp=TempPictureCDC.SelectObject(&bitmap);

	bitmap.GetObject(sizeof(bmInfo),&bmInfo);
	
	PictureCDC->StretchBlt(0,0,PictureW,PictureH, &TempPictureCDC,	\
						0,0,bmInfo.bmWidth,bmInfo.bmHeight,SRCCOPY);

	TempPictureCDC.SelectObject(oldbmp);
	//bitmap.Detach();

}