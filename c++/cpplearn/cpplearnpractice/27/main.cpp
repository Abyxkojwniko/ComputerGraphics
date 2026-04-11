#include <iostream>
#include "Complex.h"
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Complex c1(3.0,4.0);
    Complex c2(1.5,-2.5);
    auto c3 = c1+c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;
    auto c4 = c1-c2;
    std::cout << "c1 - c2 = " << c4 << std::endl;
    c4 = c1;
    std::cout << "c4 = " << c4 << std::endl;
    auto bres = (c4==c1);
    std::cout << "c4 == c1 = " << bres << std::endl;

    RealObject real;
    Proxy proxy(&real);

    proxy->display(); // 使用重载的 -> 运算符
    return 0;
}
