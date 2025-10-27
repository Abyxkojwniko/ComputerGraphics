#include "FixedStack.h"
#include <string>

int main() {
    std::cout << "--- ���� FixedStack<int, 5> ---" << std::endl;
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
        
        // intStack.pop(); // �����ڿ�ջ�� pop�����׳��쳣
        // intStack.push(100); 
        // intStack.push(200); 
        // intStack.push(300); 
        // intStack.push(400); 
        // intStack.push(500); 
        // intStack.push(600); // ���� push ������С���ƣ����׳��쳣

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- ���� FixedStack<std::string, 3> ---" << std::endl;
    try {
        FixedStack<std::string, 3> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("C++");
        
        // strStack.push("OverFlow"); // ���� push ������С���ƣ����׳��쳣

        std::cout << "Top string: " << strStack.top() << std::endl;
        strStack.pop();
        std::cout << "New top string: " << strStack.top() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}