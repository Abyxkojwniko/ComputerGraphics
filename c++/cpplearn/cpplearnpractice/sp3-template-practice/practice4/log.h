#pragma once
#include <iostream>

template<typename... Args>
void logMessage(const Args&... args){
    ((std::cout << args << " "),...);
    std::cout << std::endl;
};