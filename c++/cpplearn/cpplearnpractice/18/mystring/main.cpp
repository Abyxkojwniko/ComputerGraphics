#include <iostream>
#include "Mystring.h"

int main(){
    Mystring str1("hello");
    std::cout<<str1;
    Mystring str2("world");
    std::cout<<str2;
    auto str3=str1;
    std::cout<<str3;
    auto str4=std::move(str1);
    std::cout<<str4;
    auto str5=str1+" "+str2;
    std::cout<<str5;
    return 0;
}