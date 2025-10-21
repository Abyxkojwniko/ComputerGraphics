#pragma once

#include <iostream>
#include <type_traits>
#include <concepts>

template <typename T>
struct IsPointer{
    static constexpr bool value = false;
};


template <typename T>
struct IsPointer<T*>{
public:
    static constexpr bool value = true;
};
