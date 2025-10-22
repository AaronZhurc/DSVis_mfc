// Set.cpp : implementation file
//

#include "stdafx.h"
#include "Josephus.h"
#include "Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSet dialog


CSet::CSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSet)
	m_set_num = 0;
	m_set_large = 0;
	m_set_first = 0;
	//}}AFX_DATA_INIT
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
	DDX_Text(pDX, IDC_EDIT_NUM, m_set_num);
	DDX_Text(pDX, IDC_EDIT_LARGE, m_set_large);
	DDX_Text(pDX, IDC_EDIT_FIRST, m_set_first);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSet, CDialog)
	//{{AFX_MSG_MAP(CSet)
	ON_BN_CLICKED(IDC_BUTTON_SET_OK, OnButtonSetOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnButtonSetOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int i;
	m_ListCtrl=(LinkList)malloc(sizeof(LNode));
	if(m_ListCtrl){
		m_ListCtrl->data=0;
		m_ListCtrl->next=m_ListCtrl;
	}
	for(i=m_set_num-1;i>0;i--){
		LinkList p;
		p=(LinkList)malloc(sizeof(LNode));
		if(p){
			p->data=i;
			p->next=m_ListCtrl->next;
			m_ListCtrl->next=p;
		}
	}
	for(i=0;i<100;i++){
		m_putout[i]=-1;
	}
	m_num=m_set_num;
	m_first=m_set_first;
	m_large=m_set_large;
	m_flagfirst=0;
	m_count=0;
	m_flagButton=0;
	CDialog::OnOK();
	::SendMessage(g_TextViewWnd,WM_RETEXT,(WPARAM)1,NULL);
}


BOOL CSet::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN){
		switch(pMsg->wParam){
		case 13:
			OnButtonSetOk();
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
