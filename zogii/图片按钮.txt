	
	// TODO: Add extra initialization here
		HBITMAP hbitmap = (HBITMAP)LoadImage(
		NULL,				// handle of the instance that contains the image
	//	"Wzd2.bmp",			// name or identifier of image
	//"capture.jpg",
	"haha.bmp",
		IMAGE_BITMAP,		// type of image-- can also be IMAGE_CURSOR or IMAGE_ICON 
		150,150,				//设定图片显示大小 desired width and height
		LR_LOADFROMFILE);	// load flags-- with LR_LOADTRANSPARENT makes transparent to bkgrnd

CButton* aa=(CButton *)GetDlgItem(IDC_BUTTON1);
aa->SetBitmap(hbitmap);
