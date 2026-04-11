#include "isEven.h"
#include <iostream>
#include <locale> // 引入本地化头文件
#include <cstdlib> // 引入 std::system

int main() {

    std::cout << "--- 测试 isEven 函数 ---" << std::endl;

    // 整型测试
    int a = 10;
    long b = 11L;
    short c = 4;

    std::cout << "int 10 is even? " << (isEven(a) ? "yes" : "no") << std::endl;
    std::cout << "long 11 is even? " << (isEven(b) ? "yes" : "no") << std::endl;
    std::cout << "short 4 is even? " << (isEven(c) ? "yes" : "no") << std::endl;

    // 浮点型测试 (会编译失败，证明 Concept 生效！)
    // double d = 4.0;
    // isEven(d); // 编译错误: 'double' 不满足 Concept 'Integral'

    // 自定义类型测试 (会编译失败)
    // struct MyType {};
    // MyType mt;
    // isEven(mt); // 编译错误: 'MyType' 不满足 Concept 'Integral'

    return 0;
}