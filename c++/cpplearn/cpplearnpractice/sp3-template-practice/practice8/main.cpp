#include "FixedStack.h"
#include <string>

int main() {
    std::cout << "--- 测试 FixedStack<int, 5> ---" << std::endl;
    try {
        FixedStack<int, 5> intStack;

        // Push some elements
        for (int i = 10; i <= 30; i += 5) {
            intStack.push(i);
            std::cout << "Pushed: " << i << ", Top: " << intStack.top() << ", Size: " << intStack.size() << std::endl;
        }

        // Test Pop and Top
        std::cout << "\nPopping elements:" << std::endl;
        while (!intStack.empty()) {
            std::cout << "Top element: " << intStack.top() << std::endl;
            intStack.pop();
        }
        
        // intStack.pop(); // 尝试在空栈上 pop，会抛出异常
        // intStack.push(100); 
        // intStack.push(200); 
        // intStack.push(300); 
        // intStack.push(400); 
        // intStack.push(500); 
        // intStack.push(600); // 尝试 push 超过大小限制，会抛出异常

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 测试 FixedStack<std::string, 3> ---" << std::endl;
    try {
        FixedStack<std::string, 3> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("C++");
        
        // strStack.push("OverFlow"); // 尝试 push 超过大小限制，会抛出异常

        std::cout << "Top string: " << strStack.top() << std::endl;
        strStack.pop();
        std::cout << "New top string: " << strStack.top() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}