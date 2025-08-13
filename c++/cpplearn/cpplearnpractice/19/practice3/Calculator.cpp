#include "Calculator.h"

int Calculator::add(int a,int b){
    std::cout << a+b <<std::endl;
    return a+b;
}

double Calculator::add(double a,double b){
    std::cout << a+b <<std::endl;
    return a+b;
}

int AdvancedCalculator::add(int a,int b,int c){
    std::cout << a+b+c <<std::endl;
    return a+b+c;
}

int AdvancedCalculator::callCalint(int a,int b){
    return Calculator::add(a,b);
}

double AdvancedCalculator::callCaldouble(double a,double b){
    return Calculator::add(a,b);
}