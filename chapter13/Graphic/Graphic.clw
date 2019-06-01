; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGraphicView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Graphic.h"
LastPage=0

ClassCount=5
Class1=CGraphicApp
Class2=CGraphicDoc
Class3=CGraphicView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CGraphicApp]
Type=0
HeaderFile=Graphic.h
ImplementationFile=Graphic.cpp
Filter=N

[CLS:CGraphicDoc]
Type=0
HeaderFile=GraphicDoc.h
ImplementationFile=GraphicDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CGraphicView]
Type=0
HeaderFile=GraphicView.h
ImplementationFile=GraphicView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=IDM_ELLIPSE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_LINE




[CLS:CAboutDlg]
Type=0
HeaderFile=Graphic.cpp
ImplementationFile=Graphic.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDM_DOT
Command18=IDM_LINE
Command19=IDM_RECT
Command20=IDM_ELLIPSE
Command21=IDM_SERIALIZE_OUT
Command22=IDM_SERIALIZE_IN
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=IDM_DOT
Command3=IDM_ELLIPSE
Command4=IDM_SERIALIZE_IN
Command5=IDM_LINE
Command6=ID_FILE_NEW
Command7=ID_FILE_OPEN
Command8=IDM_SERIALIZE_OUT
Command9=ID_FILE_PRINT
Command10=IDM_RECT
Command11=ID_FILE_SAVE
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_UNDO
Command14=ID_EDIT_CUT
Command15=ID_NEXT_PANE
Command16=ID_PREV_PANE
Command17=ID_EDIT_COPY
Command18=ID_EDIT_PASTE
Command19=ID_EDIT_CUT
Command20=ID_EDIT_UNDO
CommandCount=20

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8
