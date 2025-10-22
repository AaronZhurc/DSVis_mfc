// snqmenuDoc.cpp : implementation of the CSnqmenuDoc class
//

#include "stdafx.h"
#include "snqmenu.h"

#include "snqmenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuDoc

IMPLEMENT_DYNCREATE(CSnqmenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnqmenuDoc, CDocument)
	//{{AFX_MSG_MAP(CSnqmenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuDoc construction/destruction

CSnqmenuDoc::CSnqmenuDoc()
{
	// TODO: add one-time construction code here

}

CSnqmenuDoc::~CSnqmenuDoc()
{
}

BOOL CSnqmenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSnqmenuDoc serialization

void CSnqmenuDoc::Serialize(CArchive& ar)
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
// CSnqmenuDoc diagnostics

#ifdef _DEBUG
void CSnqmenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnqmenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnqmenuDoc commands
