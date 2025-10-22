// graphmenu.h : main header file for the GRAPHMENU application
//

#if !defined(AFX_GRAPHMENU_H__1FA9D748_8563_44E5_98E3_EE811AD3EACB__INCLUDED_)
#define AFX_GRAPHMENU_H__1FA9D748_8563_44E5_98E3_EE811AD3EACB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuApp:
// See graphmenu.cpp for the implementation of this class
//

class CGraphmenuApp : public CWinApp
{
public:
	CGraphmenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphmenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGraphmenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHMENU_H__1FA9D748_8563_44E5_98E3_EE811AD3EACB__INCLUDED_)
