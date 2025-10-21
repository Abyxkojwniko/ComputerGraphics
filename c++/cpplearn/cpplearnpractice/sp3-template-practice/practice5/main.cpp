 #include "Pointer.h"
 
 int main() {
    std::cout << "--- 测试 IsPointer (模板元编程) ---" << std::endl;

    // --- 正确判断：int* 是指针 ---
    static_assert(IsPointer<int*>::value, "int* is a pointer");
    std::cout << "int* IsPointer::value: " << IsPointer<int*>::value << std::endl; // 输出 1

    // --- 正确判断：int 不是指针 ---
    static_assert(!IsPointer<int>::value, "int is not a pointer");
    std::cout << "int IsPointer::value: " << IsPointer<int>::value << std::endl;  // 输出 0
    
    // --- 额外测试：其他指针类型 ---
    static_assert(IsPointer<double*>::value, "double* is a pointer");
    static_assert(IsPointer<const char*>::value, "const char* is a pointer");
    std::cout << "double* IsPointer::value: " << IsPointer<double*>::value << std::endl; // 输出 1
    
    // --- 额外测试：非指针复杂类型 ---
    static_assert(!IsPointer<std::string>::value, "std::string is not a pointer");
    std::cout << "std::string IsPointer::value: " << IsPointer<std::string>::value << std::endl; // 输出 0

    return 0;
}