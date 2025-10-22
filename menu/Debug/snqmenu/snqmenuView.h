// snqmenuView.h : interface of the CSnqmenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNQMENUVIEW_H__755DF5BC_947F_4FB2_8834_C43B76612030__INCLUDED_)
#define AFX_SNQMENUVIEW_H__755DF5BC_947F_4FB2_8834_C43B76612030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnqmenuView : public CView
{
protected: // create from serialization only
	CSnqmenuView();
	DECLARE_DYNCREATE(CSnqmenuView)

// Attributes
public:
	CSnqmenuDoc* GetDocument();

// Operations
public:
	CBitmap m_bmp;
	CDC m_dc;
	CBitmapButton m_buttonback;
	CBitmapButton m_buttonjo;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnqmenuView)
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
	virtual ~CSnqmenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnqmenuView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBackButtonDown();
	afx_msg void OnJoButtonDown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in snqmenuView.cpp
inline CSnqmenuDoc* CSnqmenuView::GetDocument()
   { return (CSnqmenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNQMENUVIEW_H__755DF5BC_947F_4FB2_8834_C43B76612030__INCLUDED_)
