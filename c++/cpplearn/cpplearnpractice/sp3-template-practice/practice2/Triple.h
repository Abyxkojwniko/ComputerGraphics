#pragma once

#include <iostream>

template <typename T>
class Triple{
public:
    Triple(const T& u,const T& v,const T& q) : a(u), b(v), c(q){};
    void print(){
        std::cout << a << " " << b << " " << c << std::endl;
    }
    void getA() const{
        std::cout << a << std::endl;
    }
    void getB() const{
        std::cout << b << std::endl;
    }
    void getC() const{
        std::cout << c << std::endl;
    }
private:
    T a, b, c;
};