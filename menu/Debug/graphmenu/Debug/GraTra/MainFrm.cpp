// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "GraTra.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_COMMAND(ID_M_VERTEX, OnMVertex)
	ON_COMMAND(ID_M_ARC, OnMArc)
	ON_COMMAND(ID_M_HINT, OnMHint)
	ON_COMMAND(ID_M_OK, OnMOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;  
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(270,100), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CGraTraView), CSize(100, 100), pContext);
	return TRUE; 
	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnMVertex() 
{
	// TODO: Add your command handler code here
	m_flagPrt=1;
	m_flagCtrl=1;
	Invalidate(true);
	for(int i=0;i<m_CtrlGraph.vertexNum;i++){
		m_CtrlGraph.adjlist[i].vertex=-1;
		m_CtrlGraph.adjlist[i].firstedge=NULL;
		m_VisitVertex[i]=-1;
	}
	m_CtrlGraph.vertexNum=0;
	m_CtrlGraph.edgeNum=0;
	m_countVertex=0;
	m_countPrint=-1;
	::SendMessage(g_TextViewWnd,WM_RETEXT,(WPARAM)1,NULL);
}

void CMainFrame::OnMArc() 
{
	// TODO: Add your command handler code here
	m_flagPrt=1;
	m_flagCtrl=2;
	::SendMessage(g_TextViewWnd,WM_RETEXT,(WPARAM)1,NULL);
}

void CMainFrame::OnMHint() 
{
	// TODO: Add your command handler code here
	CHint dlg;
	dlg.DoModal();
}


void CMainFrame::OnMOk() 
{
	// TODO: Add your command handler code here
	m_flagPrt=1;
	m_flagCtrl=3;
	m_flagRadio=0;
	::SendMessage(g_TextViewWnd,WM_RETEXT,(WPARAM)2,NULL);
}
