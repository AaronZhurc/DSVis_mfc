// HuffmanDoc.cpp : implementation of the CHuffmanDoc class
//

#include "stdafx.h"
#include "Huffman.h"

#include "HuffmanDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuffmanDoc

IMPLEMENT_DYNCREATE(CHuffmanDoc, CDocument)

BEGIN_MESSAGE_MAP(CHuffmanDoc, CDocument)
	//{{AFX_MSG_MAP(CHuffmanDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuffmanDoc construction/destruction

CHuffmanDoc::CHuffmanDoc()
{
	// TODO: add one-time construction code here

}

CHuffmanDoc::~CHuffmanDoc()
{
}

BOOL CHuffmanDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHuffmanDoc serialization

void CHuffmanDoc::Serialize(CArchive& ar)
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
// CHuffmanDoc diagnostics

#ifdef _DEBUG
void CHuffmanDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHuffmanDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuffmanDoc commands
