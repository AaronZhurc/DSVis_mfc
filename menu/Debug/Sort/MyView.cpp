// MyView.cpp : implementation file
//

#include "stdafx.h"
#include "Sort.h"
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
	m_radio = -1;
	m_ctrl_gap = _T("");
	//}}AFX_DATA_INIT
}

CMyView::~CMyView()
{
}

void CMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyView)
	DDX_Radio(pDX, IDC_RADIO_BUBBLE, m_radio);
	DDX_Text(pDX, IDC_STATIC_GAP, m_ctrl_gap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyView, CFormView)
	//{{AFX_MSG_MAP(CMyView)
	ON_BN_CLICKED(IDC_BUTTON_SORT, OnButtonSort)
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

void CMyView::OnButtonSort() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_howSort!=m_radio){
		m_startflag=1;
		Restore();
	}
	m_howSort=m_radio;	if(m_shellflag==1){
		m_ctrl_gap="希尔排序被禁用";
	}else if(m_shellflag==0){
		m_ctrl_gap.Empty();
		m_ctrl_gap="步长 ";
		for(int i=0;i<m_gap.length;i++){
			CString a;
			a.Format("%d ",m_gap.r[i]);
			m_ctrl_gap+=a;
		}
	}
	UpdateData(false);
	m_sortflag=1;
	//m_startflag=1;
	if(m_howSort==0){
		BubbleSort();
	}else if(m_howSort==1){
		InsertSort();
	}else if(m_howSort==2&&m_shellflag==0){
		ShellSort();
	}else if(m_howSort==3){
		GetQuickSort();
	}
	::SendMessage(g_MainViewWnd,WM_REDRAW,(WPARAM)1,NULL);
}


void CMyView::BubbleSort()
{
	sqInt temp;
	if(m_startflag==1){
		m_startflag=0;
	}

	for(m_i=0;m_i<m_list.length&&m_sortflag==1;m_i++){
		for(m_j=0;m_j<m_list.length-1-m_i;m_j++){
			if(m_list.r[m_j].n>m_list.r[m_j+1].n){
				ResetFlag(1);
				temp = m_list.r[m_j];
				m_list.r[m_j] = m_list.r[m_j+1];
				m_list.r[m_j+1] = temp;
				m_sortflag=0;
				m_list.r[m_j+1].flag=1;
			}
		}
		for(int h=0;h<m_list.length;h++){
			if(m_list.r[h].flag==1||m_list.r[h].flag==2&&h+1<m_list.length){
				m_list.r[h+1].flag=2;
			}
		}
	}
	if(m_i==m_list.length&&m_sortflag==1){
		m_sortflag=0;
		Restore();
		m_startflag=1;
	}
}

void CMyView::InsertSort()
{
	sqInt temp;
	if(m_startflag==1){
		m_i=1;
		m_startflag=0;
	}
	int j;
	for(;m_i<m_list.length&&m_sortflag==1;m_i++)
    {
		temp=m_list.r[m_i];
		j=m_i-1;
		ResetFlag(2);
		while(j>=0&&temp.n<m_list.r[j].n){
			m_list.r[j+1]=m_list.r[j];
			j--;
			m_sortflag=0;
		}
		m_list.r[j+1]=temp;
		m_list.r[j+1].flag=1;
    }
	if(m_i==m_list.length&&m_sortflag==1){
		m_sortflag=0;
		Restore();
		m_startflag=1;
	}
}

void CMyView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_sortflag=0;
	m_countnum=0;
}

void CMyView::Restore()
{
	for(int i=0;i<m_list.length;i++){
		m_list.r[i]=m_store.r[i];
	}
}

void CMyView::ResetFlag(int i)
{
	int k;
	switch(i){
	case 1:
		for(k=0;k<m_list.length;k++){
    		if(m_list.r[k].flag!=2){
				m_list.r[k].flag=0;
			}
		}
		break;
	case 2:
		for(k=0;k<m_list.length;k++){
			if(m_list.r[k].flag==1){
				m_list.r[k].flag=2;
			}else if(m_list.r[k].flag!=2){
				m_list.r[k].flag=0;
			}
		}
		break;
	default:
		break;
	}
}

void CMyView::ShellSort()
{
	if(m_startflag==1){
		m_i=0;
		m_startflag=0;
	}
	for(;m_i<m_gap.length&&m_sortflag==1;m_i++){
		ShellInsert(m_gap.r[m_i]);
		m_sortflag=0;
	}
	if(m_i==m_gap.length&&m_sortflag==1){
		m_sortflag=0;
		Restore();
		m_startflag=1;
	}
}

void CMyView::ShellInsert(int gap)
{
	int i,j;
	sqInt outpost;
	for(i=gap;i<m_list.length;i++){
		if(m_list.r[i].n<m_list.r[i-gap].n){
			outpost=m_list.r[i];
			for(j=i-gap;j>=0&&outpost.n<m_list.r[j].n;j=j-gap)
				m_list.r[j+gap]=m_list.r[j];
			m_list.r[j+gap]=outpost;
		}
	}
}

void CMyView::GetQuickSort()
{
	if(m_startflag==1){
		m_countnum=0;
		m_startflag=0;
	}
	for(;m_countnum<m_record.num&&m_sortflag==1;m_countnum++){
		for(int i=0;i<m_list.length;i++){
			m_list.r[i]=m_record.r[m_countnum][i];
		}
		m_sortflag=0;
	}
	if(m_countnum==
		m_record.num&&m_sortflag==1){
		m_sortflag=0;
		Restore();
		m_startflag=1;
		m_countnum=0;
	}
}
