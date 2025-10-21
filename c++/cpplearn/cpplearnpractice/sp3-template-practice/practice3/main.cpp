#include "printer.h"

int main(){
    Printer<int> T;
    T.print(10);
    Printer<bool> F;
    F.print(true);

}