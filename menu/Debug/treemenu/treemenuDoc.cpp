// treemenuDoc.cpp : implementation of the CTreemenuDoc class
//

#include "stdafx.h"
#include "treemenu.h"

#include "treemenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreemenuDoc

IMPLEMENT_DYNCREATE(CTreemenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreemenuDoc, CDocument)
	//{{AFX_MSG_MAP(CTreemenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreemenuDoc construction/destruction

CTreemenuDoc::CTreemenuDoc()
{
	// TODO: add one-time construction code here

}

CTreemenuDoc::~CTreemenuDoc()
{
}

BOOL CTreemenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTreemenuDoc serialization

void CTreemenuDoc::Serialize(CArchive& ar)
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
// CTreemenuDoc diagnostics

#ifdef _DEBUG
void CTreemenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreemenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreemenuDoc commands
