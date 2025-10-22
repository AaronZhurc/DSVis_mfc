// MyView.cpp : implementation file
//

#include "stdafx.h"
#include "Huffman.h"
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
	m_last = _T("");
	m_ctrl = _T("");
	//}}AFX_DATA_INIT
}

CMyView::~CMyView()
{
}

void CMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyView)
	DDX_Text(pDX, IDC_STATIC_LAST, m_last);
	DDX_Text(pDX, IDC_STATIC_CTRL, m_ctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyView, CFormView)
	//{{AFX_MSG_MAP(CMyView)
	ON_BN_CLICKED(IDC_STATIC_LAST, OnStaticLast)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_MESSAGE(WM_RETEXT, ResetText)
	//}}AFX_MSG_MAP
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

//DEL void CMyView::OnMSet() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

void CMyView::OnStaticLast() 
{
	// TODO: Add your control notification handler code here

}

void CMyView::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	if(m_LeafNum==0){
		AfxMessageBox("树中无元素");
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("结束");
	}else{
		try{
			Leaves* p=m_LeafCtrl->next,* q;
			int i,j;
			for (i = 0; i<m_LeafNum1 ; i++) {
				for (j = 0; j < m_LeafNum1-i ; j++) {
					q = p->next;
					if (p->weight < q->weight) {
						p->prior->next = q;
						q->next->prior = p;
						p->next = q->next;
						q->prior = p->prior;
						p->prior = q;
						q->next = p;
					}else if(p->weight==q->weight){
						if(p->width>q->width){
							p->prior->next = q;
							q->next->prior = p;
							p->next = q->next;
							q->prior = p->prior;
							p->prior = q;
							q->next = p;
						}else
							p=p->next;
					}else
						p=p->next;
				}
				p = m_LeafCtrl->next;
			}
			
			m_last.Empty();
			m_ctrl.Empty();
			CString str,strc;
			for(i=0;i<m_LeafNum;i++){
				str.Format("%d ",m_LeafArr[i]);
				m_last+=str;
			}
			if(m_LeafCtrl->next->next!=m_LeafCtrl)
				CreateParent();
			m_widthCtrl=0;
			SetWidth();
			m_flagWidth=1;
			m_LeafNum1--;
			p=m_LeafCtrl->next;
			while (p!=m_LeafCtrl) {
				strc.Format("%d ", p->weight);
				m_ctrl+=strc;
				p=p->next;
			}
			UpdateData(false);
			::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
			if(m_LeafCtrl->next->next==m_LeafCtrl)
				GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("结束");
			else
				GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
		}catch(...){
		}
	}
}

void CMyView::SetWidth()
{
	Leaves* p=m_LeafCtrl->next;
	while(p!=m_LeafCtrl){
		if(p->lchild&&p->rchild)
			LeafWidth(p);
		else{
			p->width=m_widthCtrl;
			m_widthCtrl++;
		}
		p=p->next;
	}
}

void CMyView::LeafWidth(Leaves *par)
{
	if(par){
		if(par->rchild&&par->lchild){
			LeafWidth(par->lchild);
			LeafWidth(par->rchild);
			par->width=0.5*(par->lchild->width+par->rchild->width);
		}else{
			par->width=m_widthCtrl;
			m_widthCtrl++;
		}
	}
}

void CMyView::CreateParent()
{
    //建立树的关系
	Leaves *p,*q;
	Leaves *par;
	par=(Leaves*)malloc(sizeof(Leaves));
	par->parent=NULL;
	p=m_LeafCtrl->prior;
	q=p->prior;
	if(p->width<q->width){
		par->lchild=p;
		par->rchild=q;
	}else{
		par->lchild=q;
		par->rchild=p;
	}
	p->parent=par;
	q->parent=par;
	
	//修改链表
	if(p!=q){
		par->prior=q->prior;
		par->next=p->next;
		q->prior->next=par;
		p->next->prior=par;
		par->weight=p->weight+q->weight;
	}
	
	//修改子树高度权值以便于作图
	ChangeHeight(par);
	GetTreeHeight();
	
}

void CMyView::ChangeHeight(Leaves *par)
{
	if(par){
		if(par->lchild->height==par->rchild->height)
			par->height=par->lchild->height+1;
		else if(par->lchild->height<par->rchild->height){
			par->height=par->rchild->height+1;
			ChangeChildHeight(par->lchild);
		}else{
			par->height=par->lchild->height+1;
			ChangeChildHeight(par->rchild);
		}	
	}
}

void CMyView::ChangeChildHeight(Leaves *par)
{
	if(par){
		par->height=par->parent->height-1;
		ChangeChildHeight(par->lchild);
		ChangeChildHeight(par->rchild);
	}
}

void CMyView::GetTreeHeight()
{
	Leaves *p=m_LeafCtrl->next;
	while(p!=m_LeafCtrl){
		if(p->height>m_TreeHigh)
			m_TreeHigh=p->height;
		p=p->next;
	}
}

//DEL BOOL CMyView::PreTranslateMessage(MSG* pMsg) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	if(pMsg->message==WM_RETEXT){
//DEL 		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
//DEL 	}
//DEL 	return CFormView::PreTranslateMessage(pMsg);
//DEL }

void CMyView::ResetText(WPARAM wParam, LPARAM lParam)
{
	if(wParam==1)
		GetDlgItem(IDC_BUTTON_NEXT)->SetWindowText("下一步");
}

void CMyView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	g_TextViewWnd=this->GetSafeHwnd();
	// TODO: Add your specialized code here and/or call the base class
}
