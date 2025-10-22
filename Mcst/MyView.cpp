// MyView.cpp : implementation file
//

#include "stdafx.h"
#include "Mcst.h"
#include "MyView.h"
#include "GlobalParas.h"

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
	DDX_Radio(pDX, IDC_RADIO_PRIM, m_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyView, CFormView)
	//{{AFX_MSG_MAP(CMyView)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	//}}AFX_MSG_MAP
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
	m_flagCtrl=1;
	if(m_flagRadio!=m_radio){
		m_flagBuild=0;
		m_i=0;
		m_flagCtrl=0;
		for(int i=0;i<m_graph.edgeNum;i++){
			m_graph.edges[i].mark=0;
		}
		m_flagRadio=m_radio;
	}
	if(m_radio==0){
		Prim();
	}else if(m_radio==1){
		Kruskal();
	}
	::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
}

void CMyView::Kruskal()
{
	int i;
	static int j,k;
	int s1,s2;
	static int f[100];
	if(m_flagBuild==0){
		j=0,k=0;
		for(i=0;i<m_graph.vertexNum;i++){
			f[i]=i;
		}
		m_flagBuild=1;
	}
	for(i=0;i<m_graph.edgeNum;i++){
		m_e[i]=&m_graph.edges[i];
	}
	sortEdge(m_e,m_graph.edgeNum);
	while(k<m_graph.vertexNum-1&&m_flagCtrl==1){
		m_flagCtrl=0;
		s1=f[m_e[j]->v1];
		s2=f[m_e[j]->v2];
		if(s1!=s2){
			m_e[j]->mark=1;
			k++;
			for(i=0;i<m_graph.vertexNum;i++){
				if(f[i]==s2)
					f[i]=s1;
			}
		}
		j++;
	}
}

void CMyView::sortEdge(ENode e[],int num)
{
	ENode temp;
	for(int i=0;i<num;i++){
		for(int j=0;j<num-1-i;j++){
			if(e[j].weight>e[j+1].weight){
				temp = e[j];
				e[j] = e[j+1];
				e[j+1] = temp;
			}
		}
	}
}

void CMyView::Prim()
{
	int j,k;
	static int i;
	int countE=0;
	static int countV;
	if(m_flagBuild==0){
		int k;
		i=0;
		for(k=0;k<100;k++){
			m_e[k]=NULL;
		}
		for(k=0;k<100;k++){
			m_v[k]=0;
		}
		countV=1;
		m_flagBuild=1;
	}
	int edgeNum=0;
	eNode* min;
	m_v[0]=0;
	for(i=0;i<m_graph.vertexNum&&m_flagCtrl==1;i++){
		if(i!=0)
			m_flagCtrl=0;
		edgeNum=0;
		countE=0;
		for(j=0;j<i;j++){
			for(k=0;k<m_graph.vertexs[m_v[j]].edgeNum;k++){
				m_e[countE++]=&m_graph.edges[m_graph.vertexs[m_v[j]].edges[k]->name];
			}
			edgeNum+=m_graph.vertexs[m_v[j]].edgeNum;
		}
		sortEdge(m_e,edgeNum);
		for(j=0;j<edgeNum;j++){
			if(CheckDup(*m_e[j],countV)==0){
				m_e[j]->mark=1;
				m_v[countV++]=m_add;
				break;
			}
		}
	}
}

int CMyView::CheckDup(ENode e,int n)
{
	int i;
	int flag1=0,flag2=0;
	if(e.mark==1)
		return 1;
	for(i=0;i<n;i++){
		if(e.v1==m_v[i]){
			flag1++;
			break;
		}
	}
	for(i=0;i<n;i++){
		if(e.v2==m_v[i]){
			flag2++;
			break;
		}
	}
	if(flag1==1&&flag2==1)
		return 1;
	else if(flag1==0&&flag2!=0){
		m_add=e.v1;
		return 0;
	}else if(flag1!=0&&flag2==0){
		m_add=e.v2;
		return 0;
	}else
		return 0;
}

void CMyView::sortEdge(ENode *e[], int num)
{
	ENode* temp;
	for(int i=0;i<num;i++){
		for(int j=0;j<num-1-i;j++){
			if(e[j]->weight>e[j+1]->weight){
				temp = e[j];
				e[j] = e[j+1];
				e[j+1] = temp;
			}
		}
	}
}

void CMyView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_i=0;
	m_flagCtrl=0;
	m_flagRadio=0;
}


