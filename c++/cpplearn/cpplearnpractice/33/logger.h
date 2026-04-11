#pragma once

#include <iostream>
#include <string>
#include <type_traits>

//通用
template <typename T, typename Enable = void>
class Logger{
public:
    static void log(const T& value){
        std::cout << "General Logger: " << value << std::endl;
    }
};


//类，模版偏特化，当T是指针类型
template <typename T>
class Logger<T, typename std::enable_if<std::is_pointer<T>::value>::type>{
public:
    static void log(const T& value){
        if(value){
            std::cout << "Pointer Logger: " << *value << std::endl;
        }
        else{
            std::cout << "Pointer Logger: nullptr" << std::endl;
        }
    }
};


//全特化
template <>
class Logger<std::string>{
public:
    static void log(const std::string& value){
        std::cout << "String Logger: " << value << std::endl;
    }
};


//函数模版，用于递归调用Logger::log
template<typename T>
void logOne(const T& value){
    Logger<T>::log(value);
};

//使用模版折叠实现变参数打印
template <typename ...Args>
void logAll(const Args&... args){
    (logOne(args),...);
};

template <int N>
struct Factorial{
    inline static const int value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<0>{
    inline static const int value = 1;
};

template <typename T, typename = void>
struct is_addable : std::false_type{

};

template <typename T>
struct  is_addable<T, decltype(void(std::declval<T>() + std::declval<T>()))> : std::true_type{

};


template <int... Ns>
struct Sum;

template <>
struct Sum<>{
    inline static const int value = 0;
};

template <int N, int... Ns>
struct Sum <N, Ns...>{
    static const int value = N + Sum<Ns...>::value;
};



//定义类型列表

template <typename... Ts>
struct TypeList{

};

template <typename List, std::size_t N>
struct TypeAt;

template <typename Head, typename... Tail>
struct TypeAt<TypeList<Head, Tail...>, 0>{
    using type = Head;
};

template <typename Head, typename... Tail, std::size_t N>
struct TypeAt<TypeList<Head, Tail...>, N>{
    using type = typename TypeAt<TypeList<Tail...>, N - 1>::type;

};