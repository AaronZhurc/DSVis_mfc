// graphmenuView.cpp : implementation of the CGraphmenuView class
//

#include "stdafx.h"
#include "graphmenu.h"

#include "graphmenuDoc.h"
#include "graphmenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuView

IMPLEMENT_DYNCREATE(CGraphmenuView, CView)

BEGIN_MESSAGE_MAP(CGraphmenuView, CView)
	//{{AFX_MSG_MAP(CGraphmenuView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDB_BUTTON_BACK,OnBackButtonDown) 
	ON_BN_CLICKED(IDB_BUTTON_TRA,OnTraButtonDown) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuView construction/destruction

CGraphmenuView::CGraphmenuView()
{
	// TODO: add construction code here

}

CGraphmenuView::~CGraphmenuView()
{
}

BOOL CGraphmenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuView drawing

void CGraphmenuView::OnDraw(CDC* pDC)
{
	CGraphmenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuView printing

BOOL CGraphmenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphmenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphmenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuView diagnostics

#ifdef _DEBUG
void CGraphmenuView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphmenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphmenuDoc* CGraphmenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphmenuDoc)));
	return (CGraphmenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuView message handlers

void CGraphmenuView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CBitmap bmp;
	bmp.LoadBitmapA(MAKEINTRESOURCE(IDB_BITMAP_BG));
	m_bmp.Attach(bmp);
	CDC* pDC=GetDC();
	m_dc.CreateCompatibleDC(pDC);
	ReleaseDC(pDC);
	m_dc.SelectObject(&m_bmp);
	m_buttonback.LoadBitmaps(IDB_BITMAP_BACK,IDB_BITMAP_BACKD); 
	m_buttonback.SizeToContent(); 
	m_buttontra.LoadBitmaps(IDB_BITMAP_TRA,IDB_BITMAP_TRAD); 
	m_buttontra.SizeToContent(); 
}

void CGraphmenuView::OnPaint() 
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
    myFont.CreateFont(70,0,0,0,100,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SWISS, _T("Î¢ÈíÑÅºÚ"));
	CFont *poldFont=dc.SelectObject(&myFont); 
	CRect rect1;
	rect1.SetRect(90,18,1000,300); 
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,0)); 
	dc.DrawText(_T("Í¼"),-1,rect1,DT_SINGLELINE); 
	dc.SelectObject(poldFont);
	// Do not call CView::OnPaint() for painting messages
}

int CGraphmenuView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect_button(0,30,93,105);
	m_buttonback.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button,this,IDB_BUTTON_BACK);
	m_buttonback.ShowWindow(SW_SHOWNORMAL);
	CRect rect_button1(90,111,240,266);
	m_buttontra.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button1,this,IDB_BUTTON_TRA);
	m_buttontra.ShowWindow(SW_SHOWNORMAL);
	return 0;
}

void CGraphmenuView::OnBackButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="menu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

CString CGraphmenuView::GetPath()
{
	CString str_path,str_filePath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.Find("graphmenu\\Debug");
	str_filePath=str_path.Left(nPos);
	return str_filePath;
}

void CGraphmenuView::OnTraButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="graphmenu\\Debug\\GraTra\\Debug\\GraTra.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
}