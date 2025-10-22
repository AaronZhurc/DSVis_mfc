// treemenuView.cpp : implementation of the CTreemenuView class
//

#include "stdafx.h"
#include "treemenu.h"

#include "treemenuDoc.h"
#include "treemenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreemenuView

IMPLEMENT_DYNCREATE(CTreemenuView, CView)

BEGIN_MESSAGE_MAP(CTreemenuView, CView)
	//{{AFX_MSG_MAP(CTreemenuView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDB_BUTTON_BACK,OnBackButtonDown) 
	ON_BN_CLICKED(IDB_BUTTON_HUFF,OnHuffButtonDown) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreemenuView construction/destruction

CTreemenuView::CTreemenuView()
{
	// TODO: add construction code here

}

CTreemenuView::~CTreemenuView()
{
}

BOOL CTreemenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTreemenuView drawing

void CTreemenuView::OnDraw(CDC* pDC)
{
	CTreemenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTreemenuView printing

BOOL CTreemenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTreemenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTreemenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTreemenuView diagnostics

#ifdef _DEBUG
void CTreemenuView::AssertValid() const
{
	CView::AssertValid();
}

void CTreemenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTreemenuDoc* CTreemenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreemenuDoc)));
	return (CTreemenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreemenuView message handlers

void CTreemenuView::OnPaint() 
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
	dc.DrawText(_T("Ê÷"),-1,rect1,DT_SINGLELINE); 
	dc.SelectObject(poldFont);
	// Do not call CView::OnPaint() for painting messages
}

int CTreemenuView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect_button(0,30,93,105);
	m_buttonback.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button,this,IDB_BUTTON_BACK);
	m_buttonback.ShowWindow(SW_SHOWNORMAL);
	CRect rect_button1(90,111,240,266);
	m_buttonhuff.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button1,this,IDB_BUTTON_HUFF);
	m_buttonhuff.ShowWindow(SW_SHOWNORMAL);
	return 0;
}

void CTreemenuView::OnInitialUpdate() 
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
	m_buttonhuff.LoadBitmaps(IDB_BITMAP_HUFF,IDB_BITMAP_HUFFD); 
	m_buttonhuff.SizeToContent(); 
}

void CTreemenuView::OnBackButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="menu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

CString CTreemenuView::GetPath()
{
	CString str_path,str_filePath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.Find("treemenu\\Debug");
	str_filePath=str_path.Left(nPos);
	return str_filePath;
}

void CTreemenuView::OnHuffButtonDown(){
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="treemenu\\Debug\\Huffman\\Debug\\Huffman.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
}