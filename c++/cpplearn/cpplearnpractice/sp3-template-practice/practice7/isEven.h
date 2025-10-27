#pragma once

#include <iostream>
#include <type_traits>


template <typename T>
concept Integral = std::integral<T>;


template <Integral T>
bool isEven(const T& value){
    return value % 2 == 0;
}