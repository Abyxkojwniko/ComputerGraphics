#include <iostream>
#include <utility>

void func(int&x){
    std::cout << "func(int&)" << std::endl;
}

void func(int&& x){
    std::cout << "func(int&&)" << std::endl;
}

template<typename T>
void check_referenc(T&& x){
    std::cout << std::boolalpha;
    std::cout << "T is lvalue reference: " << std::is_lvalue_reference<T>::value << std::endl;
    std::cout << "T is rvalue reference: " << std::is_rvalue_reference<T>::value << std::endl;
    std::cout << "T is rvalue : " << std::is_rvalue_reference<T&&> ::value << std::endl;
    std::cout << "x is lvalue reference: " << std::is_lvalue_reference<decltype(x)>::value << std::endl;
    std::cout << "x is rvalue reference: " << std::is_rvalue_reference<decltype(x)>::value << std::endl;
}

void process(int&x){
    std::cout << "process(int&)" << std::endl;
    x = 100;
}

void process(int&& x){
    std::cout << "process(int&&)" << std::endl;
}

template<typename T>
void wrapper(T&& arg){
    process(std::forward<T>(arg));
    //process(arg);
}

template<typename T>
void deduce_type(T&&) {
    std::cout << std::boolalpha;
    std::cout << "Is T an lvalue reference: " << std::is_lvalue_reference<T>::value << std::endl;
    std::cout << "Is T an rvalue reference: " << std::is_rvalue_reference<T&&>::value << std::endl;
}

template<typename T>
void display_type(T&& param){
    std::cout << "T is lvalue reference: " << std::is_lvalue_reference<T>::value << std::endl;
    std::cout << "param is lvalue reference: " << std::is_lvalue_reference<decltype(param)>::value << std::endl;
    std::cout << "T traits normal type is int : " <<
    std::is_integral<typename std::remove_reference<T>::type>::value << std::endl;
}

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2){
    f(t2,t1);
}



void ftemp(int v1, int &v2){
    std::cout << v1 << " " << ++v2 << std::endl;
}

void use_ftemp(){
    int i = 100;
    int j = 99;
    flip1(ftemp, j, 42);
    std::cout << "j: " << j << std::endl;
    std::cout << "i: " << i << std::endl;
}

//void gtemp(int && i, int &j){
//    std::cout << i << " " << ++j << std::endl;
//}
template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2){
    f(t2,t1);
}

//void use_temp3(){
//    int i = 100;
//    int j = 99;
//    flip2(gtemp, i, j);
//    std::cout << "j: " << j << std::endl;
//    std::cout << "i: " << i << std::endl;
//}


void use_ftemp2(){
    int i = 100;
    int j = 99;
    flip2(ftemp, 100, 42);
    std::cout << "j: " << j << std::endl;
    std::cout << "i: " << i << std::endl;
}


int main() {
    int a = 10;
    int &b = a;
    int && c = 20;
    int d = a + 5;
    std::string s1 = "Hello";
    std::string s2 = std::string("World");
    std::cout << "a: " << a << ", d: " << d << ", s1: " << s1 << ", s2: " << s2 << std::endl;
    std::cout << std::boolalpha;
    std::cout << "a 是左值引用: " << std::is_lvalue_reference<decltype(a)>::value << std::endl;
    std::cout << "b 是左值引用: " << std::is_lvalue_reference<decltype(b)>::value << std::endl;
    // 使用 decltype((a)) 获取 a 的类型，包括引用
    // `(a)` 是一个左值表达式，所以 decltype((a)) 是 `int&`
    std::cout << "a 是左值: " << std::is_lvalue_reference< decltype((a))>::value << std::endl;

    func(a);
    func(10);
    check_referenc(a);
    check_referenc(20);
    //c 是int&& 类型，但是c是左值
    check_referenc(c);
    check_referenc(std::move(c));
    check_referenc(std::forward<int&&>(c));

    wrapper(a);
    wrapper(10);

    int da = 5;
    const int & ref = da;
    deduce_type(da);
    std::cout << "******************" << std::endl;
    deduce_type(10);
    std::cout << "?????????????????????" << std::endl;
    deduce_type(ref);
    std::cout << "++++++++++++++++++++" << std::endl;
    deduce_type(std::move(da));

    std::cout << "??????????????" << std::endl;
    display_type(da);
    display_type(20);

    std::cout << "++++++++++ " << std::endl;
    display_type(ref);
    display_type(std::move(da));

//    use_temp3();
    return 0;
}
