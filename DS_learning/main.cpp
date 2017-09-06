//
//  main.cpp
//  DS_learning
//
//  Created by  唐 on 2017/8/22.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXSIZE 20


#include "others.h"
#include "Arrlist.h"
#include "Linklist.h"
#include "BiTree.h"
#include "Tree.h"
#include "ParTree.h"


int main(int argc, const char * argv[]) {


    int tmp;
    ParTreeNode *mypartree = new ParTreeNode[MAXSIZE];
    int parent[11]={-1,-1,1,1,2,2,5,5,5,7,7};
    int data[11] = {0};
    creat_ParTree(mypartree, data, parent, 11);
    tmp = parfind(mypartree, 7);
    cout <<  "7属于集合" << tmp << "。路径压缩后此时集合关系为："<< endl;
    for (int i = 0; i<11 ; i++) cout << mypartree[i].parent << " ";
    cout << endl;
    
    ParUnion(mypartree, 1, 0);
    for (int i = 0; i<11 ; i++) cout << mypartree[i].parent << " ";
    cout << endl;
    return 0;
}



