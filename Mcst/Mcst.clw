; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Mcst.h"
LastPage=0

ClassCount=7
Class1=CMcstApp
Class2=CMcstDoc
Class3=CMcstView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_DIALOG_CTRL
Class6=CMyView
Resource3=IDD_ABOUTBOX
Class7=CSet
Resource4=IDD_DIALOG_SET

[CLS:CMcstApp]
Type=0
HeaderFile=Mcst.h
ImplementationFile=Mcst.cpp
Filter=N

[CLS:CMcstDoc]
Type=0
HeaderFile=McstDoc.h
ImplementationFile=McstDoc.cpp
Filter=N

[CLS:CMcstView]
Type=0
HeaderFile=McstView.h
ImplementationFile=McstView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMcstView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_M_VERTEX




[CLS:CAboutDlg]
Type=0
HeaderFile=Mcst.cpp
ImplementationFile=Mcst.cpp
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
Command17=ID_M_VERTEX
Command18=ID_M_EDGE
Command19=ID_M_WEIGHT
CommandCount=19

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
LastObject=CMyView
VirtualFilter=VWC

[DLG:IDD_DIALOG_CTRL]
Type=1
Class=CMyView
ControlCount=3
Control1=IDC_RADIO_PRIM,button,1342308361
Control2=IDC_RADIO_KRUS,button,1342177289
Control3=IDC_BUTTON_NEXT,button,1342242816

[DLG:IDD_DIALOG_SET]
Type=1
Class=CSet
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_SET_WEIGHT,edit,1350631552
Control3=IDC_BUTTON_OK,button,1342242816

[CLS:CSet]
Type=0
HeaderFile=Set.h
ImplementationFile=Set.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSet

