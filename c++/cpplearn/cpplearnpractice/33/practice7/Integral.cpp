#include "Integral.h"

int main() {
    // 测试整数类型
    std::cout << std::boolalpha;
    std::cout << "42 is even: " << isEven(42) << '\n';         // int
    std::cout << "17u is even: " << isEven(17u) << '\n';       // unsigned int
    std::cout << "100L is even: " << isEven(100L) << '\n';     // long
    std::cout << "'A' is even: " << isEven('A') << '\n';       // char (ASCII 65)
    std::cout << "false is even: " << isEven(false) << '\n';   // bool

    // 测试非整数类型（编译错误）
    // float f = 3.14f;
    // std::cout << isEven(f) << '\n';  // 错误：不满足约束
    
    return 0;
}
