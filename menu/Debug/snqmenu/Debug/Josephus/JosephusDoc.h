// JosephusDoc.h : interface of the CJosephusDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JOSEPHUSDOC_H__404BCD07_4826_46AE_ABBA_6672EA393B87__INCLUDED_)
#define AFX_JOSEPHUSDOC_H__404BCD07_4826_46AE_ABBA_6672EA393B87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJosephusDoc : public CDocument
{
protected: // create from serialization only
	CJosephusDoc();
	DECLARE_DYNCREATE(CJosephusDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJosephusDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJosephusDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJosephusDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOSEPHUSDOC_H__404BCD07_4826_46AE_ABBA_6672EA393B87__INCLUDED_)
