// Josephus.h : main header file for the JOSEPHUS application
//

#if !defined(AFX_JOSEPHUS_H__3D4333E5_0D0B_4ED8_BAF5_512D692B9BB0__INCLUDED_)
#define AFX_JOSEPHUS_H__3D4333E5_0D0B_4ED8_BAF5_512D692B9BB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJosephusApp:
// See Josephus.cpp for the implementation of this class
//

class CJosephusApp : public CWinApp
{
public:
	CJosephusApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJosephusApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJosephusApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOSEPHUS_H__3D4333E5_0D0B_4ED8_BAF5_512D692B9BB0__INCLUDED_)
