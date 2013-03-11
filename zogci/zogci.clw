; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDLGlink
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "zogci.h"

ClassCount=8
Class1=CZogciApp
Class2=CZogciDlg

ResourceCount=8
Resource2=IDD_Announce
Resource3=IDD_ABOUT
Resource4=IDD_ZOGCI_DIALOG
Resource5=IDD_SEARCH
Resource1=IDR_MAINFRAME
Class3=CDLGabout
Resource6=IDD_INFO
Resource7=IDD_RESULT
Class4=CDLGinfo
Class5=CDLGlink
Class6=CDLGresult
Class7=CDLGsearch
Class8=CDLGannounce
Resource8=IDD_LINK

[CLS:CZogciApp]
Type=0
HeaderFile=zogci.h
ImplementationFile=zogci.cpp
Filter=N

[CLS:CZogciDlg]
Type=0
HeaderFile=zogciDlg.h
ImplementationFile=zogciDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CZogciDlg



[DLG:IDD_ZOGCI_DIALOG]
Type=1
Class=CZogciDlg
ControlCount=2
Control1=IDC_TREE,SysTreeView32,1350631424
Control2=IDC_TAB_MAIN,SysTabControl32,1342178304

[DLG:IDD_ABOUT]
Type=1
Class=CDLGabout
ControlCount=11
Control1=IDC_Announce,button,1342242816
Control2=IDC_Language,combobox,1344339971
Control3=IDC_STATIC,static,1342308353
Control4=IDC_LanguageButton,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_Authors,static,1342308352
Control7=IDC_EMAIL,static,1342308352
Control8=IDC_WEBSITE,static,1342308352
Control9=IDC_SOFTVER,static,1342308352
Control10=IDC_DATABASEVER,static,1342308352
Control11=IDC_ADDR,static,1342308352

[DLG:IDD_SEARCH]
Type=1
Class=CDLGsearch
ControlCount=0

[DLG:IDD_RESULT]
Type=1
Class=CDLGresult
ControlCount=0

[DLG:IDD_INFO]
Type=1
Class=CDLGinfo
ControlCount=0

[CLS:CDLGabout]
Type=0
HeaderFile=DLGabout.h
ImplementationFile=DLGabout.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGabout
VirtualFilter=dWC

[DLG:IDD_Announce]
Type=1
Class=CDLGannounce
ControlCount=1
Control1=IDC_EDIT_A,edit,1342244868

[DLG:IDD_LINK]
Type=1
Class=CDLGlink
ControlCount=4
Control1=IDC_LIST_WEBSITE,SysListView32,1350631441
Control2=IDC_LIST_BBS,SysListView32,1350631441
Control3=IDC_LIST_BOOK,SysListView32,1350631441
Control4=IDC_LIST_FLICKR,SysListView32,1350631441

[CLS:CDLGinfo]
Type=0
HeaderFile=DLGinfo.h
ImplementationFile=DLGinfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGinfo

[CLS:CDLGlink]
Type=0
HeaderFile=DLGlink.h
ImplementationFile=DLGlink.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_WEBSITE
VirtualFilter=dWC

[CLS:CDLGresult]
Type=0
HeaderFile=DLGresult.h
ImplementationFile=DLGresult.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGresult

[CLS:CDLGsearch]
Type=0
HeaderFile=DLGsearch.h
ImplementationFile=DLGsearch.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGsearch

[CLS:CDLGannounce]
Type=0
HeaderFile=DLGannounce.h
ImplementationFile=DLGannounce.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_A
VirtualFilter=dWC

