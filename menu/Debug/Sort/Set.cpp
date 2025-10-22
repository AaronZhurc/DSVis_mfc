// Set.cpp : implementation file
//

#include "stdafx.h"
#include "Sort.h"
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
	m_set_num = _T("");
	m_set_gap = _T("");
	//}}AFX_DATA_INIT
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
	DDX_Text(pDX, IDC_EDIT_SET_NUM, m_set_num);
	DDX_Text(pDX, IDC_EDIT_SET_GAP, m_set_gap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSet, CDialog)
	//{{AFX_MSG_MAP(CSet)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_GEN, OnButtonGen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnButtonOk() 
{
	// TODO: Add your control notification handler code here
	int m_flagExit=0,i,m_flagMark,m_ListLength=0;
	UpdateData(true);
	CString str;
	CString strc;
	for(i=0;i<m_set_num.GetLength();i++){
		if(m_set_num.GetAt(i)==','){
			m_flagMark=0;
			m_ListLength++;
		}
		if(m_set_num.GetAt(i)==' '){
			m_flagMark=1;
			m_ListLength++;
		}
	}
	m_list.length=++m_ListLength;
	for(i=0;i<m_ListLength;i++){
		if(m_flagMark==0){
			AfxExtractSubString(str,m_set_num,i,',');
		}else if(m_flagMark==1){
			AfxExtractSubString(str,m_set_num,i,' ');
		}
		if(str.IsEmpty()){
			m_flagExit=1;
		}else{
			m_list.r[i].n=atoi(str);
			m_store.r[i].n=m_list.r[i].n;
			m_sorted.r[i].n=m_list.r[i].n;
			m_list.r[i].flag=0;
			m_store.r[i].flag=0;
			m_sorted.r[i].flag=0;
		}
	}
	m_sorted.length=m_list.length;
	m_store.length=m_list.length;
	Sort();
	m_ListLength=0;
	for(i=0;i<m_set_gap.GetLength();i++){
		if(m_set_gap.GetAt(i)==','){
			m_flagMark=0;
			m_ListLength++;
		}
		if(m_set_gap.GetAt(i)==' '){
			m_flagMark=1;
			m_ListLength++;
		}
	}
	m_gap.length=++m_ListLength;
	for(i=0;i<m_ListLength;i++){
		if(m_flagMark==0){
			AfxExtractSubString(str,m_set_gap,i,',');
		}else if(m_flagMark==1){
			AfxExtractSubString(str,m_set_gap,i,' ');
		}
		if(str.IsEmpty()){
			m_flagExit=2;
		}else{
			m_gap.r[i]=atoi(str);
		}
	}
	if(m_gap.r[m_gap.length-1]!=1){
		m_gap.r[m_gap.length]=1;
		m_gap.length++;
	}
	GetRecord();
	if(m_flagExit==0){
		m_shellflag=0;
		CDialog::OnOK();
	}else if(m_flagExit==1){
		AfxMessageBox("输入不能为空");
	}else if(m_flagExit==2){
		int flag;
		flag=AfxMessageBox("如果不填写步长，将会关闭希尔排序",MB_OKCANCEL);
		m_shellflag=1;
		if(flag==IDOK)
			CDialog::OnOK();
	}
}

void CSet::Sort()
{
	sqInt temp;
	int i,j;
	for(i=0;i<m_sorted.length;i++){
		for(j=0;j<m_sorted.length-1-i;j++){
			if(m_sorted.r[j].n>m_sorted.r[j+1].n){
				temp = m_sorted.r[j];
				m_sorted.r[j] = m_sorted.r[j+1];
				m_sorted.r[j+1] = temp;
			}
		}
	}
	for(i=0;i<m_list.length;i++){
		for(j=0;j<m_list.length;j++){
			if(m_list.r[i].n==m_sorted.r[j].n){
				m_list.r[i].s=j;
				break;
			}
		}
	}
	for(i=0;i<m_list.length;i++){
		m_store.r[i].s=m_list.r[i].s;
	}
}

void CSet::OnButtonGen() 
{
	// TODO: Add your control notification handler code here
	CString str="生成的数组为：";
	for(int i=0;i<10;i++){
		m_list.r[i].n=(rand()%(100-0+1))+0;
		m_store.r[i].n=m_list.r[i].n;
		m_sorted.r[i].n=m_list.r[i].n;
		CString a;
		a.Format("%d ",m_list.r[i].n);
		str+=a;
		m_list.r[i].flag=0;
		m_store.r[i].flag=0;
		m_sorted.r[i].flag=0;
	}
	m_list.length=10;
	m_store.length=10;
	m_sorted.length=10;
	Sort();
	m_gap.length=3;
	m_gap.r[0]=5;
	m_gap.r[1]=3;
	m_gap.r[2]=1;
	GetRecord();
	AfxMessageBox(str);
	CDialog::OnOK();
}

void CSet::Restore()
{
	for(int i=0;i<m_list.length;i++){
		m_list.r[i]=m_store.r[i];
	}
}

void CSet::QuickSort(int low, int high)
{
	int pivotloc;
	if(low<high){
		pivotloc=QuickSort1(low,high);
		QuickSort(low,pivotloc-1);
		QuickSort(pivotloc+1,high);
	}

}

int CSet::QuickSort1(int low, int high)
{
	static int k=0;
	for(int i=0;i<m_list.length;i++){
		m_list.r[i].flag=0;
	}
	sqInt pivotkey;
	pivotkey=m_list.r[low];
	while(low<high){
		while(low<high&&m_list.r[high].n>=pivotkey.n)
			high--;
		m_list.r[low]=m_list.r[high];
		while(low<high&&m_list.r[low].n<=pivotkey.n)
			low++;
		m_list.r[high]=m_list.r[low];
	}
	m_list.r[low]=pivotkey;
	m_list.r[low].flag=1;
	for(i=0;i<m_list.length;i++){
		m_record.r[k][i]=m_list.r[i];
	}
	k++;
	m_record.num=k;
	return low;
}

void CSet::GetRecord()
{
	CleanRecord();
	QuickSort(0,m_list.length-1);
	Restore();
}

void CSet::CleanRecord()
{
	for(int i=0;i<MAXSIZE+1;i++){
		for(int j=0;j<MAXSIZE+1;j++){
			m_record.r[i][j].n=0;
			m_record.r[i][j].s=0;
			m_record.r[i][j].flag=0;
		}
	}
	m_record.num=0;
}
