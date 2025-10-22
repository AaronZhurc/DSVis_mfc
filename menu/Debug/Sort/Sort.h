// Sort.h : main header file for the SORT application
//

#if !defined(AFX_SORT_H__DBE3B007_FE2E_4640_9A88_66BE08327E95__INCLUDED_)
#define AFX_SORT_H__DBE3B007_FE2E_4640_9A88_66BE08327E95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSortApp:
// See Sort.cpp for the implementation of this class
//

class CSortApp : public CWinApp
{
public:
	CSortApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSortApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORT_H__DBE3B007_FE2E_4640_9A88_66BE08327E95__INCLUDED_)
