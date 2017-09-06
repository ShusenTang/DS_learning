//
//  ParTree.h
//  DS_learning
//
//  Created by  唐 on 2017/9/6.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#ifndef ParTree_h
#define ParTree_h

#define MAXSIZE 20
#define ElemType int

typedef struct{
    ElemType data;
    int parent;
}ParTreeNode;

int parfind(ParTreeNode partree[],int i);//路径压缩技术：返回当前结点所在集合标识符(即根节点)，并将当前结点到根节点路径上所有结点的parent设为根
void creat_ParTree(ParTreeNode partree[],ElemType data[],int parent[],int n);
/*
main函数示例：
 ParTreeNode *mypartree = new ParTreeNode[MAXSIZE];
 int parent[11]={-1,-1,1,1,2,2,5,5,5,7,7};
 int data[11] = {0};
 creat_ParTree(mypartree, data, parent, 11);
 */

void ParUnion(ParTreeNode partree[],int root1,int root2);



int parfind(ParTreeNode partree[],int i)
{
    if(partree[i].parent < 0) return i;
    partree[i].parent = parfind(partree, partree[i].parent);
    return partree[i].parent;
}

void creat_ParTree(ParTreeNode partree[],ElemType data[],int parent[],int n)
{
    if(n == 0) return;
    for (int i = 0; i < n; i++) {
        partree[i].data = data[i];
        partree[i].parent = parent[i];
    }
}

void ParUnion(ParTreeNode partree[],int root1,int root2)
{
    if (root1 != root2) partree[root2].parent = root1;
}



#endif /* ParTree_h */
