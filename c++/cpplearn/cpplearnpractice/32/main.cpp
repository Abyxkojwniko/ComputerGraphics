#include "sfinae.h"
#include <iostream>

int main(){
    int x = 10;
    print_type(10);
    float y = 3.14;
    print_type(y);
    const char* cstr = "hello zack";
    print_type(cstr);
    std::string str = "Hello World";
    print_type(str);
    print_type(&x);
    cout_type(10);
    cout_type(y);
    cout_type(cstr);
    cout_type(str);
    cout_type(&x);

    WithFoo wf;
    call_foo(wf);


    TypePrinter<WithValueType>::print();
    
    return 0;
}