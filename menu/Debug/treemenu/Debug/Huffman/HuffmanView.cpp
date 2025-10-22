// HuffmanView.cpp : implementation of the CHuffmanView class
//

#include "stdafx.h"
#include "Huffman.h"

#include "HuffmanDoc.h"
#include "HuffmanView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuffmanView

IMPLEMENT_DYNCREATE(CHuffmanView, CView)

BEGIN_MESSAGE_MAP(CHuffmanView, CView)
	//{{AFX_MSG_MAP(CHuffmanView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(WM_REDRAW,OnReDraw)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuffmanView construction/destruction

CHuffmanView::CHuffmanView()
{
	// TODO: add construction code here

}

CHuffmanView::~CHuffmanView()
{
}

BOOL CHuffmanView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHuffmanView drawing

void CHuffmanView::OnDraw(CDC* pDC)
{
	CHuffmanDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_pDC=pDC;
	if(m_flagPrt==0){
		pDC->TextOut(25,50,"操作提示");
		pDC->TextOut(25,100,"点击\"操作\"菜单下\"设置\"按钮设置叶子节点的数目和权值，叶子节点会进行自动命名");
		pDC->TextOut(25,125,"绿色圆结点为叶子节点，非叶子节点用蓝色方块标识");
		pDC->TextOut(25,150,"在界面左侧控制菜单进行分步控制，界面右侧绘图菜单会出现当前所绘制到的哈夫曼树");
		pDC->TextOut(25,175,"绘制结束后会绘制带有名称、权值和编码的表格");
		pDC->TextOut(25,225,"点击\"帮助\"菜单下\"获取使用帮助\"按钮可重新获取操作提示");
	}
	DrawTree();
	DrawCode();
}

/////////////////////////////////////////////////////////////////////////////
// CHuffmanView printing

BOOL CHuffmanView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHuffmanView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHuffmanView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHuffmanView diagnostics

#ifdef _DEBUG
void CHuffmanView::AssertValid() const
{
	CView::AssertValid();
}

void CHuffmanView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHuffmanDoc* CHuffmanView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHuffmanDoc)));
	return (CHuffmanDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuffmanView message handlers


void CHuffmanView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	g_MainViewWnd=this->GetSafeHwnd();

	CBitmap bmp;
	bmp.LoadBitmapA(MAKEINTRESOURCE(IDB_BITMAP_BG));
	m_bmp.Attach(bmp);
	CDC* pDC=GetDC();
	m_dc.CreateCompatibleDC(pDC);
	ReleaseDC(pDC);
	m_dc.SelectObject(&m_bmp);
}


LRESULT CHuffmanView::OnReDraw(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){	
		Invalidate(true);
		m_flagPrt=1;
		if(m_LeafCtrl->next->next==m_LeafCtrl)
			m_flagCode=1;
		flag_draw=1;
	}
	return 0;
}

void CHuffmanView::DrawTree()
{
	if(flag_draw=1&&m_LeafCtrl){
		Leaves* p=m_LeafCtrl->next;
		while(p!=m_LeafCtrl){
			DrawLeaf(p);
			p=p->next;
		}
	}
	flag_draw=0;
}

void CHuffmanView::DrawLeaf(Leaves *par)
{
	CRect rectDlg;
	GetClientRect(rectDlg);
	int m_w=rectDlg.Width()/10;
	int m_h=rectDlg.Height()/10;
	CBrush Brush1;
	CBrush Brush2;
	Brush1.CreateSolidBrush(RGB(88,214,141));
	Brush2.CreateSolidBrush(RGB(53,152,219));
	if(par){
		CString str;
		str.Format("(%d)", par->weight);
		if(par->lchild&&par->rchild){
			m_pDC->BeginPath();
			m_pDC->Rectangle((par->width+1)*50-20+m_w,(m_TreeHigh-par->height+1)*50-20+m_h,(par->width+1)*50+20+m_w,(m_TreeHigh-par->height+1)*50+20+m_h);
		    m_pDC->EndPath();
			m_pDC->SelectObject(&Brush2);
			m_pDC->FillPath();
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut((par->width+1)*50-7+m_w,(m_TreeHigh-par->height+1)*50-10+m_h,str);
		}else{
			m_pDC->BeginPath();
			m_pDC->Ellipse((par->width+1)*50-20+m_w,(m_TreeHigh-par->height+1)*50-20+m_h,(par->width+1)*50+20+m_w,(m_TreeHigh-par->height+1)*50+20+m_h);	
		    m_pDC->EndPath();
			m_pDC->SelectObject(&Brush1);
			m_pDC->FillPath();
			m_pDC->SetBkMode(TRANSPARENT);
			m_pDC->TextOut((par->width+1)*50-5+m_w,(m_TreeHigh-par->height+1)*50-14+m_h,par->name);
			m_pDC->TextOut((par->width+1)*50-7+m_w,(m_TreeHigh-par->height+1)*50+2+m_h,str);
		}		
		m_pDC->MoveTo((par->width+1)*50+m_w,(m_TreeHigh-par->height+1)*50+20+m_h);
		if(par->lchild)
			m_pDC->LineTo((par->lchild->width+1)*50+m_w,(m_TreeHigh-par->lchild->height+1)*50+m_h);
		m_pDC->MoveTo((par->width+1)*50+m_w,(m_TreeHigh-par->height+1)*50+20+m_h);
		if(par->rchild)
			m_pDC->LineTo((par->rchild->width+1)*50+m_w,(m_TreeHigh-par->rchild->height+1)*50+m_h);
		DrawLeaf(par->lchild);
		DrawLeaf(par->rchild);
	}
}

void CHuffmanView::DrawCode()
{
	int i;
	CRect rectDlg;
	GetClientRect(rectDlg);
	int m_w=rectDlg.Width()/10;
	int m_h=rectDlg.Height()/10;
	if(m_flagCode==1){
		CodeLeaf(m_LeafCtrl->next,'0');
		m_pDC->MoveTo(50+m_w,(m_TreeHigh+2)*50+m_h);
		m_pDC->LineTo(120+(m_LeafNum)*50+m_w,(m_TreeHigh+2)*50+m_h);
		m_pDC->MoveTo(50+m_w,(m_TreeHigh+2)*50+20+m_h);
		m_pDC->LineTo(120+(m_LeafNum)*50+m_w,(m_TreeHigh+2)*50+20+m_h);
		m_pDC->MoveTo(50+m_w,(m_TreeHigh+2)*50+40+m_h);
		m_pDC->LineTo(120+(m_LeafNum)*50+m_w,(m_TreeHigh+2)*50+40+m_h);
	    m_pDC->MoveTo(50+m_w,(m_TreeHigh+2)*50+60+m_h);
		m_pDC->LineTo(120+(m_LeafNum)*50+m_w,(m_TreeHigh+2)*50+60+m_h);
		m_pDC->TextOut(52+m_w,(m_TreeHigh+2)*50+2+m_h,"结点名称");
	    m_pDC->TextOut(52+m_w,(m_TreeHigh+2)*50+22+m_h,"结点权值");
		m_pDC->TextOut(52+m_w,(m_TreeHigh+2)*50+42+m_h,"结点编码");
		m_pDC->MoveTo(120+m_w,(m_TreeHigh+2)*50+m_h);
		m_pDC->LineTo(120+m_w,(m_TreeHigh+2)*50+60+m_h);
		for(i=1;i<m_LeafNum;i++){
			m_pDC->MoveTo(120+50*i+m_w,(m_TreeHigh+2)*50+m_h);
			m_pDC->LineTo(120+50*i+m_w,(m_TreeHigh+2)*50+60+m_h);
			WriteCode(m_LeafCtrl->next);
		}
	}
}

void CHuffmanView::CodeLeaf(Leaves *par, char ch)
{
	int i;
	if(par){
		if(par->parent)
			for(i=0;i<=(m_TreeHigh-par->parent->height);i++){
				par->code[i]=par->parent->code[i];
			}
			par->code[m_TreeHigh-par->height-1]=ch;
			CodeLeaf(par->lchild,'0');
			CodeLeaf(par->rchild,'1');
	}
}

void CHuffmanView::WriteCode(Leaves *par)
{
	CRect rectDlg;
	GetClientRect(rectDlg);
	int m_w=rectDlg.Width()/10;
	int m_h=rectDlg.Height()/10;
	CString strn,strc,strw,temp;
	int i;
	if(par){
		if(!par->rchild&&!par->lchild){
			strn.Format("%c",par->name);
			m_pDC->TextOut(120+50*par->width+2+m_w,(m_TreeHigh+2)*50+2+m_h,strn);
			strw.Format("%d",par->weight);
			m_pDC->TextOut(120+50*par->width+2+m_w,(m_TreeHigh+2)*50+22+m_h,strw);
			strc.Format("%c",par->code[0]);
			for(i=1;i<(m_TreeHigh-par->height);i++){
				temp.Format("%c",par->code[i]);
				strc+=temp;
			}
			m_pDC->TextOut(120+50*par->width+2+m_w,(m_TreeHigh+2)*50+42+m_h,strc);
		}
		WriteCode(par->lchild);
		WriteCode(par->rchild);
	}
}

void CHuffmanView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect=(0);
	GetClientRect(&rect);
	BITMAP bm;
	m_bmp.GetBitmap(&bm);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&m_dc,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
	CView::OnPaint();

	OnPrepareDC(&dc);
    OnDraw(&dc);
	// Do not call CView::OnPaint() for painting messages
}

void CHuffmanView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CView::OnPrepareDC(pDC, pInfo);
}
