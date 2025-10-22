// sortmenuDoc.h : interface of the CSortmenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORTMENUDOC_H__BAB557C9_8321_4DB9_9057_5FA85C25AEB8__INCLUDED_)
#define AFX_SORTMENUDOC_H__BAB557C9_8321_4DB9_9057_5FA85C25AEB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSortmenuDoc : public CDocument
{
protected: // create from serialization only
	CSortmenuDoc();
	DECLARE_DYNCREATE(CSortmenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortmenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSortmenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSortmenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTMENUDOC_H__BAB557C9_8321_4DB9_9057_5FA85C25AEB8__INCLUDED_)
