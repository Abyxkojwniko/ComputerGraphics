#pragma once

#include <iostream>
#include <type_traits>
#include <vector>
#include <list> 
template <typename T>
class has_size {
private:
    template <typename U>
    static auto test(int) -> decltype(std::declval<U>().size(), std::true_type{});
    
    template <typename U>
    static auto test(...) -> std::false_type;
    
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

// 简化函数重载设计
template <typename T>
void printSize(const T& container) {
    if constexpr (has_size<T>::value) {
        std::cout << "Container size: " << container.size() << std::endl;
    } else {
        std::cout << "This type has no size() member function" << std::endl;
    }
}