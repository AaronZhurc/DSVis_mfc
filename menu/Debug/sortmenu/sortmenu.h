// sortmenu.h : main header file for the SORTMENU application
//

#if !defined(AFX_SORTMENU_H__273BE2EF_06BF_495C_B8BB_9397EA28373E__INCLUDED_)
#define AFX_SORTMENU_H__273BE2EF_06BF_495C_B8BB_9397EA28373E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSortmenuApp:
// See sortmenu.cpp for the implementation of this class
//

class CSortmenuApp : public CWinApp
{
public:
	CSortmenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortmenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSortmenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTMENU_H__273BE2EF_06BF_495C_B8BB_9397EA28373E__INCLUDED_)
