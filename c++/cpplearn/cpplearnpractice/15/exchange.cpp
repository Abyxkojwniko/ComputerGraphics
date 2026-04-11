/*
题目：使用位运算符，交换两个整数变量的值而不使用第三个变量。
*/

#include<iostream>

int main(){
    int a=15,b=10;
    std::cout<<"before swap "<<a<<" "<<b<<std::endl;
    a=a+b;
    b=a-b;
    a=a-b;
    std::cout<<"after swap "<<a<<" "<<b<<std::endl;
    return 0;
}