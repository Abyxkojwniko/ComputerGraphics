#include "swap.h"

int main(){
    int a, b;
    a =10;
    b = 5;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swapValues(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}