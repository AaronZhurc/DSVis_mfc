// JosephusDoc.cpp : implementation of the CJosephusDoc class
//

#include "stdafx.h"
#include "Josephus.h"

#include "JosephusDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJosephusDoc

IMPLEMENT_DYNCREATE(CJosephusDoc, CDocument)

BEGIN_MESSAGE_MAP(CJosephusDoc, CDocument)
	//{{AFX_MSG_MAP(CJosephusDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJosephusDoc construction/destruction

CJosephusDoc::CJosephusDoc()
{
	// TODO: add one-time construction code here

}

CJosephusDoc::~CJosephusDoc()
{
}

BOOL CJosephusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJosephusDoc serialization

void CJosephusDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CJosephusDoc diagnostics

#ifdef _DEBUG
void CJosephusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJosephusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJosephusDoc commands
