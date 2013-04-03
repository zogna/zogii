; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDLGsearch
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "zogci.h"

ClassCount=16
Class1=CZogciApp
Class2=CZogciDlg

ResourceCount=17
Resource2=IDD_COLOR
Resource3=IDD_INFOTXT_INFO
Resource4=IDD_ABOUT
Resource5=IDD_MAP
Resource1=IDR_MAINFRAME
Class3=CDLGabout
Resource6=IDD_INFOTXT_PANNEL
Resource7=IDD_LINK
Class4=CDLGinfo
Class5=CDLGlink
Class6=CDLGresult
Class7=CDLGsearch
Class8=CDLGannounce
Resource8=IDD_INFO_TXT
Class9=CDLGResultPannel
Resource9=IDD_RESULT
Class10=CDLGpicture
Resource10=IDD_SEARCH
Class11=CDLGMark
Resource11=IDD_PICWIN
Class12=CDLGInfoTxt
Resource12=IDD_RESULT_PANNEL
Class13=CDLGMap
Class14=DLGpicwin
Resource13=IDD_ZOGCI_DIALOG
Class15=CDLGInfotxtPannel
Resource14=IDD_MARK
Class16=CDLGInfotxtInfo
Resource15=IDD_INFO
Resource16=IDD_Announce
Resource17=IDD_SEARCH_ADULT

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
Control1=IDC_TREE,SysTreeView32,1350631431
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
ControlCount=41
Control1=IDC_EDIT_TXT,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CHECK_SF,button,1342242819
Control4=IDC_CHECK_GE,button,1342242819
Control5=IDC_CHECK_SP,button,1342242819
Control6=IDC_CHECK_SSP,button,1342242819
Control7=IDC_CHECK_ALLNAME,button,1342242819
Control8=IDC_CHECK_DOC,button,1342242819
Control9=IDC_BUTTON_RESET,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_CHECK_ADULT_SIZE_02,button,1342242819
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CHECK_ADULT_SIZE_ANY,button,1342242819
Control14=IDC_CHECK_ADULT_SIZE_25,button,1342242819
Control15=IDC_CHECK_ADULT_SIZE_58,button,1342242819
Control16=IDC_CHECK_ADULT_SIZE_810,button,1342242819
Control17=IDC_CHECK_ADULT_SIZE_10,button,1342242819
Control18=IDC_STATIC,button,1342177287
Control19=IDC_BUTTON_ADULT,button,1342242816
Control20=IDC_BUTTON_LARVA,button,1342242816
Control21=IDC_BUTTON_PUPA,button,1342242816
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,button,1342177287
Control24=IDC_CHECK_LARVA_NORMAL,button,1342246787
Control25=IDC_CHECK_LARVA_BRANCH,button,1342246787
Control26=IDC_CHECK_LARVA_THORN,button,1342246787
Control27=IDC_CHECK_LARVA_ALLHAIR,button,1342246787
Control28=IDC_CHECK_LARVA_HALFHAIR,button,1342246787
Control29=IDC_CHECK_LARVA_NULLHAIR,button,1342246787
Control30=IDC_CHECK_LARVA_FLAT,button,1342246787
Control31=IDC_CHECK_LARVA_ALL,button,1342242819
Control32=IDC_CHECK_PUPA_ALL,button,1342242819
Control33=IDC_CHECK_PUPA_NORMAL,button,1342246787
Control34=IDC_CHECK_PUPA_HAIR,button,1342246787
Control35=IDC_CHECK_PUPA_HARDTHORN,button,1342246787
Control36=IDC_CHECK_PUPA_SOFTTHORN,button,1342246787
Control37=IDC_CHECK_CONTOUR_ANY,button,1342242819
Control38=IDC_CHECK_CONTOUR_ELLIPSE,button,1342242947
Control39=IDC_CHECK_CONTOUR_CIRCLE,button,1342242947
Control40=IDC_CHECK_CONTOUR_RACTANGLE,button,1342242947
Control41=IDC_BUTTON1,button,1342242816

[DLG:IDD_RESULT]
Type=1
Class=CDLGresult
ControlCount=0

[DLG:IDD_INFO]
Type=1
Class=CDLGinfo
ControlCount=10
Control1=IDC_TAB_INFO,SysTabControl32,1342178304
Control2=IDC_STATIC_SF,static,1342308864
Control3=IDC_STATIC_GE,static,1342308864
Control4=IDC_STATIC_SP,static,1342308352
Control5=IDC_STATIC_SSP,static,1342308352
Control6=IDC_STATIC_DISCOVERY,static,1342308352
Control7=IDC_STATIC,static,1342308864
Control8=IDC_STATIC,static,1342308864
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

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
LastObject=IDC_TAB_INFO
VirtualFilter=dWC

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
VirtualFilter=dWC

[CLS:CDLGannounce]
Type=0
HeaderFile=DLGannounce.h
ImplementationFile=DLGannounce.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_A
VirtualFilter=dWC

[DLG:IDD_RESULT_PANNEL]
Type=1
Class=CDLGResultPannel
ControlCount=9
Control1=IDC_BUTTON_First,button,1342242816
Control2=IDC_BUTTON_Previous,button,1342242816
Control3=IDC_BUTTON_Next,button,1342242816
Control4=IDC_BUTTON_Last,button,1342242816
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_BUTTON_Jump,button,1342242816
Control7=IDC_COMBO,combobox,1342242819
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308353

[CLS:CDLGResultPannel]
Type=0
HeaderFile=DLGResultPannel.h
ImplementationFile=DLGResultPannel.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO
VirtualFilter=dWC

[CLS:CDLGpicture]
Type=0
HeaderFile=DLGpicture.h
ImplementationFile=DLGpicture.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGpicture
VirtualFilter=dWC

[DLG:IDD_MARK]
Type=1
Class=CDLGMark
ControlCount=3
Control1=IDC_STATIC,static,1342308353
Control2=IDC_COMBO_COLOR,combobox,1342243347
Control3=IDC_BUTTON_MARK,button,1342242816

[CLS:CDLGMark]
Type=0
HeaderFile=DLGMark.h
ImplementationFile=DLGMark.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGMark
VirtualFilter=dWC

[DLG:IDD_INFO_TXT]
Type=1
Class=CDLGInfoTxt
ControlCount=1
Control1=IDC_EDIT_TXT,edit,1350631428

[CLS:CDLGInfoTxt]
Type=0
HeaderFile=DLGInfoTxt.h
ImplementationFile=DLGInfoTxt.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_TXT
VirtualFilter=dWC

[DLG:IDD_MAP]
Type=1
Class=CDLGMap
ControlCount=1
Control1=IDC_STATIC_MAP,static,1342177806

[CLS:CDLGMap]
Type=0
HeaderFile=DLGMap.h
ImplementationFile=DLGMap.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGMap
VirtualFilter=dWC

[DLG:IDD_PICWIN]
Type=1
Class=DLGpicwin
ControlCount=30
Control1=IDC_BUTTON_PICWIN1,button,1342279552
Control2=IDC_BUTTON_PICWIN2,button,1342275712
Control3=IDC_BUTTON_PICWIN3,button,1342275712
Control4=IDC_BUTTON_PICWIN4,button,1342275712
Control5=IDC_BUTTON_PICWIN5,button,1342275712
Control6=IDC_BUTTON_PICWIN6,button,1342275712
Control7=IDC_BUTTON_PICWIN7,button,1342275712
Control8=IDC_BUTTON_PICWIN8,button,1342275712
Control9=IDC_BUTTON_PICWIN9,button,1342275712
Control10=IDC_BUTTON_PICWIN10,button,1342275712
Control11=IDC_BUTTON_PICWIN11,button,1342275712
Control12=IDC_BUTTON_PICWIN12,button,1342275712
Control13=IDC_BUTTON_PICWIN13,button,1342275712
Control14=IDC_BUTTON_PICWIN14,button,1342275712
Control15=IDC_BUTTON_PICWIN15,button,1342275712
Control16=IDC_BUTTON_PICWIN16,button,1342275712
Control17=IDC_BUTTON_PICWIN17,button,1342275712
Control18=IDC_BUTTON_PICWIN18,button,1342275712
Control19=IDC_BUTTON_PICWIN19,button,1342279552
Control20=IDC_BUTTON_PICWIN20,button,1342275712
Control21=IDC_BUTTON_PICWIN21,button,1342275712
Control22=IDC_BUTTON_PICWIN22,button,1342275712
Control23=IDC_BUTTON_PICWIN23,button,1342275712
Control24=IDC_BUTTON_PICWIN24,button,1342275712
Control25=IDC_BUTTON_PICWIN25,button,1342275712
Control26=IDC_BUTTON_PICWIN26,button,1342275712
Control27=IDC_BUTTON_PICWIN27,button,1342275712
Control28=IDC_BUTTON_PICWIN28,button,1342275712
Control29=IDC_BUTTON_PICWIN29,button,1342275712
Control30=IDC_BUTTON_PICWIN30,button,1342275712

[CLS:DLGpicwin]
Type=0
HeaderFile=DLGpicwin.h
ImplementationFile=DLGpicwin.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_PICWIN1
VirtualFilter=dWC

[DLG:IDD_INFOTXT_PANNEL]
Type=1
Class=CDLGInfotxtPannel
ControlCount=7
Control1=IDC_BUTTON_First,button,1342242816
Control2=IDC_BUTTON_Previous,button,1342242816
Control3=IDC_BUTTON_Next,button,1342242816
Control4=IDC_BUTTON_Last,button,1342242816
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_BUTTON_Jump,button,1342242816
Control7=IDC_STATIC,static,1342308353

[CLS:CDLGInfotxtPannel]
Type=0
HeaderFile=DLGInfotxtPannel.h
ImplementationFile=DLGInfotxtPannel.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGInfotxtPannel
VirtualFilter=dWC

[DLG:IDD_INFOTXT_INFO]
Type=1
Class=CDLGInfotxtInfo
ControlCount=3
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352

[CLS:CDLGInfotxtInfo]
Type=0
HeaderFile=DLGInfotxtInfo.h
ImplementationFile=DLGInfotxtInfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGInfotxtInfo

[DLG:IDD_COLOR]
Type=1
Class=?
ControlCount=12
Control1=IDC_CHECK1,button,1342242947
Control2=IDC_CHECK2,button,1342242947
Control3=IDC_CHECK3,button,1342242947
Control4=IDC_CHECK4,button,1342242947
Control5=IDC_CHECK5,button,1342242947
Control6=IDC_CHECK6,button,1342242947
Control7=IDC_CHECK11,button,1342242947
Control8=IDC_CHECK12,button,1342242947
Control9=IDC_CHECK26,button,1342242947
Control10=IDC_CHECK27,button,1342242947
Control11=IDC_CHECK28,button,1342242947
Control12=IDC_CHECK29,button,1342242947

[DLG:IDD_SEARCH_ADULT]
Type=1
Class=?
ControlCount=22
Control1=IDC_STATIC,button,1342177287
Control2=IDC_CHECK1,button,1342242819
Control3=IDC_CHECK2,button,1342242819
Control4=IDC_CHECK_ADULT_SIZE_02,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_CHECK_ADULT_SIZE_ANY,button,1342242819
Control7=IDC_CHECK_ADULT_SIZE_25,button,1342242819
Control8=IDC_CHECK_ADULT_SIZE_58,button,1342242819
Control9=IDC_CHECK_ADULT_SIZE_810,button,1342242819
Control10=IDC_CHECK_ADULT_SIZE_10,button,1342242819
Control11=IDC_CHECK_ADULT_SIZE_3,button,1342242819
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CHECK_ADULT_SIZE_ANY2,button,1342242819
Control14=IDC_CHECK_ADULT_SIZE_26,button,1342242819
Control15=IDC_CHECK_ADULT_SIZE_59,button,1342242819
Control16=IDC_CHECK_ADULT_SIZE_811,button,1342242819
Control17=IDC_CHECK_ADULT_SIZE_11,button,1342242819
Control18=IDC_CHECK3,button,1342242819
Control19=IDC_CHECK4,button,1342242819
Control20=IDC_CHECK5,button,1342242819
Control21=IDC_CHECK6,button,1342242819
Control22=IDC_CHECK7,button,1342242819

