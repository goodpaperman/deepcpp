; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNamedPipeSrvView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NamedPipeSrv.h"
LastPage=0

ClassCount=5
Class1=CNamedPipeSrvApp
Class2=CNamedPipeSrvDoc
Class3=CNamedPipeSrvView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg

[CLS:CNamedPipeSrvApp]
Type=0
HeaderFile=NamedPipeSrv.h
ImplementationFile=NamedPipeSrv.cpp
Filter=N

[CLS:CNamedPipeSrvDoc]
Type=0
HeaderFile=NamedPipeSrvDoc.h
ImplementationFile=NamedPipeSrvDoc.cpp
Filter=N

[CLS:CNamedPipeSrvView]
Type=0
HeaderFile=NamedPipeSrvView.h
ImplementationFile=NamedPipeSrvView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDM_PIPE_WRITE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=NamedPipeSrv.cpp
ImplementationFile=NamedPipeSrv.cpp
Filter=D
LastObject=CAboutDlg

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
Command17=IDM_PIPE_CREATE
Command18=IDM_PIPE_READ
Command19=IDM_PIPE_WRITE
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_PIPE_CREATE
Command2=IDM_PIPE_READ
Command3=IDM_PIPE_WRITE
Command4=ID_EDIT_COPY
Command5=ID_FILE_NEW
Command6=ID_FILE_OPEN
Command7=ID_FILE_PRINT
Command8=ID_FILE_SAVE
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_EDIT_CUT
Command17=ID_EDIT_UNDO
CommandCount=17

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

