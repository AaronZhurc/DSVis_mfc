// GraTraDoc.h : interface of the CGraTraDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRATRADOC_H__AC4997CD_8A13_4FDF_968E_EE16C53B5396__INCLUDED_)
#define AFX_GRATRADOC_H__AC4997CD_8A13_4FDF_968E_EE16C53B5396__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraTraDoc : public CDocument
{
protected: // create from serialization only
	CGraTraDoc();
	DECLARE_DYNCREATE(CGraTraDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraTraDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGraTraDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraTraDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRATRADOC_H__AC4997CD_8A13_4FDF_968E_EE16C53B5396__INCLUDED_)
