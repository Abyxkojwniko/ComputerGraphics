#pragma once

#include <concepts>
#include <type_traits>
#include <iostream>

template <typename T>
concept Integral = std::is_integral_v<T>;


template <Integral T>
bool isEven(T value){
    return value % 2 == 0;
}