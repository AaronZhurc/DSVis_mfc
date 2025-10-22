#pragma once
extern HWND g_MainViewWnd;
#define WM_REDRAW WM_USER+7
extern HWND g_TextViewWnd;
#define WM_RETEXT WM_USER+8
typedef struct node{
	int data;
	struct node* next;
}LNode,*LinkList;
extern LinkList m_ListCtrl;
extern int m_num;
extern int m_large;
extern int m_first;
extern int m_putout[100];
extern int m_flagfirst;
extern int m_count;
extern int m_flagButton;
extern LinkList m_pCtrl;
extern int m_flagPrt;