#if !defined(AFX_HINT_H__81DDF6BB_0A0C_476C_9CA7_6589322F089C__INCLUDED_)
#define AFX_HINT_H__81DDF6BB_0A0C_476C_9CA7_6589322F089C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Hint.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHint dialog

class CHint : public CDialog
{
// Construction
public:
	CHint(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHint)
	enum { IDD = IDD_DIALOG_HINT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHint)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHint)
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HINT_H__81DDF6BB_0A0C_476C_9CA7_6589322F089C__INCLUDED_)
