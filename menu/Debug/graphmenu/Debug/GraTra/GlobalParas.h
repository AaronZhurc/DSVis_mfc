#pragma once 
extern HWND g_MainViewWnd;
#define WM_REDRAW WM_USER+7
extern HWND g_TextViewWnd;
#define WM_RETEXT WM_USER+8
typedef struct node{
	int adjvertex;
	struct node* next;
}EdgeNode;
typedef struct vnode{
	int vertex;
	int x;
	int y;
	EdgeNode* firstedge;
}VertexNode;
typedef struct{
	VertexNode adjlist[30];
	int vertexNum; 
	int edgeNum;
}ALGraph;
extern ALGraph m_CtrlGraph;
extern int m_flagCtrl;
extern int m_countVertex;
extern int visited[30];
extern int m_VisitVertex[30];
extern int m_countPrint;
extern int m_countAdj;
extern int m_flagRadio;
extern int m_flagPrt;