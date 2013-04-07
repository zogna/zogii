# Microsoft Developer Studio Project File - Name="zogci" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=zogci - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "zogci.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "zogci.mak" CFG="zogci - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "zogci - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "zogci - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "zogci - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "zogci - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "zogci - Win32 Release"
# Name "zogci - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CeXDib.cpp
# End Source File
# Begin Source File

SOURCE=.\ColourPickerCB.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGabout.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGannounce.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGinfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGInfoTxt.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGInfotxtInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGInfotxtPannel.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGlink.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGMap.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGMark.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGpicwin.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGresult.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGResultPannel.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGsearch.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGSearchElytron.cpp
# End Source File
# Begin Source File

SOURCE=.\DLGSearchPronotum.cpp
# End Source File
# Begin Source File

SOURCE=.\MyHyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\PPDrawManager.cpp
# End Source File
# Begin Source File

SOURCE=.\PPHtmlDrawer.cpp
# End Source File
# Begin Source File

SOURCE=.\PPTooltip.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\zogci.cpp
# End Source File
# Begin Source File

SOURCE=.\zogci.rc
# End Source File
# Begin Source File

SOURCE=.\zogciDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CeXDib.h
# End Source File
# Begin Source File

SOURCE=.\ColourPickerCB.h
# End Source File
# Begin Source File

SOURCE=.\DLGabout.h
# End Source File
# Begin Source File

SOURCE=.\DLGannounce.h
# End Source File
# Begin Source File

SOURCE=.\DLGinfo.h
# End Source File
# Begin Source File

SOURCE=.\DLGInfoTxt.h
# End Source File
# Begin Source File

SOURCE=.\DLGInfotxtInfo.h
# End Source File
# Begin Source File

SOURCE=.\DLGInfotxtPannel.h
# End Source File
# Begin Source File

SOURCE=.\DLGlink.h
# End Source File
# Begin Source File

SOURCE=.\DLGMap.h
# End Source File
# Begin Source File

SOURCE=.\DLGMark.h
# End Source File
# Begin Source File

SOURCE=.\DLGpicwin.h
# End Source File
# Begin Source File

SOURCE=.\DLGresult.h
# End Source File
# Begin Source File

SOURCE=.\DLGResultPannel.h
# End Source File
# Begin Source File

SOURCE=.\DLGsearch.h
# End Source File
# Begin Source File

SOURCE=.\DLGSearchElytron.h
# End Source File
# Begin Source File

SOURCE=.\DLGSearchPronotum.h
# End Source File
# Begin Source File

SOURCE=.\link.h
# End Source File
# Begin Source File

SOURCE=.\map.h
# End Source File
# Begin Source File

SOURCE=.\MyHyperLink.h
# End Source File
# Begin Source File

SOURCE=.\PPDrawManager.h
# End Source File
# Begin Source File

SOURCE=.\PPHtmlDrawer.h
# End Source File
# Begin Source File

SOURCE=.\PPTooltip.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\zogci.h
# End Source File
# Begin Source File

SOURCE=.\zogciDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\contour-circle.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\contour-ellipse.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\contour-rectangle.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Elytron_banded.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Elytron_circle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Elytron_eye.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Elytron_solid.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Elytron_spots.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Elytron_striped.bmp
# End Source File
# Begin Source File

SOURCE=".\res\larva-allhair.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\larva-branch.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\larva-flat.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\larva-halfhair.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\larva-normal.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\larva-nullhair.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\larva-thorn.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Map.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Pronotum_2big.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Pronotum_solid.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Pronotum_spot.bmp
# End Source File
# Begin Source File

SOURCE=".\res\pupa-hair.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\pupa-hardthorn.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\pupa-normal.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\pupa-softthorn.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\zogci.ico
# End Source File
# Begin Source File

SOURCE=.\res\zogci.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
