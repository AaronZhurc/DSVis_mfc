// snqmenuView.cpp : implementation of the CSnqmenuView class
//

#include "stdafx.h"
#include "snqmenu.h"

#include "snqmenuDoc.h"
#include "snqmenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuView

IMPLEMENT_DYNCREATE(CSnqmenuView, CView)

BEGIN_MESSAGE_MAP(CSnqmenuView, CView)
	//{{AFX_MSG_MAP(CSnqmenuView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDB_BUTTON_BACK,OnBackButtonDown) 
	ON_BN_CLICKED(IDB_BUTTON_JO,OnJoButtonDown) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuView construction/destruction

CSnqmenuView::CSnqmenuView()
{
	// TODO: add construction code here

}

CSnqmenuView::~CSnqmenuView()
{
}

BOOL CSnqmenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuView drawing

void CSnqmenuView::OnDraw(CDC* pDC)
{
	CSnqmenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuView printing

BOOL CSnqmenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnqmenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnqmenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuView diagnostics

#ifdef _DEBUG
void CSnqmenuView::AssertValid() const
{
	CView::AssertValid();
}

void CSnqmenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnqmenuDoc* CSnqmenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnqmenuDoc)));
	return (CSnqmenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuView message handlers

void CSnqmenuView::OnPaint() 
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
	dc.DrawText(_T("Á´±í Õ» ¶ÓÁÐ"),-1,rect1,DT_SINGLELINE); 
	dc.SelectObject(poldFont);
	// Do not call CView::OnPaint() for painting messages
}

void CSnqmenuView::OnInitialUpdate() 
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
	m_buttonjo.LoadBitmaps(IDB_BITMAP_JO,IDB_BITMAP_JOD); 
	m_buttonjo.SizeToContent(); 
}

void CSnqmenuView::OnBackButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="menu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

CString CSnqmenuView::GetPath()
{
	CString str_path,str_filePath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.Find("snqmenu\\Debug");
	str_filePath=str_path.Left(nPos);
	return str_filePath;
}

int CSnqmenuView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect_button(0,30,93,105);
	m_buttonback.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button,this,IDB_BUTTON_BACK);
	m_buttonback.ShowWindow(SW_SHOWNORMAL);
	CRect rect_button1(90,111,240,266);
	m_buttonjo.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button1,this,IDB_BUTTON_JO);
	m_buttonjo.ShowWindow(SW_SHOWNORMAL);
	return 0;
}

void CSnqmenuView::OnJoButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="snqmenu\\Debug\\Josephus\\Debug\\Josephus.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
}