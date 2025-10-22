; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sort.h"
LastPage=0

ClassCount=7
Class1=CSortApp
Class2=CSortDoc
Class3=CSortView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CMyView
Resource3=IDD_DIALOG_CTRL
Class7=CSet
Resource4=IDD_DIALOG_SET

[CLS:CSortApp]
Type=0
HeaderFile=Sort.h
ImplementationFile=Sort.cpp
Filter=N

[CLS:CSortDoc]
Type=0
HeaderFile=SortDoc.h
ImplementationFile=SortDoc.cpp
Filter=N

[CLS:CSortView]
Type=0
HeaderFile=SortView.h
ImplementationFile=SortView.cpp
Filter=C
LastObject=CSortView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_M_SET




[CLS:CAboutDlg]
Type=0
HeaderFile=Sort.cpp
ImplementationFile=Sort.cpp
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
Command17=ID_M_SET
CommandCount=17

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

[CLS:CMyView]
Type=0
HeaderFile=MyView.h
ImplementationFile=MyView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_STATIC_GAP
VirtualFilter=VWC

[DLG:IDD_DIALOG_CTRL]
Type=1
Class=CMyView
ControlCount=6
Control1=IDC_RADIO_BUBBLE,button,1342308361
Control2=IDC_RADIO_INSERT,button,1342177289
Control3=IDC_RADIO_SHELL,button,1342177289
Control4=IDC_RADIO_QUICK,button,1342177289
Control5=IDC_BUTTON_SORT,button,1342242816
Control6=IDC_STATIC_GAP,static,1342308352

[DLG:IDD_DIALOG_SET]
Type=1
Class=CSet
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_SET_NUM,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_SET_GAP,edit,1350631552
Control5=IDC_BUTTON_OK,button,1342242816
Control6=IDC_BUTTON_GEN,button,1342242816

[CLS:CSet]
Type=0
HeaderFile=Set.h
ImplementationFile=Set.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_SET_NUM2
VirtualFilter=dWC

