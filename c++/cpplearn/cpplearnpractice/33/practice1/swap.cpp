#include "swap.h" 

int main(){
    int a = 10, b = 5;
    swapvalue<int>(a, b);
    std::cout << "A is: " << a <<", " << "B is: " << b << std::endl;
}