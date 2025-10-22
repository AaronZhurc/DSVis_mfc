#include <stdlib.h>
#include <stdio.h>

#define M 6
#define N 8
int maze[M+2][N+2]={
	1,1,1,1,1,1,1,1,1,1,
	1,0,1,1,1,0,1,1,1,1,
	1,0,0,0,0,1,1,1,1,1,
	1,0,1,0,0,0,0,0,1,1,
	1,0,1,1,1,0,0,1,1,1,
	1,1,0,0,1,1,0,0,0,1,
	1,0,1,1,0,0,1,1,0,1,
	1,1,1,1,1,1,1,1,1,1};

typedef struct{
	int x,y;
}item;
item move[4];

typedef struct{
	int x,y,d;
}typemaze;

typedef struct node{
	typemaze data;
	struct node* next;
}StackNode,*PStackNode;
typedef struct{
	PStackNode top;
}LinkStack,*PLinkStack;

PLinkStack Init_LinkStack(){
	PLinkStack S;
	S=(PLinkStack)malloc(sizeof(LinkStack));
	if(S)
		S->top=NULL;
	return S;
}

int Push_LinkStack(PLinkStack S,typemaze x){
	PStackNode p;
	p=(PStackNode)malloc(sizeof(StackNode));
	if(!p){
		printf("内存溢出\n");
		return 0;
	}
	p->data=x;
	p->next=S->top;
	S->top=p;
	return 1;
}

int Pop_LinkStack(PLinkStack S,typemaze* x){
	PStackNode p;
	if(S->top==NULL){
		printf("栈空\n");
		return 0;
	}
	*x=S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	return 1;
}

void Destroy_LinkStack(PLinkStack *S){
	PStackNode p,q;
	if(*S){
		p=(*S)->top;
		while(p){
			q=p;
			p=p->next;
			free(q);
		}
		free(*S);
	}
	*S=NULL;
	return;
}

void Init_Move(){
	move[0].x=0;
	move[0].y=1;
	move[1].x=1;
	move[1].y=0;
	move[2].x=0;
	move[2].y=-1;
	move[3].x=-1;
	move[3].y=0;
}

int mazepath(int x0,int y0){
	PLinkStack S;
	typemaze temp;
	int x,y,d,i,j;
	temp.x=x0;
	temp.y=y0;
	temp.d=-1;
	S=Init_LinkStack();
	Init_Move();
	if(!S){
		printf("栈初始化失败\n");
		return 0;
	}
	Push_LinkStack(S,temp);
	while(S->top!=NULL){
		Pop_LinkStack(S,&temp);
		x=temp.x;
		y=temp.y;
		d=temp.d+1;
		while(d<4){
			i=x+move[d].x;
			j=y+move[d].y;
			if(maze[i][j]==0){
				temp.x=x;
				temp.y=y;
				temp.d=d;
				Push_LinkStack(S,temp);
				x=i;
				y=j;
				maze[x][y]=-1;
				if(x==M&&y==N){
					while(S->top!=NULL){
						Pop_LinkStack(S,&temp);
						printf("(%d,%d,%d)<-",temp.x,temp.y,temp.d);
					}
					Destroy_LinkStack(&S);
					return 1;
				}
				else
					d=0;
			}
			else
				d++;
		}
	}
	Destroy_LinkStack(&S);
	return 0;
}

int main(){
	printf("迷宫的样式\n");
	for(int i=1;i<M+1;i++){
		for(int j=1;j<N+1;j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf("路径\n");
	printf("(6,8)<-");
	mazepath(1,1);
	printf("\n");
	return 0;
}



