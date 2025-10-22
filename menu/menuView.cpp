// menuView.cpp : implementation of the CMenuView class
//

#include "stdafx.h"
#include "menu.h"

#include "menuDoc.h"
#include "menuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuView

IMPLEMENT_DYNCREATE(CMenuView, CView)

BEGIN_MESSAGE_MAP(CMenuView, CView)
	//{{AFX_MSG_MAP(CMenuView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDB_BUTTON_SORT,OnSortButtonDown) 
	ON_BN_CLICKED(IDB_BUTTON_SNQ,OnSnqButtonDown) 
	ON_BN_CLICKED(IDB_BUTTON_TREE,OnTreeButtonDown) 
	ON_BN_CLICKED(IDB_BUTTON_GRAPH,OnGraphButtonDown) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuView construction/destruction

CMenuView::CMenuView()
{
	// TODO: add construction code here

}

CMenuView::~CMenuView()
{
}

BOOL CMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView drawing

void CMenuView::OnDraw(CDC* pDC)
{
	CMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView printing

BOOL CMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenuView diagnostics

#ifdef _DEBUG
void CMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuDoc* CMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuDoc)));
	return (CMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuView message handlers

void CMenuView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect=(0);
	GetClientRect(&rect);
	BITMAP bm;
	m_bmp.GetBitmap(&bm);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&m_dc,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
	CView::OnPaint();
	CFont myFont;
    myFont.CreateFont(70,0,0,0,100,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SWISS, _T("微软雅黑"));
	CFont *poldFont=dc.SelectObject(&myFont); 
	CRect rect1;
	rect1.SetRect(90,18,1000,300); 
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,0)); 
	dc.DrawText(_T("数据结构可视化"),-1,rect1,DT_SINGLELINE); 
	dc.SelectObject(poldFont);
	// Do not call CView::OnPaint() for painting messages
}

void CMenuView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CBitmap bmp;
	bmp.LoadBitmapA(MAKEINTRESOURCE(IDB_BITMAP_BACKG));
	m_bmp.Attach(bmp);
	CDC* pDC=GetDC();
	m_dc.CreateCompatibleDC(pDC);
	ReleaseDC(pDC);
	m_dc.SelectObject(&m_bmp);
	m_buttonsort.LoadBitmaps(IDB_BITMAP_LOGOSORT,IDB_BITMAP_LOGOSORTD); 
	m_buttonsort.SizeToContent(); 
	m_buttonsnq.LoadBitmaps(IDB_BITMAP_LOGOSNQ,IDB_BITMAP_LOGOSNQD); 
	m_buttonsnq.SizeToContent(); 
	m_buttontree.LoadBitmaps(IDB_BITMAP_LOGOTREE,IDB_BITMAP_LOGOTREED); 
	m_buttontree.SizeToContent(); 
	m_buttongraph.LoadBitmaps(IDB_BITMAP_LOGOGRAPH,IDB_BITMAP_LOGOGRAPHD); 
	m_buttongraph.SizeToContent(); 
	Invalidate(false);
}

int CMenuView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect_button(90,111,240,266);
	m_buttonsort.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button,this,IDB_BUTTON_SORT);
	m_buttonsort.ShowWindow(SW_SHOWNORMAL);
	CRect rect_button2(300,111,450,266);
	m_buttonsnq.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button2,this,IDB_BUTTON_SNQ);
	m_buttonsnq.ShowWindow(SW_SHOWNORMAL);
	CRect rect_button3(90,322,240,476);
	m_buttontree.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button3,this,IDB_BUTTON_TREE);
	m_buttontree.ShowWindow(SW_SHOWNORMAL);
	CRect rect_button4(300,322,450,476);
	m_buttongraph.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button4,this,IDB_BUTTON_GRAPH);
	m_buttongraph.ShowWindow(SW_SHOWNORMAL);
	return 0;
}

void CMenuView::OnSortButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="Sort\\Debug\\Sort.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	//AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

void CMenuView::OnSnqButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="snqmenu\\Debug\\snqmenu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

void CMenuView::OnTreeButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="treemenu\\Debug\\treemenu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

void CMenuView::OnGraphButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="graphmenu\\Debug\\graphmenu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


CString CMenuView::GetPath()
{
	CString str_path,str_filePath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	return str_filePath;
}
