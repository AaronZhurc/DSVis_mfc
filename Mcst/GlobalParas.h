#pragma once
extern HWND g_MainViewWnd;
#define WM_REDRAW WM_USER+7
#define MaxVertexNum 100
struct eNode{
	int name;
	struct vNode* vertex1,* vertex2;
	int v1,v2;
	int weight;
	int mark;
};
struct vNode{
	int name;
	int x;
	int y;
	struct eNode* edges[MaxVertexNum];
	int edgeNum;
};
typedef struct eNode ENode;
typedef struct vNode VNode;
typedef struct{
	int vertexNum,edgeNum;
	VNode vertexs[MaxVertexNum];
	ENode edges[MaxVertexNum];
}ELGraph;
extern ELGraph m_graph;
extern int m_flagCtrl;
extern int m_countVertex;
extern int m_countEdge;
extern int m_flagBuild;

