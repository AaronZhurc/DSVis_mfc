#if !defined(AFX_MYVIEW_H__72B66EE7_2EAA_4C4F_B5DD_6388FCF03558__INCLUDED_)
#define AFX_MYVIEW_H__72B66EE7_2EAA_4C4F_B5DD_6388FCF03558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyView.h : header file
//
#include "GlobalParas.h"
#include "GraTraView.h"
#include <queue>

/////////////////////////////////////////////////////////////////////////////
// CMyView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMyView : public CFormView
{
protected:
	CMyView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyView)

// Form Data
public:
	//{{AFX_DATA(CMyView)
	enum { IDD = IDD_DIALOG_CTRL };
	CString	m_result;
	int		m_radio;
	//}}AFX_DATA

// Attributes
public:
	int m_flagText;

// Operations
public:
	void ResetText(WPARAM wParam,LPARAM lParam);
	int m_tra;
	void BFS(int v);
	void BFStraverse();
	void DFS(int v);
	void DFStraverse();
	void Traversal();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMyView)
	afx_msg void OnButtonNext();
	afx_msg void OnRadioBfs();
	afx_msg void OnRadioDfs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEW_H__72B66EE7_2EAA_4C4F_B5DD_6388FCF03558__INCLUDED_)
