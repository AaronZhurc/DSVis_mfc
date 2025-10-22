; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GraTra.h"
LastPage=0

ClassCount=7
Class1=CGraTraApp
Class2=CGraTraDoc
Class3=CGraTraView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_DIALOG_CTRL
Class6=CMyView
Resource3=IDD_ABOUTBOX
Class7=CHint
Resource4=IDD_DIALOG_HINT

[CLS:CGraTraApp]
Type=0
HeaderFile=GraTra.h
ImplementationFile=GraTra.cpp
Filter=N

[CLS:CGraTraDoc]
Type=0
HeaderFile=GraTraDoc.h
ImplementationFile=GraTraDoc.cpp
Filter=N

[CLS:CGraTraView]
Type=0
HeaderFile=GraTraView.h
ImplementationFile=GraTraView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGraTraView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_M_ARC
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=GraTra.cpp
ImplementationFile=GraTra.cpp
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
Command16=ID_M_HINT
Command17=ID_APP_ABOUT
Command18=ID_M_VERTEX
Command19=ID_M_ARC
Command20=ID_M_OK
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

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

[DLG:IDD_DIALOG_CTRL]
Type=1
Class=CMyView
ControlCount=8
Control1=IDC_BUTTON_NEXT,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC_RESULT,static,1342308352
Control7=IDC_RADIO_DFS,button,1342308361
Control8=IDC_RADIO_BFS,button,1342177289

[CLS:CMyView]
Type=0
HeaderFile=MyView.h
ImplementationFile=MyView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_RADIO_DFS
VirtualFilter=VWC

[DLG:IDD_DIALOG_HINT]
Type=1
Class=CHint
ControlCount=10
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_BUTTON_OK,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

[CLS:CHint]
Type=0
HeaderFile=Hint.h
ImplementationFile=Hint.cpp
BaseClass=CDialog
Filter=D
LastObject=CHint
VirtualFilter=dWC

