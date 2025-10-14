#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

template <typename T>
T maxValue(T a, T b){
    return a > b ? a : b;
}


template <typename T, typename U>
class Pair{
public:
    T first;
    U second;
    Pair(T a, U b) : first(a), second(b){};
    void print() const{
        std::cout << "Pair: " << first << ", " << "second: " << second << std::endl;
    }
private:

};

template <typename T, typename U>
class Pair<T, U*>{
public:
    T first;
    U* second;
    Pair(T a, U* b) : first(a), second(b){};
    void print() const{
        std::cout << "Pair : " << first << ", " << *second << std::endl;
    }
};

template <typename T, std::size_t N>
class FixedArray{
public:
    T data[N];
    T& operator[](std::size_t index){
        return data[index];
    }
    void print() const{
        for(std::size_t i = 0; i < N; ++i){
            std::cout << data[i] <<  " ";
        }
        std::cout << std::endl;
    }
private:

};


template<template<typename, typename > class Container, typename T>
class ContinerPrinter{
public: 
    void print(const Container<T, std::allocator<T>> & container){
        for(const auto& elem : container){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};


template<typename T>
class Printer{
public:
    void print(const T& obj){
        std::cout << "General Printer : " << obj << std::endl;
    }
};

template<>
class Printer<std::string>{
public:
    void print(const std::string obj){
        std::cout << "String Printer : " << obj << std::endl;
    }
};




template<typename T>
void printValue(const T& obj){
    std::cout << "General printValue: " << obj << std::endl;
}


template<>
inline void printValue<std::string>(const std::string& obj){
    std::cout << "String printValue : " << obj << std::endl;
}

template<>
inline void printValue<int *>(int* const& p){
    std::cout << "INT* printValue : " << *p << std::endl;
}



//可变参数模版

inline void printAll(){
    std::cout << std::endl;
}

template<typename T, typename... Args>
inline void printAll(const T& first,const Args&... args){
    std::cout << first << " ";
    printAll(args...);
}

template<typename... Args>
void coutAll(const Args&... args){
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

template <typename... Args>
auto sumAll(Args... args) ->decltype((args + ...)){
    return (args + ...);
}