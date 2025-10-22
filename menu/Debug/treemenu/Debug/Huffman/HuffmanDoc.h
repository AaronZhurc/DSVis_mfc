// HuffmanDoc.h : interface of the CHuffmanDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUFFMANDOC_H__E69E7C8E_41A4_4543_8E03_2224F8821FCC__INCLUDED_)
#define AFX_HUFFMANDOC_H__E69E7C8E_41A4_4543_8E03_2224F8821FCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHuffmanDoc : public CDocument
{
protected: // create from serialization only
	CHuffmanDoc();
	DECLARE_DYNCREATE(CHuffmanDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuffmanDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHuffmanDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuffmanDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUFFMANDOC_H__E69E7C8E_41A4_4543_8E03_2224F8821FCC__INCLUDED_)
