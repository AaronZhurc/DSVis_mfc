#if !defined(AFX_MYVIEW_H__2FE6ADF2_5656_42EE_B94B_D89A8D594D27__INCLUDED_)
#define AFX_MYVIEW_H__2FE6ADF2_5656_42EE_B94B_D89A8D594D27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyView.h : header file
//
#include "GlobalParas.h"

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
	CString	m_last;
	CString	m_ctrl;
	//}}AFX_DATA

// Attributes
public:
	int m_widthCtrl;

// Operations
public:
	void ResetText(WPARAM wParam, LPARAM lParam);
	void GetTreeHeight();
	void ChangeChildHeight(Leaves *par);
	void ChangeHeight(Leaves *par);
	void CreateParent();
	void LeafWidth(Leaves *par);
	void SetWidth();

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
	afx_msg void OnStaticLast();
	afx_msg void OnButtonNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEW_H__2FE6ADF2_5656_42EE_B94B_D89A8D594D27__INCLUDED_)
