

#include "logger.h"

int main(){
    Logger<std::string> test1;
    test1.log("hello sp2");
    int a = 10;
    Logger<int>::log(a);
    int* ptr = &a;
    Logger<int*>::log(ptr);
    std::string str = "HELLO WORLD";
    Logger<std::string>::log(str);
    std::cout << "Logging all parameters: " << std::endl;
    double* pNull = nullptr;
    logAll(a, ptr, str, pNull);

    std::cout << "Fctorial(5) = " << Factorial<5>::value << std::endl;
    std::cout << "Fctorial(0) = " << Factorial<0>::value << std::endl;

    std::cout << "Fctorial(5) = " << &Factorial<5>::value << std::endl;
    std::cout << "Fctorial(0) = " << &Factorial<0>::value << std::endl;

    std::cout << "Fabonacci(10) = " << Fibonacci<10>::value << std::endl;
    static_assert(is_addable<int>::value, "int should be addable");
    static_assert(!is_addable<void*>::value, "void* should not be addable");


    int result = Sum<1,2,3,10,5>::value;
    std::cout << "Sum<1,2,3,10,5> = " << result << std::endl;

    using list = TypeList<int, double, char>;
    using third_type = TypeAt<list, 2>::type;
    std::cout << "TypeAt<list, 2> = " << typeid(third_type).name() << std::endl;
    return 0;
}