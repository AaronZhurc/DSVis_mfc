// sortmenuView.cpp : implementation of the CSortmenuView class
//

#include "stdafx.h"
#include "sortmenu.h"

#include "sortmenuDoc.h"
#include "sortmenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortmenuView

IMPLEMENT_DYNCREATE(CSortmenuView, CView)

BEGIN_MESSAGE_MAP(CSortmenuView, CView)
	//{{AFX_MSG_MAP(CSortmenuView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDB_BUTTON_BACK,OnBackButtonDown) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortmenuView construction/destruction

CSortmenuView::CSortmenuView()
{
	// TODO: add construction code here

}

CSortmenuView::~CSortmenuView()
{
}

BOOL CSortmenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSortmenuView drawing

void CSortmenuView::OnDraw(CDC* pDC)
{
	CSortmenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_BG);
	CDC dcComp;
	dcComp.CreateCompatibleDC(pDC);
	dcComp.SelectObject(&bitmap);
	BITMAP bmInfo;
	bitmap.GetObject(sizeof(bmInfo),&bmInfo);
	pDC->BitBlt(0,0,bmInfo.bmWidth,bmInfo.bmHeight,&dcComp,0,0,SRCCOPY);*/
}

/////////////////////////////////////////////////////////////////////////////
// CSortmenuView printing

BOOL CSortmenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSortmenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSortmenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSortmenuView diagnostics

#ifdef _DEBUG
void CSortmenuView::AssertValid() const
{
	CView::AssertValid();
}

void CSortmenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSortmenuDoc* CSortmenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSortmenuDoc)));
	return (CSortmenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSortmenuView message handlers

void CSortmenuView::OnPaint() 
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
	dc.DrawText(_T("ÅÅÐò"),-1,rect1,DT_SINGLELINE); 
	dc.SelectObject(poldFont);
	// Do not call CView::OnPaint() for painting messages
}

void CSortmenuView::OnInitialUpdate() 
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
	Invalidate(false);
}

void CSortmenuView::OnBackButtonDown()
{
	CString str_path=GetPath();
	int nPos=str_path.ReverseFind(_T('\\'));
	str_path=str_path.Left(nPos+1);
	str_path+="menu.exe";
	ShellExecute(NULL,"open",str_path,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

int CSortmenuView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect_button(0,30,93,105);
	m_buttonback.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect_button,this,IDB_BUTTON_BACK);
	m_buttonback.ShowWindow(SW_SHOWNORMAL);
	return 0;
}

CString CSortmenuView::GetPath()
{
	CString str_path,str_filePath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.Find("sortmenu\\Debug");
	str_filePath=str_path.Left(nPos);
	return str_filePath;
}
