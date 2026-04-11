#include "TypeIdentity.h"

int main() {
    // 2. 使用 static_assert 和 std::is_same 验证
    
    // 检查 TypeIdentity<int>::type 是否与 int 是同一类型
    static_assert(std::is_same<TypeIdentity<int>::type, int>::value, 
                  "TypeIdentity<int>::type 必须等同于 int");
    
    // 检查 TypeIdentity<double>::type 是否与 double 是同一类型
    static_assert(std::is_same<TypeIdentity<double>::type, double>::value, 
                  "TypeIdentity<double>::type 必须等同于 double");

    // 编译时类型检查，如果下面的 assert 不通过，代码将编译失败并显示错误信息
    // static_assert(std::is_same<TypeIdentity<float>::type, int>::value, 
    //               "这是一个错误的检查，代码应该无法通过编译"); 

    std::cout << "TypeIdentity 验证通过，所有类型关系在编译时确认无误。" << std::endl;

    return 0;
}