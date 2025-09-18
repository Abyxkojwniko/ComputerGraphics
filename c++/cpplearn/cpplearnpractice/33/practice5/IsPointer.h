#pragma once

#include <iostream>
#include <string>
#include <type_traits>


template <typename T>
struct IsPointer{
    static constexpr bool value = false;
};

template <typename T>
struct IsPointer<T*>{
    static constexpr bool value = true;
};