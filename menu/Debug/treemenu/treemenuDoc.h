// treemenuDoc.h : interface of the CTreemenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEMENUDOC_H__557336C6_8DAD_4942_BE4C_3F6663E8046E__INCLUDED_)
#define AFX_TREEMENUDOC_H__557336C6_8DAD_4942_BE4C_3F6663E8046E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTreemenuDoc : public CDocument
{
protected: // create from serialization only
	CTreemenuDoc();
	DECLARE_DYNCREATE(CTreemenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreemenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreemenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreemenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEMENUDOC_H__557336C6_8DAD_4942_BE4C_3F6663E8046E__INCLUDED_)
