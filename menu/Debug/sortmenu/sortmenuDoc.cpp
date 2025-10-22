// sortmenuDoc.cpp : implementation of the CSortmenuDoc class
//

#include "stdafx.h"
#include "sortmenu.h"

#include "sortmenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortmenuDoc

IMPLEMENT_DYNCREATE(CSortmenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CSortmenuDoc, CDocument)
	//{{AFX_MSG_MAP(CSortmenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortmenuDoc construction/destruction

CSortmenuDoc::CSortmenuDoc()
{
	// TODO: add one-time construction code here

}

CSortmenuDoc::~CSortmenuDoc()
{
}

BOOL CSortmenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSortmenuDoc serialization

void CSortmenuDoc::Serialize(CArchive& ar)
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
// CSortmenuDoc diagnostics

#ifdef _DEBUG
void CSortmenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSortmenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSortmenuDoc commands
