#pragma once

#include <iostream>

template<typename T>
void swapValues(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}