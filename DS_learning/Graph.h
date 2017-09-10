//
//  Graph.h
//  DS_learning
//
//  Created by  唐 on 2017/9/10.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#define MAXSIZE 20         //最大顶点个数
#define INF 32767          //INF表示∞
int visited[MAXSIZE];      //定义存放节点的访问标志的全局数组

//以下定义邻接表类型
typedef struct ArcNode          //弧的结点结构类型
{
    int adjvex;                 //该弧指向的位置
    struct ArcNode *nextarc;    //指向下一条弧的指针
    int info;                   //该弧的相关信息,这里用于存放权值
} ArcNode;

typedef int Vertex;

typedef struct Vnode            //邻接表头结点的类型
{
    Vertex data;                //顶点信息
    int count;                  //存放顶点入度,只在拓扑排序中用
    ArcNode *firstarc;          //指向第一条弧
} VNode,AdjList[MAXSIZE];          //AdjList是邻接表类型

typedef struct
{
    AdjList adjlist;            //邻接表
    int vexnum,arcnum;          //图中顶点数和边数
} ALGraph;                      //ALGraph是图的邻接表类型

void ArrayToList(int Arr[], int n, ALGraph *&G); //用n*n个元素的一维数组构造图的邻接表
/* 也或者传入二维数组
     int A[5][5]={
         {0,1,0,1,0},
         {1,0,1,0,0},
         {0,1,0,1,1},
         {1,0,1,0,1},
         {0,0,1,1,0} };
      ArrayToList(A[0], 5, G);//二维数组时注意这里是A[0]而不是A
 */
void FindPaths(ALGraph *G,int u,int v,int path[],int d);



void ArrayToList(int Arr[], int n, ALGraph *&G)
{
    int i,j,count=0;  //count用于统计边数，即矩阵中非0元素个数
    ArcNode *p;
    G = new ALGraph;
    G->vexnum = n;
    for (i=0; i<n; i++)                 //给邻接表中所有头节点的指针域置初值
        G->adjlist[i].firstarc=NULL;
    for (i=0; i<n; i++)                 //检查邻接矩阵中每个元素
        for (j=n-1; j>=0; j--)
            if (Arr[i*n+j]!=0)      //存在一条边，将Arr看作n×n的二维数组，Arr[i*n+j]即是Arr[i][j]
            {
                p=new ArcNode;   //创建一个节点*p
                p->adjvex=j;
                p->info=Arr[i*n+j];
                p->nextarc=G->adjlist[i].firstarc;      //采用头插法插入*p
                G->adjlist[i].firstarc=p;
            }
    
    G->arcnum=count;
}


void FindPaths(ALGraph *G,int u,int v,int path[],int d)
//d是到当前为止已走过的路径长度，调用时初值为-1
{
    int w,i;
    ArcNode *p;
    visited[u]=1;
    d++;                    //路径长度增1
    path[d]=u;              //将当前顶点添加到路径中
    if (u==v)            //输出一条路径
    {
        cout<< path[0] << "到" << v << "的其中一条简单路径是： "<< path[0];
        for (i=1; i<=d; i++)   cout << "->"<<path[i];
        cout << endl;
        
        visited[u]=0;   //恢复环境
        return;
    }
    
    p=G->adjlist[u].firstarc; //p指向u的第一条边
    while(p!=NULL)
    {
        w=p->adjvex;     //w为u的邻接顶点
        if (visited[w]==0)      //若顶点未标记访问，则递归访问之
            FindPaths(G,w,v,path,d);
        p=p->nextarc; //找u的下一个邻接顶点
    }
    visited[u]=0;   //恢复环境
}



#endif /* Graph_h */
