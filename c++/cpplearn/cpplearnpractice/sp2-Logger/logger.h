#pragma once


#include <iostream>
#include <string>
#include <type_traits>

template <typename T, typename Enable = void>
class Logger{
public:
    static void log(const T& msg){
        std::cout << "General Logging : " << msg << std::endl;
    }
};

//指针类型
template<typename T>
class Logger<T, typename std::enable_if<std::is_pointer<T>::value>::type>{
public:
    static void log(const T& msg){
        if(msg){
            std::cout << "Pointer Logging : " << *msg << std::endl;
        }
        else{
            std::cout << "Pointer Logging : nullptr" << std::endl;
        }
    }
};

//全特化
template<>
class Logger<std::string>{
public:
    static void log(const std::string& msg){
        std::cout << "String Logging : " << msg << std::endl;
    } 
};


//函数模版，用于递归调用Logger::log
template<typename T>
void logOne(const T& value){
    Logger<T>::log(value);
}


//模版折叠
template<typename... Args>
void logAll(const Args&... args){
    (logOne(args),...);
}



template<int N>
struct Factorial{
    static constexpr int value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<0>{
    static constexpr int value = 1;
};


template <int N>
struct Fibonacci{
    static constexpr long long value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<1>{
    static constexpr long long value = 1;
};

template<>
struct Fibonacci<0>{
    static constexpr long long value = 0;
};


template<typename T, typename = void>
struct is_addable : std::false_type{
};

template<typename T>
struct is_addable<T, decltype(void(std::declval<T>() + std::declval<T>()))> : std::true_type{
};

template<int... Ns>
struct Sum;

template<>
struct Sum<>{
    static constexpr int value = 0;
};

template<int N, int... Ns>
struct Sum<N, Ns...>{
    static constexpr int value = N + Sum<Ns...>::value;
};



//列表类型访问
template<typename... Ts>
struct TypeList{

};

template<typename List, std::size_t N>
struct TypeAt;


template<typename Head, typename... Tail>
struct TypeAt<TypeList<Head, Tail...>, 0>{
    using type = Head;
};

template<typename Head, typename... Tail, std::size_t N>
struct TypeAt<TypeList<Head, Tail...>, N>{
    using type = typename TypeAt<TypeList<Tail...>, N - 1>::type;
};
 