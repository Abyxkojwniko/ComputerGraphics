/*
编写一个C++程序，输入一个`3x3`的矩阵，计算其转置矩阵，并输出结果。
*/


#include<iostream>

int main(){
    int matrix[3][3];
    std::cout << "请输入3x3矩阵的元素（共9个整数）:" << std::endl;
    for(int (*p)[3]=matrix;p!=matrix+3;p++){
        for(int *q=*p;q!=*p+3;q++){
            std::cin>>*q;
        }
    }
    std::cout << "the transform matrix is:" << std::endl;
    for(int i=0;i!=3;i++){
        for(int j=0;j!=3;j++){
            std::cout<<matrix[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}