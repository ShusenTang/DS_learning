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


#include "others.h"
#include "Arrlist.h"
#include "Linklist.h"
#include "BiTree.h"
#include "Tree.h"


int main(int argc, const char * argv[]) {

    Tree mytree;
    int data[] = {1,2,3,4,5,6};
    int degree[] = {3, 1, 0, 1, 0, 0};
    creatTree_by_Level_degree(mytree, data, degree,6);
    print(mytree);
    return 0;
}

