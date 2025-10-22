#pragma once
extern HWND g_MainViewWnd;
#define WM_REDRAW WM_USER+7
extern HWND g_TextViewWnd;
#define WM_RETEXT WM_USER+8
extern int m_LeafNum;
extern int m_LeafArr[100];
typedef struct Leaves{
	int weight;
	int height;
	char name;
	char code[100];
	double width;//标识在绘制后树里的横向位置
	struct Leaves* rchild,* lchild,* parent;//操作数
	struct Leaves* prior,* next;//操作数组
}Leaves;
extern Leaves* m_LeafCtrl;
extern int m_TreeHigh;
extern int m_flagWidth;
extern int m_flagCode;
extern int m_LeafNum1;
extern int m_flagPrt;
