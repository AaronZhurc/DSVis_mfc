// Set.cpp : implementation file
//

#include "stdafx.h"
#include "Mcst.h"
#include "Set.h"
#include "GlobalParas.h"

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
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnButtonOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int i,m_flagMark,m_flagExit=0;
	CString str;
	for(i=0;i<m_set_w.GetLength();i++){
		if(m_set_w.GetAt(i)==','){
			m_flagMark=0;
		}
		if(m_set_w.GetAt(i)==' '){
			m_flagMark=1;
		}
	}
	for(i=0;i<m_graph.edgeNum;i++){
		if(m_flagMark==0){
			AfxExtractSubString(str,m_set_w,i,',');
		}else if(m_flagMark==1){
			AfxExtractSubString(str,m_set_w,i,' ');
		}
		if(str.IsEmpty()){
			m_flagExit=1;
		}else{
			m_graph.edges[i].weight=atoi(str);
		}
	}
	if(m_flagExit==0){
		m_flagBuild=0;
		m_flagCtrl=3;
		::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
		CDialog::OnOK();
	}else if(i!=m_graph.edgeNum){
		AfxMessageBox("没有为所有边赋值");
	}else{
		AfxMessageBox("输入不能为空");
	}
}
