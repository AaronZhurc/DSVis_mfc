// graphmenuView.h : interface of the CGraphmenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHMENUVIEW_H__8C842D34_F8B3_4DA0_AADE_29EB0DC2B44F__INCLUDED_)
#define AFX_GRAPHMENUVIEW_H__8C842D34_F8B3_4DA0_AADE_29EB0DC2B44F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraphmenuView : public CView
{
protected: // create from serialization only
	CGraphmenuView();
	DECLARE_DYNCREATE(CGraphmenuView)

// Attributes
public:
	CGraphmenuDoc* GetDocument();

// Operations
public:
	CBitmap m_bmp;
	CDC m_dc;
	CBitmapButton m_buttonback;
	CBitmapButton m_buttontra;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphmenuView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetPath();
	virtual ~CGraphmenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphmenuView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBackButtonDown();
	afx_msg void OnTraButtonDown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in graphmenuView.cpp
inline CGraphmenuDoc* CGraphmenuView::GetDocument()
   { return (CGraphmenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHMENUVIEW_H__8C842D34_F8B3_4DA0_AADE_29EB0DC2B44F__INCLUDED_)
