#include "Template.h"

template<>
void printValue<int *>(int* const& obj){
    std::cout << "Int* printValue: " << *obj << std::endl;
};


