#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

template <typename T>
class Printer{
public:
    void print(const T& obj){
        std::cout << "General Printer: " << obj << std::endl;
    }
};

template <>
class Printer<int *>{
public:
    void print(int* obj){
        std::cout << "int* Printer: " << *obj << std::endl;
    }
};


template <typename T, typename U>
class Pair{
public:
    T first;
    U second;
    Pair(T a, U b):first(a), second(b){};
    void print() const{
        std::cout << "Pair: " << first << ", " << second << std::endl;
    }
};


template <typename T, typename U>
class Pair<T, U*>{
public:
    T first;
    U* second;
    Pair(T a, U* b):first(a), second(b){};
    void print() const{
        std::cout << "Pair: " << first << ", " << *second << std::endl;
    }
};

template<typename T>
void printValue(const T& obj){
    std::cout << "General printValue : " << obj << std::endl;
};

template<>
inline void printValue<std::string>(const std::string& obj){
    std::cout << "String printValue: " << obj << std::endl;
};

template<>
void printValue<int *>(int* const& obj);

inline void printAll(){
    std::cout << "Print All" << std::endl;
};
template<typename T, typename... Args>
void printAll(const T& first, const Args&... args){
    std::cout << first << " ";
    printAll(args...);
}
;

template<typename... Args>
void countAll(const Args&... args){
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
};


template <typename... Args>
auto sum(Args... args) -> decltype((args + ...)){
    return (args + ...);
};

template <typename... Args>
bool allNot(const Args&... args){
    return (!args && ...);
};

template <typename... Args>
auto sumLeftFold(const Args&... args)->decltype((args + ...)){
    return (args + ...);
};

template <typename... Args>
auto sumrightFold(const Args&... args)->decltype((... + args)){
    return (... + args);
};

template <typename... Args>
auto multiRightFlod(const Args&... args)->decltype((args * ...)){
    return (... * args);
};

template <typename... Args>
void printFoldAll(const Args&... args){
    (std::cout << ... << args) << std::endl;
    (std::cout << (... << args)) << std::endl;
};


struct MyPoint{
    int x, y;
    MyPoint(int a, int b):x(a), y(b){};
    MyPoint operator + (const MyPoint& other) const{
        return MyPoint(x + other.x, y + other.y);
    };

};
template <typename... Args>
auto sumPoints(const Args&... args)->decltype((args + ...)){
    return (args + ...);
};