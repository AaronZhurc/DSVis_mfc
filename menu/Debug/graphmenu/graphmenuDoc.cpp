// graphmenuDoc.cpp : implementation of the CGraphmenuDoc class
//

#include "stdafx.h"
#include "graphmenu.h"

#include "graphmenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuDoc

IMPLEMENT_DYNCREATE(CGraphmenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphmenuDoc, CDocument)
	//{{AFX_MSG_MAP(CGraphmenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuDoc construction/destruction

CGraphmenuDoc::CGraphmenuDoc()
{
	// TODO: add one-time construction code here

}

CGraphmenuDoc::~CGraphmenuDoc()
{
}

BOOL CGraphmenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGraphmenuDoc serialization

void CGraphmenuDoc::Serialize(CArchive& ar)
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
// CGraphmenuDoc diagnostics

#ifdef _DEBUG
void CGraphmenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphmenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphmenuDoc commands
