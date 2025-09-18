#pragma once

#include <iostream>
#include <string>

template <typename T>
class Triple{
public:
    T a, b, c;
    Triple(T& u,T& v,T& q):a(u), b(v), c(q){};
    void print(){
        std::cout << a << ", " << b << ", " << c << std::endl;
    }
};