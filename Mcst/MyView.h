#if !defined(AFX_MYVIEW_H__AD2EC8CA_941C_4D85_A9B4_352F1122DDB5__INCLUDED_)
#define AFX_MYVIEW_H__AD2EC8CA_941C_4D85_A9B4_352F1122DDB5__INCLUDED_

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
	//}}AFX_DATA

// Attributes
public:
	ENode* m_e[100];
	int m_add;
	int m_v[100];
	int m_i,m_j,m_k;
	int m_flagCtrl;
	int m_flagRadio;

// Operations
public:
	void sortEdge(ENode* e[],int num);
	int CheckDup(ENode e,int n);
	void Prim();
	void sortEdge(ENode e[],int num);
	void Kruskal();

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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEW_H__AD2EC8CA_941C_4D85_A9B4_352F1122DDB5__INCLUDED_)
