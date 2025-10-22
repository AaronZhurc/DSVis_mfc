// DataStructure.h : main header file for the DATASTRUCTURE application
//

#if !defined(AFX_DATASTRUCTURE_H__8A65E8B7_E20A_472F_9869_E8CCA570F757__INCLUDED_)
#define AFX_DATASTRUCTURE_H__8A65E8B7_E20A_472F_9869_E8CCA570F757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataStructureApp:
// See DataStructure.cpp for the implementation of this class
//

class CDataStructureApp : public CWinApp
{
public:
	CDataStructureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataStructureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDataStructureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASTRUCTURE_H__8A65E8B7_E20A_472F_9869_E8CCA570F757__INCLUDED_)
