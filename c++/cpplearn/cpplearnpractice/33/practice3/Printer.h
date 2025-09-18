#pragma once

#include <iostream>


template <typename T>
class Printer{
public:
    static void print(const T& value){
        std::cout << "General Printer: " << value << std::endl;
    }
};

template <>
class Printer<bool>{
public:
    static void print(bool value){
        std::cout << "Boolean Printer:" << (value ? "true" : "false") << std::endl;
    }
};
