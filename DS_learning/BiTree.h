//
//  BiTree.h
//  DS_learning
//
//  Created by  唐 on 2017/8/29.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h

#define MAXSIZE  20
#define ElemType int

typedef struct BiTNode{
    struct BiTNode *leftchild,*rightchild;
    ElemType data;
}BiTNode,*BiTree;



void creat_a_test_BiTree(BiTree &T);
void visit(BiTNode *node);
void PreOrderWithRecursion(BiTree T);
void InOrderWithRecursion(BiTree T);
void PostOrderWithRecursion(BiTree T);
void PostOrderWithoutRecursion(BiTree T);
void LevelOrder(BiTree T);
int BitreeHeight(BiTree T);






void creat_a_test_BiTree(BiTree &T)
/*       0
        / \
       1   2
        \   \
         3   4
        /
       5
 */
{
    BiTNode *node[6];
    for (int i = 0; i < 6; i++) {
        node[i] = new BiTNode;
        node[i]->data = i;
        node[i]->leftchild = NULL;
        node[i]->rightchild = NULL;
    }
    
    node[0]->leftchild = node[1];
    node[0]->rightchild = node[2];
    
    node[1]->rightchild = node[3];
    
    node[2]->rightchild = node[4];
    
    node[3]->leftchild = node[5];
    T = node[0];
}


void visit(BiTNode *node)
{
    cout << node->data << ' ';
}


void PreOrderWithRecursion(BiTree T)
{
    if(T){
        visit(T);
        PreOrderWithRecursion(T->leftchild);
        PreOrderWithRecursion(T->rightchild);
    }
}

void InOrderWithRecursion(BiTree T)
{
    if(T){
        InOrderWithRecursion(T->leftchild);
        visit(T);
        InOrderWithRecursion(T->rightchild);
    }
}

void PostOrderWithRecursion(BiTree T)
{
    if(T){
        PostOrderWithRecursion(T->leftchild);
        PostOrderWithRecursion(T->rightchild);
        visit(T);
    }
}

void PostOrderWithoutRecursion(BiTree T)
{
    enum TagType {LEFT,RIGHT};                  //tag记录从左还是右子树返回
    typedef struct{
        BiTNode *pointer;
        TagType tag;
    }stackElem;                                 //stack元素类型
    
    stackElem node;
    BiTNode *pointer = T;                       //工作指针
    stackElem stack[MAXSIZE];
    int top=0;                                  //栈顶指针
    if (T == NULL ) return;                     //空树
    while (top>0 || pointer) {
        while (pointer) {                       //一路下降到最左结点
            node.pointer = pointer;
            node.tag = LEFT;                    //LEFT表示进入左子树
            stack[top++] = node;                //入栈
            pointer = pointer -> leftchild;
        }
        node = stack[--top];                    //出栈
        pointer = node.pointer;
        if (node.tag == LEFT) {                 //从左子树返回
            node.tag = RIGHT;                   //置为RIGHT表示进入右子树
            stack[top++] = node;                //入栈
            pointer = pointer -> rightchild;
        }
        else{                                   //从右子树返回，可以访问
            visit(pointer);
            pointer = NULL;                     //置pointer为空以再次弹栈
        }
    }
}

void LevelOrder(BiTree T)
{
    if(T==NULL) return;                   //空树
    BiTNode *queue[MAXSIZE];
    int front=0,rear=0;
    BiTNode *p=T;
    queue[rear++] = p;
    while (rear!=front) {                   //队非空
        p = queue[front++];                 //出队
        visit(p);
        if (p->leftchild)                   //将左孩子入队
            queue[rear++] = p -> leftchild;
        if (p->rightchild)                  //将右孩子入队
            queue[rear++] = p -> rightchild;
      
    }
}

int BitreeHeight(BiTree T)//利用层序遍历思想计算树高
{
    int height = 0;
    if(T==NULL) return 0;                   //空树
    BiTNode *queue[MAXSIZE];
    int front=0,rear=0;
    BiTNode *p=T;
    queue[rear++] = p;                      //根入队
    int last = rear - 1;                    //last记录每层最后一个结点
    while (rear!=front) {                   //队非空
        p = queue[front++];                 //出队
        //visit(p);
        if (p->leftchild)                   //将左孩子入队
            queue[rear++] = p -> leftchild;
        if (p->rightchild)                  //将右孩子入队
            queue[rear++] = p -> rightchild;
        
        if (front == last + 1){             //若刚刚出队的是一层中最后一个结点
            height++;
            last = rear-1;                  //last更新到下一层
        }
    }
    return height;
}





#endif /* BiTree_h */
