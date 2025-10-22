// SortDoc.cpp : implementation of the CSortDoc class
//

#include "stdafx.h"
#include "Sort.h"

#include "SortDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortDoc

IMPLEMENT_DYNCREATE(CSortDoc, CDocument)

BEGIN_MESSAGE_MAP(CSortDoc, CDocument)
	//{{AFX_MSG_MAP(CSortDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortDoc construction/destruction

CSortDoc::CSortDoc()
{
	// TODO: add one-time construction code here

}

CSortDoc::~CSortDoc()
{
}

BOOL CSortDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSortDoc serialization

void CSortDoc::Serialize(CArchive& ar)
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
// CSortDoc diagnostics

#ifdef _DEBUG
void CSortDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSortDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSortDoc commands
