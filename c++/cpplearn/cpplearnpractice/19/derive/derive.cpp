#include "derive.h"

void Base::display(){
    std::cout<<"Base Virtual Func"<<std::endl;
    std::cout<<"Private Num"<<std::endl;
    std::cout<<"Protected Num"<<protectedNum<<std::endl;
}