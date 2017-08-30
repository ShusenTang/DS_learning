//
//  Linklist.h
//  DS_learning
//
//  Created by  唐 on 2017/8/25.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#ifndef Linklist_h
#define Linklist_h

#define Elemtype int

typedef struct LNode{
    struct LNode *next;
    Elemtype data;
}LNode,*Linklist;

void createLinklist(Linklist &L);

void createLinklist(Linklist &L)
{
    LNode *head = new LNode;//带头结点
    L = head;
    head->next = NULL;
    
    Elemtype input;
    LNode *last = head;//记录最后一个节点
    cout << "请输入若干个int型数据以建立链表，9999并回车代表结束:" << endl;
    cin >> input;
    while (input != 9999) {
        LNode *node = new LNode;
        node -> data = input;
        node -> next = last -> next;//尾插法建立链表
        last -> next = node;
        last = node;
        cin >> input;
    }
    
    
}


#endif /* Linklist_h */
