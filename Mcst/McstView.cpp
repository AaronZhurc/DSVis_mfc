// McstView.cpp : implementation of the CMcstView class
//

#include "stdafx.h"
#include "Mcst.h"

#include "McstDoc.h"
#include "McstView.h"
#include "GlobalParas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMcstView

IMPLEMENT_DYNCREATE(CMcstView, CView)

BEGIN_MESSAGE_MAP(CMcstView, CView)
	//{{AFX_MSG_MAP(CMcstView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_MESSAGE(WM_REDRAW,OnReDraw)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMcstView construction/destruction

CMcstView::CMcstView()
{
	// TODO: add construction code here

}

CMcstView::~CMcstView()
{
}

BOOL CMcstView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMcstView drawing

void CMcstView::OnDraw(CDC* pDC)
{
	CMcstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC memDC;
	m_pDC=&memDC;

	memDC.CreateCompatibleDC(NULL);

	CBitmap m_bmap;
	m_bmap.CreateCompatibleBitmap(pDC,1400,900);
	CBitmap* pOldBit=memDC.SelectObject(&m_bmap);
	memDC.FillSolidRect(0,0,1400,900,RGB(255,255,255));

	DrawVertex();
	DrawEdge();
	
	pDC->BitBlt(0,0,1400,900,&memDC,0,0,SRCCOPY);
	m_bmap.DeleteObject();
	memDC.DeleteDC();
	ReleaseDC(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CMcstView printing

BOOL CMcstView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMcstView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMcstView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMcstView diagnostics

#ifdef _DEBUG
void CMcstView::AssertValid() const
{
	CView::AssertValid();
}

void CMcstView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMcstDoc* CMcstView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMcstDoc)));
	return (CMcstDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMcstView message handlers

void CMcstView::DrawVertex()
{
	CString str;
	int i;
	for(i=0;i<m_graph.vertexNum;i++){
		m_pDC->Ellipse(m_graph.vertexs[i].x-15,m_graph.vertexs[i].y-15,m_graph.vertexs[i].x+15,m_graph.vertexs[i].y+15);
		str.Format("%d",i);
		m_pDC->SetBkMode(TRANSPARENT);
		m_pDC->TextOut(m_graph.vertexs[i].x-5,m_graph.vertexs[i].y-10,str);
	}
}

void CMcstView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flagCtrl==1){
		Invalidate(true);
		m_x=point.x;
		m_y=point.y;
		if(m_x%30<=15&&m_x%30>=0)
			m_x=m_x/30*30;
		else
			m_x=m_x/30*30+30;
		if(m_y%30<=15&&m_y%30>=0)
			m_y=m_y/30*30;
		else
			m_y=m_y/30*30+30;
		m_graph.vertexs[m_countVertex].x=m_x;
		m_graph.vertexs[m_countVertex].y=m_y;
		m_graph.vertexs[m_countVertex].name=m_countVertex;
		m_countVertex++;
		m_graph.vertexNum=m_countVertex;
	}else if(m_flagCtrl==2){
		m_flagPoint=1;
		m_t_x=point.x;
		m_t_y=point.y;
		m_LBD=point;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMcstView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flagPoint==1&&m_flagCtrl==2){
		Invalidate(false);
		m_x=m_t_x+(point.x-m_LBD.x);
		m_y=m_t_y+(point.y-m_LBD.y);
	}
	CView::OnMouseMove(nFlags, point);
}

void CMcstView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flagPoint==1&&m_flagCtrl==2){
		m_flagPoint=0;
		for(int i=0;i<m_graph.vertexNum;i++){
			if(m_graph.vertexs[i].x<=m_t_x+15&&m_graph.vertexs[i].y<=m_t_y+15&&m_graph.vertexs[i].x>=m_t_x-15&&m_graph.vertexs[i].y>=m_t_y-15){
				for(int j=0;j<m_graph.vertexNum;j++){
					if(m_graph.vertexs[j].x<=m_x+15&&m_graph.vertexs[j].y<=m_y+15&&m_graph.vertexs[j].x>=m_x-15&&m_graph.vertexs[j].y>=m_y-15){
						m_graph.edges[m_countEdge].vertex1=&m_graph.vertexs[i];
						m_graph.edges[m_countEdge].vertex2=&m_graph.vertexs[j];
						m_graph.edges[m_countEdge].v1=i;
						m_graph.edges[m_countEdge].v2=j;
						m_graph.edges[m_countEdge].name=m_countEdge;
						m_graph.vertexs[i].edges[m_graph.vertexs[i].edgeNum]=&m_graph.edges[m_countEdge];
						m_graph.vertexs[j].edges[m_graph.vertexs[j].edgeNum]=&m_graph.edges[m_countEdge];
						m_graph.edgeNum=++m_countEdge;
						m_graph.vertexs[i].edgeNum++;
						m_graph.vertexs[j].edgeNum++;	
					}
				}
			}
		}
	}
	CView::OnLButtonUp(nFlags, point);
}

void CMcstView::DrawEdge()
{
	CPen pen1(PS_SOLID,3,RGB(255,0,0));
	CPen pen2(PS_SOLID,1,RGB(0,0,0));
	CString str;
	if(m_flagCtrl==2){
		m_pDC->MoveTo(m_t_x,m_t_y);
		m_pDC->LineTo(m_x,m_y);
		str.Format("%d",m_graph.edgeNum+1);
		m_pDC->SetBkMode(TRANSPARENT);
		m_pDC->TextOut((m_t_x+m_x)/2,(m_t_y+m_y)/2,str);
		for(int i=0;i<m_graph.edgeNum;i++){
			m_pDC->MoveTo(m_graph.edges[i].vertex1->x,m_graph.edges[i].vertex1->y);
			m_pDC->LineTo(m_graph.edges[i].vertex2->x,m_graph.edges[i].vertex2->y);
			str.Format("%d",i+1);
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut((m_graph.edges[i].vertex1->x+m_graph.edges[i].vertex2->x)/2,(m_graph.edges[i].vertex1->y+m_graph.edges[i].vertex2->y)/2,str);
		}
	}else{
		for(int i=0;i<m_graph.edgeNum;i++){
			if(m_graph.edges[i].mark==1){	
				CPen* pOldPen=m_pDC->SelectObject(&pen1);
				m_pDC->MoveTo(m_graph.edges[i].vertex1->x,m_graph.edges[i].vertex1->y);
				m_pDC->LineTo(m_graph.edges[i].vertex2->x,m_graph.edges[i].vertex2->y);
				m_pDC->SelectObject(&pOldPen);
				str.Format("%d",m_graph.edges[i].weight);
				m_pDC->SetBkMode(TRANSPARENT);
				m_pDC->TextOut((m_graph.edges[i].vertex1->x+m_graph.edges[i].vertex2->x)/2,(m_graph.edges[i].vertex1->y+m_graph.edges[i].vertex2->y)/2,str);
			}else{
				CPen* pOldPen=m_pDC->SelectObject(&pen2);
				m_pDC->MoveTo(m_graph.edges[i].vertex1->x,m_graph.edges[i].vertex1->y);
				m_pDC->LineTo(m_graph.edges[i].vertex2->x,m_graph.edges[i].vertex2->y);
				m_pDC->SelectObject(&pOldPen);
				str.Format("%d",m_graph.edges[i].weight);
				m_pDC->SetBkMode(TRANSPARENT);
				m_pDC->TextOut((m_graph.edges[i].vertex1->x+m_graph.edges[i].vertex2->x)/2,(m_graph.edges[i].vertex1->y+m_graph.edges[i].vertex2->y)/2,str);
			}
		}
	}
}

void CMcstView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	g_MainViewWnd=this->GetSafeHwnd();
}

LRESULT CMcstView::OnReDraw(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){	
		Invalidate(true);
	}
	return 0;
}
