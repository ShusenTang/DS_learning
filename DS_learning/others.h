//
//  others.h
//  DS_learning
//
//  Created by  唐 on 2017/8/22.
//  Copyright © 2017年 shusen tang. All rights reserved.
//

#ifndef others_h
#define others_h

long Fib(int n);//非递归计算斐波那契数列

long Fib(int n)
{
    if (n<0){
        cout << "斐波那契数列输入必须非负！";
        exit(0);
    }
    else if (n<2) return 1;
    else{
        long Fn_1,Fn_2,tmp;
        Fn_1 = Fn_2 = 1;
        for (int i = 1; i < n; i++) {
            tmp = Fn_1;
            Fn_1 = tmp + Fn_2;
            Fn_2 = tmp;
        }
        return Fn_1;
    }
}





#endif /* others_h */
