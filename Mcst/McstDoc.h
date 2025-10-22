// McstDoc.h : interface of the CMcstDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCSTDOC_H__A2D5223F_BF5A_41F6_A83F_DE7450C5A27F__INCLUDED_)
#define AFX_MCSTDOC_H__A2D5223F_BF5A_41F6_A83F_DE7450C5A27F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMcstDoc : public CDocument
{
protected: // create from serialization only
	CMcstDoc();
	DECLARE_DYNCREATE(CMcstDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMcstDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMcstDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMcstDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCSTDOC_H__A2D5223F_BF5A_41F6_A83F_DE7450C5A27F__INCLUDED_)
