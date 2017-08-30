//
//  Arrlist.h
//  DS_learning
//
//  Created by  唐 on 2017/8/22.
//  Copyright © 2017年 shusen tang. All rights reserved.
//


//顺序表相关算法
#ifndef Arrlist_h
#define Arrlist_h

void Arr_random_initial(int *array,int length,int max);//随机初始化为0-max之间的数
void swap(int *array,int i,int j);//交换数组元素L[i]L[j]
void P18_8(int *array,int length,int n);//王道DS P18第8题,循环右移n位
void Arr_reverse(int *array,int low,int high);//倒转low和high之间的元素



void Arr_random_initial(int *array,int length,int max)
{
    for (int i = 0; i < length; i++) {
        array[i] = random()%max;
    }
    
}


void swap_ij(int *array,int i,int j)
{
    int tmp;
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    
}

void P18_8(int *array,int length,int n)
{
    Arr_reverse(array, 0, length-1);
    Arr_reverse(array, 0, n-1);
    Arr_reverse(array, n, length-1);

}
void Arr_reverse(int *array,int low,int high)
{
    while (low < high) {
        swap_ij(array, low, high);
        low++;
        high--;
    }
}



#endif /* Arrlist_h */
