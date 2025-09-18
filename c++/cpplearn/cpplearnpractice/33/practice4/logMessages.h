#pragma once

#include <iostream>
#include <string>
#include <type_traits>

void logMessages(){
    std::cout << std::endl;
}

template <typename T, typename... Args>
void logMessages(T first, Args... args){
    std::cout << first;
    if(sizeof...(args) > 0){
        std::cout << " ";
        logMessages(args...);
    }
    else{
        std::cout << std::endl;
    }
}