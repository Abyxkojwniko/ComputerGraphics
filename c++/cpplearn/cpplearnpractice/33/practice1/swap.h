#pragma once

#include <iostream>

template <typename T>
void swapvalue(T& u, T& v){
    T temp = u;
    u = v;
    v = temp;
}