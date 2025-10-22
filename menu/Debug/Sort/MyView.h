#if !defined(AFX_MYVIEW_H__C631BCDA_1C23_4CC8_A437_1EA840427BEC__INCLUDED_)
#define AFX_MYVIEW_H__C631BCDA_1C23_4CC8_A437_1EA840427BEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "GlobalParas.h"

class CMyView : public CFormView
{
protected:
	CMyView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyView)

// Form Data
public:
	//{{AFX_DATA(CMyView)
	enum { IDD = IDD_DIALOG_CTRL };
	int		m_radio;
	CString	m_ctrl_gap;
	//}}AFX_DATA

// Attributes
public:
	int m_sortflag;
	int m_i,m_j;
	int m_low,m_high;
	int m_countnum;

// Operations
public:
	void GetQuickSort();
	void ShellInsert(int gap);
	void ShellSort();
	void ResetFlag(int i);
	void Restore();
	void InsertSort();
	void BubbleSort();

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
	afx_msg void OnButtonSort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEW_H__C631BCDA_1C23_4CC8_A437_1EA840427BEC__INCLUDED_)
