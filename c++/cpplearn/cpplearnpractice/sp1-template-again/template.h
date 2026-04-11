#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <type_traits>
#include <concepts>
#include <vector>

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


//sfinae使用举例
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_type(T value){
    std::cout << "Integral type" << std::endl;
}


template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print_type(T value){
    std::cout << "Floating point type" << std::endl;
}

template<typename T>
typename std::enable_if<std::is_same<T, const char*>::value ||
    std::is_same<T, char*>::value, void>::type
print_type(T value){
    std::cout << "Cstyle string: " << value << std::endl;
}

template<typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
print_type(T value){
    std::cout << "String: " << std::endl;
}

template<typename T>
typename std::enable_if<std::is_pointer<T>::value &&
    !std::is_same<T, const char*>::value &&
    !std::is_same<T, char*>::value>::type
print_type(T value){
    std::cout << "Pointer type" << std::endl;
}

template<typename T>
typename std::enable_if<
    !std::is_integral<T>::value &&
    !std::is_floating_point<T>::value &&
    !std::is_same<T, const char*>::value &&
    !std::is_same<T, char*>::value &&
    !std::is_same<T, std::string>::value &&
    !(std::is_pointer<T>::value &&
    !std::is_same<T, const char*>::value &&
    !std::is_same<T, char*>::value), void
    >::type 
print_type(T value){
    std::cout << "Other type" << std::endl;
}

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template<typename T>
concept CString = std::is_same_v<T, const char*> || std::is_same_v<T, char*>;

template<typename T>
concept StdString = std::is_same_v<T, std::string>;

template<typename T>
concept Pointer = std::is_pointer_v<T> && !(std::is_same_v<T, const char*> || std::is_same_v<T, char*>);

void cout_type(Integral auto value){
    std::cout << "Integral type" << std::endl;
}

void cout_type(FloatingPoint auto value){
    std::cout << "Floating type" << std::endl;
}

void cout_type(CString auto value){
    std::cout << "CString type" << std::endl;
}

void cout_type(StdString auto value){
    std::cout << "String type" << std::endl;
}

void cout_type(Pointer auto value){
    std::cout << "Pointer type" << std::endl;
}

template<typename T>
requires (!Integral<T> && !FloatingPoint<T> && !CString<T> && !StdString<T> && !Pointer<T>)
void cout_type(T value){
    std::cout << "Other Type" << std::endl;
}


template<typename T>
class has_foo{
private:
    typedef char yes[1];
    typedef char no[2];
    template<typename U, void(U::*)()>
    struct SFINAE{};
    template<typename U>
    static yes& test(SFINAE<U, &U::foo>*);
    template <typename U>
    static no& test(...);
public:
    static constexpr bool value = sizeof(test<T>(0)) == sizeof(yes);

};


template <typename T>
typename std::enable_if<has_foo<T>::value, void>::type
call_foo(T& obj){
    obj.foo();
    std::cout << "foo() called" << std::endl;
}

class WithFoo{
public:
    void foo(){
        std::cout << "WithFoo::foo()" << std::endl;
    }
};

class WithOutFoo{};


template <typename T, typename Enable = void>
struct has_non_void_value_type : std::false_type{};

//当T有成员类型的时候判断为true，也就是T有具体的成员类型
template <typename T>
struct has_non_void_value_type<T, std::enable_if_t<!std::is_void_v<typename T::value_type>>>:std::true_type{};

template<typename T, bool HasValueType = has_non_void_value_type<T>::value>
struct TypePrinter;

// 特化：当 T 有成员类型 `value_type`
template <typename T>
struct TypePrinter<T, true> {
    void foo(){
        std::cout << "WithFoo::foo()" << std::endl;
    }
    static void print() {
        std::cout << "T has a member type 'value_type'." << std::endl;
    }
};

template<typename T>
struct TypePrinter<T, false>{
    static void print(){
        std::cout << "T does not have a member type value_type" << std::endl;
    }
};

struct WithValueType{
    using value_type = int;
};

struct WithoutValueType{};


//Concept版本
// struct WithVoidValueType {
//     using value_type = void; // 用于测试非 void 约束
// };

// // ----------------------------------------------------
// // 2. Concept 定义 (替代 has_non_void_value_type 结构体)
// // ----------------------------------------------------
// template <typename T>
// concept HasNonVoidValueType = requires {
//     // 检查 T 是否有一个名为 value_type 的成员类型
//     typename T::value_type;
    
//     // 检查这个 value_type 是否不是 void
//     requires !std::is_void_v<typename T::value_type>;
// };

// // ----------------------------------------------------
// // 3. TypePrinter 结构 (使用 Concept 进行约束分派)
// // ----------------------------------------------------

// // A. TypePrinter 的主要定义（作为不满足约束时的默认回退）
// // 对应原代码中的 TypePrinter<T, false>
// template <typename T>
// struct TypePrinter {
//     static void print() {
//         std::cout << "T does not have a member type value_type (Concept version)" << std::endl;
//     }
//     // 注意：此版本不提供 foo()
// };

// // B. 特化/约束版本 (只适用于满足 Concept 的类型)
// // 对应原代码中的 TypePrinter<T, true>
// template <HasNonVoidValueType T>
// struct TypePrinter<T> {
//     void foo() {
//         std::cout << "WithFoo::foo() (Concept version)" << std::endl;
//     }
//     static void print() {
//         std::cout << "T has a member type 'value_type'. (Concept version)" << std::endl;
//     }
// };



