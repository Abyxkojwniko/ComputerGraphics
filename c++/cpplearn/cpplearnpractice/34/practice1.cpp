#include <iostream>
#include <type_traits> // 用于判断类型属性

int main() {
    //test1
    const int x = 10;
    
    // 问：y1 和 y2 的最终类型是什么？
    //y1的类型是const int， y2的类型是int&
    using Type_y1 = decltype(x);
    using Type_y2 = decltype((x));
    
    std::cout << "Type_y1 is const: " << std::is_const<Type_y1>::value << std::endl;
    std::cout << "Type_y1 is reference: " << std::is_reference<Type_y1>::value << std::endl;
    std::cout << "Type_y2 is const: " << std::is_const<Type_y2>::value << std::endl;
    std::cout << "Type_y2 is reference: " << std::is_reference<Type_y2>::value << std::endl;
    
    return 0;
}