#pragma once
#include <iostream>



template<typename T>
T maxvalue(T a, T b){
    return a > b ? a : b;
}


template<typename T, typename U>
class Pair{
public:
    T first;
    U second;
    Pair(T a, U b):first(a), second(b){};
    void print() const{
        std::cout << "Pair:(" << first <<", " << second << ")" << std::endl;
    }
};


template<typename T, std::size_t N>
class FixedArray{
public:
    T arr[N];
    T& operator [](std::size_t index){
        return arr[index];
    }
    void print() const{
        for(std::size_t i = 0; i < N; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};


template<template<typename, typename> class Container, typename T>
class ContainerPrinter{
public:
    void print(const Container<T, std::allocator<T>>& container){
        for(const auto& item : container){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};