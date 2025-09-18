#include "IsPointer.h"

int main() {
    // 测试非指针类型
    static_assert(IsPointer<int>::value == false, "int should not be pointer");
    static_assert(IsPointer<double>::value == false, "double should not be pointer");

    // 测试指针类型
    static_assert(IsPointer<int*>::value == true, "int* should be pointer");
    static_assert(IsPointer<double*>::value == true, "double* should be pointer");
    static_assert(IsPointer<const char*>::value == true, "const char* should be pointer");

    // 测试多级指针
    static_assert(IsPointer<int**>::value == true, "int** should be pointer");

    return 0;
}