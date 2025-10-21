#include "sfinae.h"


// 完整的测试代码

int main() {
    std::vector<int> v = {1, 2, 3};
    std::list<int> l = {4, 5};
    int i = 10;

    std::cout << "--- Testing SFINAE with std::enable_if ---" << std::endl;
    // 1. 测试 std::vector<int> (应启用)
    enableIfExample(v); 

    // 2. 测试 std::list<int> (应启用)
    enableIfExample(l);

    // 3. 测试 int (不应启用，编译时会失败/找不到匹配的函数)
    // enableIfExample(i); // <-- **取消注释会触发编译错误 (SFINAE生效)**
                         // error: no matching function for call to 'enableIfExample(int&)'

    // 如果支持 C++20，测试 Concepts 版本
    std::cout << "\n--- Testing C++20 Concepts ---" << std::endl;
    enableIfExample(v);
    // enableIfExample_concepts(i); // <-- 同样会因为 Concept 不满足而触发编译错误

    return 0;
}