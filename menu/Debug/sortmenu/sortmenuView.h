// sortmenuView.h : interface of the CSortmenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORTMENUVIEW_H__9787F9CF_C790_4358_A8CA_94D564BAFCA5__INCLUDED_)
#define AFX_SORTMENUVIEW_H__9787F9CF_C790_4358_A8CA_94D564BAFCA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSortmenuView : public CView
{
protected: // create from serialization only
	CSortmenuView();
	DECLARE_DYNCREATE(CSortmenuView)

// Attributes
public:
	CSortmenuDoc* GetDocument();

// Operations
public:
	CBitmap m_bmp;
	CDC m_dc;
	CBitmapButton m_buttonback;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortmenuView)
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
	virtual ~CSortmenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSortmenuView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBackButtonDown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sortmenuView.cpp
inline CSortmenuDoc* CSortmenuView::GetDocument()
   { return (CSortmenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTMENUVIEW_H__9787F9CF_C790_4358_A8CA_94D564BAFCA5__INCLUDED_)
