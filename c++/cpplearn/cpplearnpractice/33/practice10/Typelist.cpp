#include "Typelist.h"

int main() {
    // 测试空列表
    using EmptyList = TypeList<>;
    static_assert(LengthOf<EmptyList>::value == 0, "Empty list should have length 0");

    // 测试单元素列表
    using SingleList = TypeList<int>;
    static_assert(LengthOf<SingleList>::value == 1, "Single element list should have length 1");

    // 测试多元素列表
    using MultiList = TypeList<int, double, char, void*>;
    static_assert(LengthOf<MultiList>::value == 4, "Multi-element list should have length 4");

    // 测试嵌套列表（作为类型元素）
    using NestedList = TypeList<TypeList<int, double>, TypeList<char>>;
    static_assert(LengthOf<NestedList>::value == 2, "Nested list should count outer elements");

    return 0;
}