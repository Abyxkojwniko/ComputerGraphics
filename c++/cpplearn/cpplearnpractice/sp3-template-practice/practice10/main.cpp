#include "TypeList.h"

int main() {
    std::cout << "--- 编译期 TypeList 长度计算测试 ---" << std::endl;

    // 1. 测试空列表
    using EmptyList = TypeList<>;
    static_assert(LengthOf<EmptyList>::value == 0, "空列表长度应为 0");
    std::cout << "空列表长度: " << LengthOf<EmptyList>::value << " (验证通过)" << std::endl;

    // 2. 测试包含 3 个类型的列表
    using List3 = TypeList<int, double, char>;
    static_assert(LengthOf<List3>::value == 3, "包含 3 个类型的列表长度应为 3");
    std::cout << "List<int, double, char> 长度: " << LengthOf<List3>::value << " (验证通过)" << std::endl;

    // 3. 测试包含 5 个类型的复杂列表
    using List5 = TypeList<int, std::string, std::vector<int>, bool, long>;
    static_assert(LengthOf<List5>::value == 5, "包含 5 个类型的列表长度应为 5");
    std::cout << "复杂列表长度: " << LengthOf<List5>::value << " (验证通过)" << std::endl;
    
    // 如果您尝试传递一个非 TypeList 的类型，例如：
    // static_assert(LengthOf<int>::value == 0, "应失败，因为 int 不是 TypeList"); 
    // ^ 这将触发主模板 LengthOf<List> 的使用，由于主模板没有 value 成员，会直接导致编译错误，这也是正确的设计。

    std::cout << "\n所有 LengthOf 计算都在编译期完成，完美！" << std::endl;

    return 0;
}