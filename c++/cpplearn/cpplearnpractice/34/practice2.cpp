#include <iostream>
#include <type_traits>

template<typename T>
void wrapper(T&& param) {
    // 问：T 和 decltype(param) 的类型属性是什么？
    
    // 1. T的属性
    std::cout << "T is reference: " << std::is_reference<T>::value << std::endl;
    // 2. decltype(param) 的属性
    std::cout << "decltype(param) is lvalue reference: " << std::is_lvalue_reference<decltype(param)>::value << std::endl;
}

int main() {
    int val = 5;
    wrapper(val); // 传入左值
    return 0;
}