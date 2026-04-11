/*
编写一个 C++ 程序，使用嵌套的 `for` 循环来打印标准的九九乘法表。输出的格式应整齐对齐，便于阅读。
*/

#include<iostream>


int main(){
    std::cout<<"print 99 multiply"<<std::endl;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            std::cout<<i<<"*"<<j<<"="<<i*j<<"\t";
        }
        std::cout<<std::endl;
    }
    return 0;
}