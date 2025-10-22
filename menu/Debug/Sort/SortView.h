// SortView.h : interface of the CSortView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORTVIEW_H__9768A72A_CCB9_4CE3_997A_1A047D6AC5BF__INCLUDED_)
#define AFX_SORTVIEW_H__9768A72A_CCB9_4CE3_997A_1A047D6AC5BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SortDoc.h"

class CSortView : public CView
{
protected: // create from serialization only
	CSortView();
	DECLARE_DYNCREATE(CSortView)

// Attributes
public:
	CSortDoc* GetDocument();

// Operations
public:
	CDC* m_pDC;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortView)
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
	void DrawArray();
	LRESULT OnReDraw(WPARAM wParam, LPARAM lParam);
	virtual ~CSortView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSortView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SortView.cpp
inline CSortDoc* CSortView::GetDocument()
   { return (CSortDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTVIEW_H__9768A72A_CCB9_4CE3_997A_1A047D6AC5BF__INCLUDED_)
