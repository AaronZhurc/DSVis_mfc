// MyView.cpp : implementation file
//

#include "stdafx.h"
#include "GraTra.h"
#include "MyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CFormView)

CMyView::CMyView()
	: CFormView(CMyView::IDD)
{
	//{{AFX_DATA_INIT(CMyView)
	m_result = _T("");
	m_radio = -1;
	//}}AFX_DATA_INIT
}

CMyView::~CMyView()
{
}

void CMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyView)
	DDX_Text(pDX, IDC_STATIC_RESULT, m_result);
	DDX_Radio(pDX, IDC_RADIO_DFS, m_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyView, CFormView)
	//{{AFX_MSG_MAP(CMyView)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_RADIO_BFS, OnRadioBfs)
	ON_BN_CLICKED(IDC_RADIO_DFS, OnRadioDfs)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RETEXT,ResetText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_tra!=m_radio)
		m_flagRadio=0;
	m_tra=m_radio;
	CString str;
	m_result.Empty();
	for(int i=0;i<=m_countPrint&&m_VisitVertex[i]!=-1;i++){
		str.Format("%d ",m_VisitVertex[i]);
		m_result+=str;
	}
	if(m_flagRadio==0){
		Traversal();
		m_flagRadio=1;
	}
	UpdateData(false);
	::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
	if(m_countPrint==m_countVertex)
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("结束");
}

void CMyView::Traversal()
{
	for(int i=0;i<30;i++){
		m_VisitVertex[i]=-1;
		visited[i]=0;
	}
	m_countAdj=0;
	m_countPrint=-1;
	if(m_tra==0){	
		DFStraverse();
	}else if(m_tra==1){
		BFStraverse();
	}
	Invalidate(true);
}

void CMyView::DFStraverse()
{
	int v;
	for(v=0;v<m_CtrlGraph.vertexNum;v++)
		visited[v]=0;
	for(v=0;v<m_CtrlGraph.vertexNum;v++)
		if(!visited[v])
			DFS(v);
}

void CMyView::DFS(int v)
{
	EdgeNode* p;
	int w;
	m_VisitVertex[m_countAdj]=v;
	m_countAdj++;
	visited[v]=1;
	for(p=m_CtrlGraph.adjlist[v].firstedge;p;p=p->next){
		w=p->adjvertex;
		if(!visited[w])
			DFS(w);
	}
}

void CMyView::BFStraverse()
{
	int v;
	for(v=0;v<m_CtrlGraph.vertexNum;v++)
		visited[v]=0;
	for(v=0;v<m_CtrlGraph.vertexNum;v++)
		if(!visited[v])
			BFS(v);
}

void CMyView::BFS(int v)
{
EdgeNode* p;
	int u,w;
	std::queue<int> Q;
	m_VisitVertex[m_countAdj]=v;
	m_countAdj++;
	visited[v]=1;
	Q.push(v);
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		for(p=m_CtrlGraph.adjlist[u].firstedge;p;p=p->next){
			w=p->adjvertex;
			if(!visited[w]){
				m_VisitVertex[m_countAdj]=w;
	            m_countAdj++;
				visited[w]=1;
				Q.push(w);
			}
		}
	}
}

void CMyView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_radio=0;
	g_TextViewWnd=this->GetSafeHwnd();
	m_flagText=1;
	UpdateData(false);

}

void CMyView::ResetText(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("绘图中");
		m_flagText=1;
	}
	else if(wParam==2){
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
		m_flagText=0;
	}
}

void CMyView::OnRadioBfs() 
{
	// TODO: Add your control notification handler code here
	if(m_tra==0&&m_flagText==0)
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
}

void CMyView::OnRadioDfs() 
{
	// TODO: Add your control notification handler code here
	if(m_tra==1&&m_flagText==0)
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
}
