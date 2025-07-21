/*
题目描述

编写一个C++程序，输入两个`2x3`的矩阵，计算它们的和，并输出结果矩阵。
*/


#include<iostream>

int main(){
    const int row=2;
    const int col=3;
    int m1[row][col],m2[row][col];
    std::cout << "请输入第一个2x3矩阵的元素(共6个整数):" << std::endl;
    for(int (*p)[3]=m1;p!=m1+2;p++){
        for(int *q=*p;q!=*p+3;q++){
            std::cin>>*q;
        }
    }
    std::cout << "请输入第二个2x3矩阵的元素(共6个整数):" << std::endl;
    for(int (*p)[3]=m2;p!=m2+2;p++){
        for(int *q=*p;q!=*p+3;q++){
            std::cin>>*q;
        }
    }
    std::cout << "两个矩阵的和为:" << std::endl;
    for(int i=0;i!=2;i++){
        for(int j=0;j!=3;j++){
            std::cout<<m1[i][j]+m2[i][j]<<std::endl;
        }
    }
    return 0;
}

