//
//  Tree.h
//  DS_learning
//
//  Created by  唐 on 2017/9/5.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#ifndef Tree_h
#define Tree_h
#define Elemtype int
#define MAXSIZE 20

typedef struct TreeNode{
    Elemtype data;
    struct TreeNode *fsc,*nsib;
}TreeNode,*Tree;


void print(Tree T);
void creatTree_by_Level_degree(Tree &T,Elemtype Level_Order_data[],int degree[],int n);
//通过树的层序遍历Level_Order_data[]及每个结点的度degree[]建立此树的左子-右兄链表，n为结点个数



void print(Tree T)
{
    if (T != NULL) {
        cout << T->data << ' ';
        print(T->fsc);
        print(T->nsib);
    }
}

void creatTree_by_Level_degree(Tree &T,Elemtype Level_Order_data[],int degree[],int n)
{
    Tree *pointer =new Tree[MAXSIZE];
    int i,j,dgr,k=0;
    for (i = 0; i < n; i++){
        pointer[i] = new TreeNode;
        pointer[i]->data = Level_Order_data[i];
        pointer[i]->fsc = pointer[i]->nsib = NULL;
    }
    for(i = 0; i<n; i++){
        dgr = degree[i];
        if (dgr) {
            k++;
            pointer[i]->fsc = pointer[k];
            for(j = 2; j <= dgr; j++){
                k++;
                pointer[k-1]->nsib = pointer[k];
            }
        }
    }
    T = pointer[0];
    delete [] pointer;
}




#endif /* Tree_h */
