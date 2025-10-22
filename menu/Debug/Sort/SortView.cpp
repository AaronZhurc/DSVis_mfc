// SortView.cpp : implementation of the CSortView class
//

#include "stdafx.h"
#include "Sort.h"

#include "SortDoc.h"
#include "SortView.h"
#include "GlobalParas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortView

IMPLEMENT_DYNCREATE(CSortView, CView)

BEGIN_MESSAGE_MAP(CSortView, CView)
	//{{AFX_MSG_MAP(CSortView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(WM_REDRAW,OnReDraw)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortView construction/destruction

CSortView::CSortView()
{
	// TODO: add construction code here

}

CSortView::~CSortView()
{
}

BOOL CSortView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSortView drawing

void CSortView::OnDraw(CDC* pDC)
{
	CSortDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_pDC=pDC;
	DrawArray();
}

/////////////////////////////////////////////////////////////////////////////
// CSortView printing

BOOL CSortView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSortView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSortView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSortView diagnostics

#ifdef _DEBUG
void CSortView::AssertValid() const
{
	CView::AssertValid();
}

void CSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSortDoc* CSortView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSortDoc)));
	return (CSortDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSortView message handlers

LRESULT CSortView::OnReDraw(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){
		Invalidate(true);
	}
	return 0;
}

void CSortView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	g_MainViewWnd=this->GetSafeHwnd();
}

void CSortView::DrawArray()
{
	CBrush Brush1;
	Brush1.CreateSolidBrush(RGB(255,23,23));
	CBrush Brush2;
	Brush2.CreateSolidBrush(RGB(0,0,0));
	CBrush Brush3;
	Brush3.CreateSolidBrush(RGB(23,255,23));
	for(int i=0;i<m_list.length;i++){
		if(m_list.r[i].flag==1){
			m_pDC->BeginPath();
			m_pDC->Rectangle(150+20*i,300,170+20*i,270-20*m_list.r[i].s);
			m_pDC->EndPath();
			m_pDC->SelectObject(&Brush1);
			m_pDC->FillPath();
			m_pDC->SetBkMode(TRANSPARENT);
		}else if(m_list.r[i].flag==0){
			m_pDC->BeginPath();
			m_pDC->Rectangle(150+20*i,300,170+20*i,270-20*m_list.r[i].s);
			m_pDC->EndPath();
			m_pDC->SelectObject(&Brush2);
			m_pDC->FillPath();
			m_pDC->SetBkMode(TRANSPARENT);
		}else if(m_list.r[i].flag==2){
			m_pDC->BeginPath();
			m_pDC->Rectangle(150+20*i,300,170+20*i,270-20*m_list.r[i].s);
			m_pDC->EndPath();
			m_pDC->SelectObject(&Brush3);
			m_pDC->FillPath();
			m_pDC->SetBkMode(TRANSPARENT);
		}
		CString c;
		c.Format("%d",m_list.r[i].n);
		m_pDC->TextOut(150+20*i,300,c);
	}
}
