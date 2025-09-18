#include "FixedStack.h"

int main() {
    // 测试整数栈
    FixedStack<int, 5> intStack;
    
    std::cout << "Testing FixedStack<int, 5>:\n";
    try {
        for (int i = 1; i <= 5; ++i) {
            intStack.push(i * 10);
            std::cout << "Pushed: " << i * 10 
                      << " | Size: " << intStack.size() << "\n";
        }
        
        // 测试栈满时的行为
        std::cout << "Attempting to push 60 (should fail): ";
        intStack.push(60); // 这里会抛出异常
    } catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    // 弹出并显示元素
    while (!intStack.empty()) {
        std::cout << "Top: " << intStack.top() 
                  << " | Size: " << intStack.size() << "\n";
        intStack.pop();
    }
    
    // 测试空栈行为
    std::cout << "Attempting to pop empty stack (should fail): ";
    try {
        intStack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    // 测试字符串栈
    FixedStack<std::string, 3> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");
    
    std::cout << "\nTesting FixedStack<std::string, 3>:\n";
    while (!strStack.empty()) {
        std::cout << "Top: " << strStack.top() << "\n";
        strStack.pop();
    }
    
    return 0;
}