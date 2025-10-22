// HuffmanView.h : interface of the CHuffmanView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUFFMANVIEW_H__CFAA3B0E_59C2_4D8F_A37A_2BC0A948594B__INCLUDED_)
#define AFX_HUFFMANVIEW_H__CFAA3B0E_59C2_4D8F_A37A_2BC0A948594B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HuffmanDoc.h"
#include "Set.h"
#include "GlobalParas.h"

class CHuffmanView : public CView
{
protected: // create from serialization only
	CHuffmanView();
	DECLARE_DYNCREATE(CHuffmanView)

// Attributes
public:
	CHuffmanDoc* GetDocument();

// Operations
public:
	CBitmap m_bmp;
	CDC m_dc;
	CDC* m_pDC;
	int flag_draw;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuffmanView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void WriteCode(Leaves *par);
	void CodeLeaf(Leaves* par,char ch);
	void DrawCode();
	void DrawLeaf(Leaves* par);
	void DrawTree();
	LRESULT OnReDraw(WPARAM wParam,LPARAM lParam);
	virtual ~CHuffmanView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuffmanView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HuffmanView.cpp
inline CHuffmanDoc* CHuffmanView::GetDocument()
   { return (CHuffmanDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUFFMANVIEW_H__CFAA3B0E_59C2_4D8F_A37A_2BC0A948594B__INCLUDED_)
