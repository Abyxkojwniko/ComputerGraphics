#include <iostream>
#include <type_traits>


template <typename T>
void deduce_type(T&&){
    std::cout << std::boolalpha;
    std::cout << "Is T an lvalue reference: " << std::is_lvalue_reference<T>::value << std::endl;
    std::cout << "Is T an rvalue reference: " << std::is_rvalue_reference<T&&>::value << std::endl;
}

template <typename T>
void display_type(T&& param){
    std::cout << "Is T an lvalue reference: " << std::is_lvalue_reference<T>::value << std::endl;
    std::cout << "Is param an lvalue reference: " << std::is_lvalue_reference<decltype(param)>::value << std::endl;
    std::cout << "T traits normal type is int: " << 
        std::is_integral<typename std::remove_reference<T>::type>::value << std::endl;
    //param = 100;
}

int main(){
    int da = 5;
    const int& ref = da;
    deduce_type(da);
    std::cout << "*************************" << std::endl;
    deduce_type(10);
    std::cout << "*************************" << std::endl;
    deduce_type(ref);
    std::cout << "*************************" << std::endl;
    deduce_type(std::move(ref));
    std::cout << "*************************" << std::endl;
    display_type(10);
    std::cout << "*************************" << std::endl;
    display_type(da);
    std::cout << "*************************" << std::endl;
    display_type(ref);
    display_type(std::move(da));
    return 0;
}