// GraTraDoc.cpp : implementation of the CGraTraDoc class
//

#include "stdafx.h"
#include "GraTra.h"

#include "GraTraDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraTraDoc

IMPLEMENT_DYNCREATE(CGraTraDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraTraDoc, CDocument)
	//{{AFX_MSG_MAP(CGraTraDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraTraDoc construction/destruction

CGraTraDoc::CGraTraDoc()
{
	// TODO: add one-time construction code here

}

CGraTraDoc::~CGraTraDoc()
{
}

BOOL CGraTraDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGraTraDoc serialization

void CGraTraDoc::Serialize(CArchive& ar)
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
// CGraTraDoc diagnostics

#ifdef _DEBUG
void CGraTraDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraTraDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraTraDoc commands
