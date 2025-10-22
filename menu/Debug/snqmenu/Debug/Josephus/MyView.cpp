// MyView.cpp : implementation file
//

#include "stdafx.h"
#include "Josephus.h"
#include "MyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CFormView)

CMyView::CMyView()
	: CFormView(CMyView::IDD)
{
	//{{AFX_DATA_INIT(CMyView)
	m_ctrl_putout = _T("");
	//}}AFX_DATA_INIT
}

CMyView::~CMyView()
{
}

void CMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyView)
	DDX_Text(pDX, IDC_STATIC_OUT, m_ctrl_putout);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyView, CFormView)
	//{{AFX_MSG_MAP(CMyView)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RETEXT,ResetText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	
	LinkList pre;
	int count;
	if(!m_ListCtrl||m_num==0){
		AfxMessageBox("表中无元素");
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("结束");
	}else{
		try{
			if(m_flagfirst==0){
				m_pCtrl=m_ListCtrl;
				for(count=0;count<=m_first;count++)
					m_pCtrl=m_pCtrl->next;
				m_flagfirst=1;
			}
			if(m_pCtrl!=m_pCtrl->next){
				pre=m_pCtrl->next;
				while(pre->next!=m_pCtrl)
					pre=pre->next;
				for(count=1;count<m_large;count++){
					pre=m_pCtrl;
					m_pCtrl=m_pCtrl->next;
				}
				m_putout[m_count]=m_pCtrl->data;
				m_count++;
				pre->next=m_pCtrl->next;
				free(m_pCtrl);
				m_pCtrl=pre->next;
			}else{
				m_putout[m_count]=m_pCtrl->data;
				free(m_pCtrl);
				m_flagButton=1;
			}
		}catch(...){
		}
		if(m_ListCtrl){
			m_ctrl_putout.Empty();
			CString str;
			for(int i=0;m_putout[i]!=-1;i++){
				str.Format("%d ",m_putout[i]);
				m_ctrl_putout+=str;
			}
			UpdateData(false);
		}
		::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
		if(m_flagButton==1)
			GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("结束");
		else
			GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
	}
}

void CMyView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	g_TextViewWnd=this->GetSafeHwnd();	
}

void CMyView::ResetText(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1){
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
	}
}
