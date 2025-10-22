// Set.cpp : implementation file
//

#include "stdafx.h"
#include "Huffman.h"
#include "Set.h"
#include "GlobalParas.h"

#include <string.h>

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
	m_set_w = _T("");
	//}}AFX_DATA_INIT
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
	DDX_Text(pDX, IDC_EDIT_SET_WEIGHT, m_set_w);
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
	int m_flagExit=0,i,m_flagMark;
	UpdateData(true);
	m_LeafNum=0;
	CString str;
	Leaves* m_leaf;
	m_LeafCtrl=(Leaves *)malloc(sizeof(Leaves));
	m_LeafCtrl->prior=m_LeafCtrl;
	m_LeafCtrl->next=m_LeafCtrl;
	for(i=0;i<m_set_w.GetLength();i++){
		if(m_set_w.GetAt(i)==','){
			m_LeafNum++;
			m_flagMark=0;
		}
		if(m_set_w.GetAt(i)==' '){
			m_LeafNum++;
			m_flagMark=1;
		}
	}
	m_LeafNum++;
	m_LeafNum1=m_LeafNum;
	for(i=0;i<m_LeafNum1;i++){
		if(m_flagMark==0){
			AfxExtractSubString(str,m_set_w,i,',');
		}else if(m_flagMark==1){
			AfxExtractSubString(str,m_set_w,i,' ');
		}
		if(str.IsEmpty()){
			m_flagExit=1;
		}else{
			m_LeafArr[i]=atoi(str);
			m_leaf=(Leaves *)malloc(sizeof(Leaves));
			m_leaf->weight=m_LeafArr[i];
			m_leaf->height=0;
			m_leaf->name=65+i;
			m_leaf->next=m_LeafCtrl->next;
			m_LeafCtrl->next->prior=m_leaf;
			m_LeafCtrl->next=m_leaf;
			m_leaf->prior=m_LeafCtrl;
			m_leaf->lchild=NULL;
			m_leaf->rchild=NULL;
			m_leaf->parent=NULL;
		}
	}
	m_TreeHigh=0;
	m_flagWidth=0;
	m_flagCode=0;
	if(m_flagExit==0){
		CDialog::OnOK();
	}else{
		AfxMessageBox("输入不能为空");
	}
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
