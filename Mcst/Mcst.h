// Mcst.h : main header file for the MCST application
//

#if !defined(AFX_MCST_H__D8915D0B_5D20_4E0B_A949_D793AFB01FC0__INCLUDED_)
#define AFX_MCST_H__D8915D0B_5D20_4E0B_A949_D793AFB01FC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMcstApp:
// See Mcst.cpp for the implementation of this class
//

class CMcstApp : public CWinApp
{
public:
	CMcstApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMcstApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMcstApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCST_H__D8915D0B_5D20_4E0B_A949_D793AFB01FC0__INCLUDED_)
