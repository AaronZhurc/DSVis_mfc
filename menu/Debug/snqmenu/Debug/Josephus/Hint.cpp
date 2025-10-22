// Hint.cpp : implementation file
//

#include "stdafx.h"
#include "Josephus.h"
#include "Hint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHint dialog


CHint::CHint(CWnd* pParent /*=NULL*/)
	: CDialog(CHint::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHint)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHint)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHint, CDialog)
	//{{AFX_MSG_MAP(CHint)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHint message handlers

void CHint::OnButtonOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
