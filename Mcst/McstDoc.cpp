// McstDoc.cpp : implementation of the CMcstDoc class
//

#include "stdafx.h"
#include "Mcst.h"

#include "McstDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMcstDoc

IMPLEMENT_DYNCREATE(CMcstDoc, CDocument)

BEGIN_MESSAGE_MAP(CMcstDoc, CDocument)
	//{{AFX_MSG_MAP(CMcstDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMcstDoc construction/destruction

CMcstDoc::CMcstDoc()
{
	// TODO: add one-time construction code here

}

CMcstDoc::~CMcstDoc()
{
}

BOOL CMcstDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMcstDoc serialization

void CMcstDoc::Serialize(CArchive& ar)
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
// CMcstDoc diagnostics

#ifdef _DEBUG
void CMcstDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMcstDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMcstDoc commands
