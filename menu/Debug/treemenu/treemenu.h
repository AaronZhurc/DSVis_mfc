// treemenu.h : main header file for the TREEMENU application
//

#if !defined(AFX_TREEMENU_H__89B9377E_3C1E_4575_AF77_BFEEFDAAE517__INCLUDED_)
#define AFX_TREEMENU_H__89B9377E_3C1E_4575_AF77_BFEEFDAAE517__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreemenuApp:
// See treemenu.cpp for the implementation of this class
//

class CTreemenuApp : public CWinApp
{
public:
	CTreemenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreemenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTreemenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEMENU_H__89B9377E_3C1E_4575_AF77_BFEEFDAAE517__INCLUDED_)
