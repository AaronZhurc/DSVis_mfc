// menuView.h : interface of the CMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUVIEW_H__A689F271_1210_4B85_A2AA_317783919482__INCLUDED_)
#define AFX_MENUVIEW_H__A689F271_1210_4B85_A2AA_317783919482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuView : public CView
{
protected: // create from serialization only
	CMenuView();
	DECLARE_DYNCREATE(CMenuView)

// Attributes
public:
	CMenuDoc* GetDocument();

// Operations
public:
	CBitmap m_bmp;
	CDC m_dc;
	CBitmapButton m_buttonsort,m_buttonsnq,m_buttontree,m_buttongraph;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuView)
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
	virtual ~CMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuView)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSortButtonDown();
	afx_msg void OnSnqButtonDown();
	afx_msg void OnTreeButtonDown();
	afx_msg void OnGraphButtonDown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in menuView.cpp
inline CMenuDoc* CMenuView::GetDocument()
   { return (CMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUVIEW_H__A689F271_1210_4B85_A2AA_317783919482__INCLUDED_)
