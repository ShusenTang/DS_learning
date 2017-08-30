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


void  test (Linklist L);


int main(int argc, const char * argv[]) {

    BiTree mytree;
    creat_a_test_BiTree(mytree);
    
//    PreOrderWithRecursion(mytree);
//    cout << endl;
//    InOrderWithRecursion(mytree);
//    cout << endl;
//    PostOrderWithRecursion(mytree);
//    cout << endl;
//    PostOrderWithoutRecursion(mytree);
//    cout << endl;
    LevelOrder(mytree);
    
    return 0;
}

