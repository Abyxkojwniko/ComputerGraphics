#include "TypeIdentity.h"

int main() {
    // 示例用法（编译时已通过 static_assert 验证）
    TypeIdentity<float>::type value = 3.14f;
    return 0;
}