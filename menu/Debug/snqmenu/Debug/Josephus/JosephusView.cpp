// JosephusView.cpp : implementation of the CJosephusView class
//

#include "stdafx.h"
#include "Josephus.h"

#include "JosephusDoc.h"
#include "JosephusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJosephusView

IMPLEMENT_DYNCREATE(CJosephusView, CView)

BEGIN_MESSAGE_MAP(CJosephusView, CView)
	//{{AFX_MSG_MAP(CJosephusView)
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
// CJosephusView construction/destruction

CJosephusView::CJosephusView()
{
	// TODO: add construction code here

}

CJosephusView::~CJosephusView()
{
}

BOOL CJosephusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CJosephusView drawing

void CJosephusView::OnDraw(CDC* pDC)
{
	CJosephusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(m_flagPrt==0){
		pDC->TextOut(25,50,"操作提示");
		pDC->TextOut(25,100,"点击\"操作\"菜单下\"设置\"按钮，对结点数、起始结点和步长进行设置");
		pDC->TextOut(25,125,"通过左侧控制栏对右侧画布的演示进行分步控制，红色结点表示已经被移除出去的结点");
		pDC->TextOut(25,175,"点击\"帮助\"菜单下\"获取使用帮助\"按钮可重新获取操作提示");
	}
	m_pDC=pDC;
	DrawList();
}

/////////////////////////////////////////////////////////////////////////////
// CJosephusView printing

BOOL CJosephusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJosephusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJosephusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJosephusView diagnostics

#ifdef _DEBUG
void CJosephusView::AssertValid() const
{
	CView::AssertValid();
}

void CJosephusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJosephusDoc* CJosephusView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJosephusDoc)));
	return (CJosephusDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJosephusView message handlers

void CJosephusView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	g_MainViewWnd=this->GetSafeHwnd();
}

LRESULT CJosephusView::OnReDraw(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){
		m_flagPrt=1;
		Invalidate(true);
	}
	return 0;
}

void CJosephusView::DrawList()
{
	CRect rectDlg;
	GetClientRect(rectDlg);
	int m_w=rectDlg.Width()/15;
	int m_h=rectDlg.Height()/15;
	int i,j;
	CString str;
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(232,76,61));
	const double PI=3.14;
	double t=2*PI/m_num;
	for(i=0;i<m_num;i++){
		m_pDC->Ellipse((int)200-sin(-t*i)*100-15+m_w,(int)200-cos(-t*i)*100-15+m_h,(int)200-sin(-t*i)*100+15+m_w,(int)200-cos(-t*i)*100+15+m_h);
		str.Format("%d",i);
		m_pDC->SetBkMode(TRANSPARENT);
		m_pDC->TextOut((int)200-sin(-t*i)*100-5+m_w,(int)200-cos(-t*i)*100-10+m_h,str);
	}
	for(i=0;i<m_num;i++){
		if(m_putout[i]!=-1){
			m_pDC->BeginPath();
			m_pDC->Ellipse((int)200-sin(-t*m_putout[i])*100-14+m_w,(int)200-cos(-t*m_putout[i])*100-14+m_h,(int)200-sin(-t*m_putout[i])*100+14+m_w,(int)200-cos(-t*m_putout[i])*100+14+m_h);
			m_pDC->EndPath();
			m_pDC->SelectObject(&Brush);
			m_pDC->FillPath();		
			m_pDC->SetBkMode(TRANSPARENT);
			str.Format("%d",m_putout[i]);
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut((int)200-sin(-t*m_putout[i])*100-5+m_w,(int)200-cos(-t*m_putout[i])*100-10+m_h,str);
		}
	}
}
