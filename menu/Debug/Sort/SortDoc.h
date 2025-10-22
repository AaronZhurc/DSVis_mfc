// SortDoc.h : interface of the CSortDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORTDOC_H__E526FB62_819D_4490_AE24_00564134494B__INCLUDED_)
#define AFX_SORTDOC_H__E526FB62_819D_4490_AE24_00564134494B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSortDoc : public CDocument
{
protected: // create from serialization only
	CSortDoc();
	DECLARE_DYNCREATE(CSortDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSortDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSortDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTDOC_H__E526FB62_819D_4490_AE24_00564134494B__INCLUDED_)
