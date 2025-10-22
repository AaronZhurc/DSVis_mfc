#if !defined(AFX_SET_H__08787604_286C_411D_AE93_5A2B4262AE4A__INCLUDED_)
#define AFX_SET_H__08787604_286C_411D_AE93_5A2B4262AE4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Set.h : header file
//

#include "GlobalParas.h"

/////////////////////////////////////////////////////////////////////////////
// CSet dialog

class CSet : public CDialog
{
// Construction
public:
	void CleanRecord();
	void GetRecord();
	int QuickSort1(int low,int high);
	void QuickSort(int low,int high);
	void Restore();
	void Sort();
	CSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSet)
	enum { IDD = IDD_DIALOG_SET };
	CString	m_set_num;
	CString	m_set_gap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSet)
	afx_msg void OnButtonOk();
	afx_msg void OnButtonGen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_H__08787604_286C_411D_AE93_5A2B4262AE4A__INCLUDED_)
