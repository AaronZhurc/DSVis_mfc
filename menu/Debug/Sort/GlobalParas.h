#pragma once
extern HWND g_MainViewWnd;
#define WM_REDRAW WM_USER+7
#define MAXSIZE 100
typedef struct{
	int n;
	int s;
	int flag;
}sqInt;
typedef struct{
	sqInt r[MAXSIZE+1];
	int length;
}SqList;
typedef struct{
	int r[MAXSIZE+1];
	int length;
}ESqList;
typedef struct{
	sqInt r[MAXSIZE+1][MAXSIZE+1];
	int num;
}QSqList;
extern SqList m_list;
extern SqList m_store;
extern SqList m_sorted;
extern int m_howSort;
extern int m_startflag;
extern ESqList m_gap;
extern int m_shellflag;
extern QSqList m_record;