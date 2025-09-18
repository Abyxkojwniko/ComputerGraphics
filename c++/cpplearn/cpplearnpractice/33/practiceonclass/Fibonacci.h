#pragma once

#include <iostream>


template <int N>
struct Fibonacci{
    inline static const int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0>{
    inline static const int value = 0;
};

template<>
struct Fibonacci<1>{
    inline static const int value = 1;
};