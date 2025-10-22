// snqmenuDoc.h : interface of the CSnqmenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNQMENUDOC_H__75A737DE_CA68_4AE5_ADE3_7C1F1458869F__INCLUDED_)
#define AFX_SNQMENUDOC_H__75A737DE_CA68_4AE5_ADE3_7C1F1458869F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnqmenuDoc : public CDocument
{
protected: // create from serialization only
	CSnqmenuDoc();
	DECLARE_DYNCREATE(CSnqmenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnqmenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnqmenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnqmenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNQMENUDOC_H__75A737DE_CA68_4AE5_ADE3_7C1F1458869F__INCLUDED_)
