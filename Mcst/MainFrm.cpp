// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Mcst.h"

#include "MainFrm.h"
#include "GlobalParas.h"
#include "Set.h"

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
	ON_WM_CREATE()
	ON_COMMAND(ID_M_EDGE, OnMEdge)
	ON_COMMAND(ID_M_VERTEX, OnMVertex)
	ON_COMMAND(ID_M_WEIGHT, OnMWeight)
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
	if(!m_wndSplitter.CreateStatic(this,1,2))
		return false;
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CMyView),CSize(270,100),pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CMcstView),CSize(100,100),pContext);
	return true;
}

void CMainFrame::OnMVertex() 
{
	// TODO: Add your command handler code here
	m_flagCtrl=1;
	int i;
	for(i=0;i<m_graph.vertexNum;i++){
		m_graph.vertexs[i].x=0;
		m_graph.vertexs[i].y=0;
		m_graph.vertexs[i].edgeNum=0;
	}
	for(i=0;i<m_graph.edgeNum;i++){
		m_graph.edges[i].vertex1=NULL;
		m_graph.edges[i].vertex2=NULL;
		m_graph.edges[i].v1=0;
		m_graph.edges[i].v2=0;
		m_graph.edges[i].mark=0;
		m_graph.edges[i].weight=0;
	}
	m_graph.edgeNum=0;
	m_graph.vertexNum=0;
	m_countVertex=0;
	m_countEdge=0;
	::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
}

void CMainFrame::OnMEdge() 
{
	// TODO: Add your command handler code here
	m_flagCtrl=2;
}

void CMainFrame::OnMWeight() 
{
	// TODO: Add your command handler code here
	CSet dlg;
	dlg.DoModal();
}
