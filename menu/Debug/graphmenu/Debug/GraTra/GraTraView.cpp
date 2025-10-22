// GraTraView.cpp : implementation of the CGraTraView class
//

#include "stdafx.h"
#include "GraTra.h"

#include "GraTraDoc.h"
#include "GraTraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraTraView

IMPLEMENT_DYNCREATE(CGraTraView, CView)

BEGIN_MESSAGE_MAP(CGraTraView, CView)
	//{{AFX_MSG_MAP(CGraTraView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(WM_REDRAW,OnReDraw)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraTraView construction/destruction

CGraTraView::CGraTraView()
{
	// TODO: add construction code here

}

CGraTraView::~CGraTraView()
{
}

BOOL CGraTraView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraTraView drawing

void CGraTraView::OnDraw(CDC* pDC)
{
	CGraTraDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC memDC;
	m_pDC=&memDC;

	memDC.CreateCompatibleDC(NULL);

	CBitmap m_bmap;
	m_bmap.CreateCompatibleBitmap(pDC,1400,900);
	CBitmap* pOldBit=memDC.SelectObject(&m_bmap);
	memDC.FillSolidRect(0,0,1400,900,RGB(255,255,255));

	CRect rect=(0);
	GetClientRect(&rect);
	BITMAP bm;
	m_bmp.GetBitmap(&bm);
	memDC.StretchBlt(0,0,rect.Width(),rect.Height(),&m_dc,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
	
	if(m_flagPrt==0){
		m_pDC->TextOut(25,25,"操作提示");
		m_pDC->TextOut(25,75,"结点与边的创建");
		m_pDC->TextOut(25,100,"点击\"操作\"菜单，点击\"创建点\"后，请在界面右侧的画布通过点击绘制点");
		m_pDC->TextOut(25,125,"创建完点后，点击\"操作\"菜单,再点击\"创建边\"后");
		m_pDC->TextOut(25,150,"请在界面右侧的画布用鼠标将连线从一个点拖动到另一个点上以创建边");
		m_pDC->TextOut(25,175,"最后，请点击\"操作\"菜单内\"确认\"按钮以开始遍历");
		m_pDC->TextOut(25,200,"请注意，本程序创建的是有向图，如要创建无向图还请双向绘制边");
		m_pDC->TextOut(25,250,"开始遍历");
		m_pDC->TextOut(25,275,"请在界面左侧控制菜单选择遍历方式");
		m_pDC->TextOut(25,300,"选择完遍历方式后，请通过界面左侧控制菜单内的\"下一步\"按钮进行分步遍历的演示");
		m_pDC->TextOut(25,325,"右侧画布中，红色标示当前遍历到的结点，绿色标示已经遍历过的结点");
		m_pDC->TextOut(25,350,"白色表示还没有遍历过的结点");
		m_pDC->TextOut(25,400,"点击\"帮助\"菜单下\"获取使用帮助\"按钮可重新获取操作提示");
	}

	DrawVertex();
	DrawArc();

	pDC->BitBlt(0,0,1400,900,&memDC,0,0,SRCCOPY);
	m_bmap.DeleteObject();
	memDC.DeleteDC();
	ReleaseDC(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CGraTraView printing

BOOL CGraTraView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraTraView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing

}

void CGraTraView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraTraView diagnostics

#ifdef _DEBUG
void CGraTraView::AssertValid() const
{
	CView::AssertValid();
}

void CGraTraView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraTraDoc* CGraTraView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraTraDoc)));
	return (CGraTraDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraTraView message handlers

void CGraTraView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	g_MainViewWnd=this->GetSafeHwnd();
	m_flagPoint=0;
	m_CtrlGraph.edgeNum=0;
	m_CtrlGraph.vertexNum=0;
	for(int i=0;i<30;i++){
		m_VisitVertex[i]=-1;
	}

	CBitmap bmp;
	bmp.LoadBitmapA(MAKEINTRESOURCE(IDB_BITMAP_BG));
	m_bmp.Attach(bmp);
	CDC* pDC=GetDC();
	m_dc.CreateCompatibleDC(pDC);
	ReleaseDC(pDC);
	m_dc.SelectObject(&m_bmp);
}

void CGraTraView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flagCtrl==1&&m_countVertex<30){
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
		m_CtrlGraph.adjlist[m_countVertex].x=m_x;
		m_CtrlGraph.adjlist[m_countVertex].y=m_y;
		m_CtrlGraph.adjlist[m_countVertex].firstedge=NULL;
		m_CtrlGraph.adjlist[m_countVertex].vertex=m_countVertex;
		m_countVertex++;
		m_CtrlGraph.vertexNum=m_countVertex;
	}else if(m_flagCtrl==2){
		m_flagPoint=1;
		m_t_x=point.x;
		m_t_y=point.y;
		m_LBD=point;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CGraTraView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	EdgeNode* p;
	if(m_flagPoint==1&&m_flagCtrl==2){
		m_flagPoint=0;
		for(int i=0;i<m_CtrlGraph.vertexNum;i++){
			if(m_CtrlGraph.adjlist[i].x<=m_t_x+15&&m_CtrlGraph.adjlist[i].y<=m_t_y+15&&m_CtrlGraph.adjlist[i].x>=m_t_x-15&&m_CtrlGraph.adjlist[i].y>=m_t_y-15&&m_CtrlGraph.adjlist[i].vertex!=-1){
				for(int j=0;j<m_CtrlGraph.vertexNum;j++){
					if(m_CtrlGraph.adjlist[j].x<=m_x+15&&m_CtrlGraph.adjlist[j].y<=m_y+15&&m_CtrlGraph.adjlist[j].x>=m_x-15&&m_CtrlGraph.adjlist[j].y>=m_y-15&&m_CtrlGraph.adjlist[i].vertex!=-1){
						p=(EdgeNode*)malloc(sizeof(EdgeNode));
						p->adjvertex=j;
						p->next=m_CtrlGraph.adjlist[i].firstedge;
						m_CtrlGraph.adjlist[i].firstedge=p;
						m_CtrlGraph.edgeNum++;
					}
				}
			}
		}
	}
	CView::OnLButtonUp(nFlags, point);
}

void CGraTraView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flagPoint==1&&m_flagCtrl==2){
		Invalidate(false);
		m_x=m_t_x+(point.x-m_LBD.x);
		m_y=m_t_y+(point.y-m_LBD.y);
	}
	CView::OnMouseMove(nFlags, point);
}

void CGraTraView::DrawVertex()
{
	int i;
	CString str;
	CBrush Brush1;
	CBrush Brush2;
	Brush1.CreateSolidBrush(RGB(88,214,141));
	Brush2.CreateSolidBrush(RGB(232,76,61));
	for(i=0;i<m_CtrlGraph.vertexNum;i++){
		if(m_CtrlGraph.adjlist[i].vertex!=-1){
			m_pDC->Ellipse(m_CtrlGraph.adjlist[i].x-15,m_CtrlGraph.adjlist[i].y-15,m_CtrlGraph.adjlist[i].x+15,m_CtrlGraph.adjlist[i].y+15);
			str.Format("%d",m_CtrlGraph.adjlist[i].vertex);
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut(m_CtrlGraph.adjlist[i].x-5,m_CtrlGraph.adjlist[i].y-10,str);
		}
	}
	if(m_flagCtrl==3){
		for(i=0;i<=m_countPrint&&m_VisitVertex[i]!=-1;i++){
			m_pDC->BeginPath();
			m_pDC->MoveTo(m_CtrlGraph.adjlist[m_VisitVertex[i]].x-14,m_CtrlGraph.adjlist[m_VisitVertex[i]].y-14);
			m_pDC->Ellipse(m_CtrlGraph.adjlist[m_VisitVertex[i]].x-14,m_CtrlGraph.adjlist[m_VisitVertex[i]].y-14,m_CtrlGraph.adjlist[m_VisitVertex[i]].x+14,m_CtrlGraph.adjlist[m_VisitVertex[i]].y+14);
			m_pDC->EndPath();
			m_pDC->SelectObject(&Brush1);
			m_pDC->FillPath();
			str.Format("%d",m_CtrlGraph.adjlist[m_VisitVertex[i]].vertex);
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut(m_CtrlGraph.adjlist[m_VisitVertex[i]].x-5,m_CtrlGraph.adjlist[m_VisitVertex[i]].y-10,str);
		}
		if(m_VisitVertex[m_countPrint]!=-1){
			m_pDC->BeginPath();
			m_pDC->MoveTo(m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].x-14,m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].y-14);
			m_pDC->Ellipse(m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].x-14,m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].y-14,m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].x+14,m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].y+14);
			m_pDC->EndPath();
			m_pDC->SelectObject(&Brush2);
			m_pDC->FillPath();
			str.Format("%d",m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].vertex);
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut(m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].x-5,m_CtrlGraph.adjlist[m_VisitVertex[m_countPrint]].y-10,str);
		}
	}
}

void CGraTraView::DrawArc()
{
	const double PI=3.14;
	double t=PI/6;
	double l,a;
	int x,y;
	EdgeNode* p;
	for(int i=0;i<m_CtrlGraph.vertexNum;i++){
		p=m_CtrlGraph.adjlist[i].firstedge;
		while(p){
			m_pDC->MoveTo(m_CtrlGraph.adjlist[i].x,m_CtrlGraph.adjlist[i].y);
			for(int j=0;j<m_CtrlGraph.vertexNum;j++){
				if(m_CtrlGraph.adjlist[j].vertex==p->adjvertex){
					x=m_CtrlGraph.adjlist[i].x-m_CtrlGraph.adjlist[j].x;
					y=m_CtrlGraph.adjlist[i].y-m_CtrlGraph.adjlist[j].y;
					a=pow(x,2)+pow(y,2);
					if(a!=0){
						l=20/sqrt(a);
						m_pDC->LineTo(m_CtrlGraph.adjlist[j].x,m_CtrlGraph.adjlist[j].y);
						m_pDC->LineTo((int)(l*(x*cos(-t)-y*sin(-t))+m_CtrlGraph.adjlist[j].x),(int)(l*(x*sin(-t)+y*cos(-t))+m_CtrlGraph.adjlist[j].y));
						m_pDC->MoveTo(m_CtrlGraph.adjlist[j].x,m_CtrlGraph.adjlist[j].y);
						m_pDC->LineTo((int)(l*(x*cos(t)-y*sin(t))+m_CtrlGraph.adjlist[j].x),(int)(l*(x*sin(t)+y*cos(t))+m_CtrlGraph.adjlist[j].y));
					}
				}
			}
			p=p->next;
		}
	}
	if(m_flagCtrl==2){
		x=m_t_x-m_x;
		y=m_t_y-m_y;
		a=pow(x,2)+pow(y,2);
		if(a!=0){
			l=20/sqrt(a);
			m_pDC->MoveTo(m_t_x,m_t_y);
			m_pDC->LineTo(m_x,m_y);
			m_pDC->LineTo((int)(l*(x*cos(-t)-y*sin(-t))+m_x),(int)(l*(x*sin(-t)+y*cos(-t))+m_y));
			m_pDC->MoveTo(m_x,m_y);
			m_pDC->LineTo((int)(l*(x*cos(t)-y*sin(t))+m_x),(int)(l*(x*sin(t)+y*cos(t))+m_y));
		}
	}
}



LRESULT CGraTraView::OnReDraw(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){
		if(m_flagCtrl==3&&m_countPrint!=m_countVertex){
			m_countPrint++;
			Invalidate(true);
		}
	}
	return 0;
}
