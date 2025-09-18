#include "enableIfExample.h"

int main() {
    // 测试有 size() 的类型
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<double> lst = {1.1, 2.2, 3.3};
    
    std::cout << "Testing std::vector<int>: ";
    printSize(vec);
    
    std::cout << "Testing std::list<double>: ";
    printSize(lst);
    
    // 测试没有 size() 的类型
    int num = 42;
    float f = 3.14f;
    
    std::cout << "Testing int: ";
    printSize(num);
    
    std::cout << "Testing float: ";
    printSize(f);
    
    // 测试自定义类
    class CustomContainer {
    public:
        size_t size() const { return 10; }
    };
    
    CustomContainer custom;
    std::cout << "Testing CustomContainer: ";
    printSize(custom);
    
    return 0;
}