#pragma once

#include <iostream>

template <typename T>
class Printer{
public:
    void print(const T& value){
        std::cout << "General Print: " << value << std::endl;
    }
};


template <>
class Printer<bool>{
public:
    void print(const bool& value){
        std::cout << "Boolen Print: " << (value ? "true" : "false") << std::endl;
    }
};