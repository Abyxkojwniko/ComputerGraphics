#include "Printer.h"

int main(){
    Printer<int>::print(42);
    Printer<bool>::print(true);
    Printer<bool>::print(false);
}