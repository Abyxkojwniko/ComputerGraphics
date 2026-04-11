/*
编写一个函数，接受一个整数指针，使用解引用运算符修改其值为原值的平方。
*/
#include<iostream>

void squire(int *num){
    *num*=*num;
}

int main(){
    int num=5;
    std::cout<<"before:"<<num<<std::endl;
    squire(&num);
    std::cout<<"after:"<<num<<std::endl;
    return 0;
}