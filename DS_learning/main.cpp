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
#include "Graph.h"


int main(int argc, const char * argv[]) {


    ALGraph *G;
    int path[MAXSIZE];
    int A[9] = {0,1,1,
                1,0,1,
                1,1,0};
    ArrayToList(A, 3, G);
    FindPaths(G,0,2,path,-1);
    return 0;
}



