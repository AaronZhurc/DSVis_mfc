// snqmenu.h : main header file for the SNQMENU application
//

#if !defined(AFX_SNQMENU_H__21752117_BE73_440B_A458_4C4896C17D67__INCLUDED_)
#define AFX_SNQMENU_H__21752117_BE73_440B_A458_4C4896C17D67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuApp:
// See snqmenu.cpp for the implementation of this class
//

class CSnqmenuApp : public CWinApp
{
public:
	CSnqmenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnqmenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSnqmenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNQMENU_H__21752117_BE73_440B_A458_4C4896C17D67__INCLUDED_)
