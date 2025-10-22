// treemenuView.h : interface of the CTreemenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEMENUVIEW_H__172E3D82_DFF2_46AE_9492_F6E0EC88ED9A__INCLUDED_)
#define AFX_TREEMENUVIEW_H__172E3D82_DFF2_46AE_9492_F6E0EC88ED9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTreemenuView : public CView
{
protected: // create from serialization only
	CTreemenuView();
	DECLARE_DYNCREATE(CTreemenuView)

// Attributes
public:
	CTreemenuDoc* GetDocument();

// Operations
public:
	CBitmap m_bmp;
	CDC m_dc;
	CBitmapButton m_buttonback;
	CBitmapButton m_buttonhuff;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreemenuView)
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
	virtual ~CTreemenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreemenuView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBackButtonDown();
	afx_msg void OnHuffButtonDown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in treemenuView.cpp
inline CTreemenuDoc* CTreemenuView::GetDocument()
   { return (CTreemenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEMENUVIEW_H__172E3D82_DFF2_46AE_9492_F6E0EC88ED9A__INCLUDED_)
