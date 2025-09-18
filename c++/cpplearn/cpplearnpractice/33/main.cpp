#include "logger.h"

int main(){
    int a = 10;
    Logger<int>::log(a);
    int* ptra = &a;
    Logger<int*>::log(ptra);
    std::string s1 = "Hello CPP";
    Logger<std::string>::log(s1);
    double* pNull = nullptr;
    logAll(a, ptra, pNull, s1);

    std::cout << "5! = " << Factorial<5>::value << std::endl;
    std::cout << "0! = " << Factorial<0>::value << std::endl;
    std::cout << "&5! = " << &Factorial<5>::value << std::endl;
    std::cout << "&0! = " << &Factorial<0>::value << std::endl;

    static_assert(is_addable<int>::value, "int should be addable");
    static_assert(!is_addable<void*>::value, "void* should be addable");

    int result = Sum<1, 2, 3, 5, 6>::value;
    std::cout << result << std::endl;

    using list = TypeList<int, double, char>;
    using thrid_type = TypeAt<list, 2>::type;
    std::cout << "TypeAt<list, 2> = " << typeid(thrid_type).name() << std::endl;
    return 0;
}