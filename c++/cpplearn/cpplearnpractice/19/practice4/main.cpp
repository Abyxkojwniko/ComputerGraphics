#include "Animal.h"

int main(){
    Dog d1;
    Animal* dog=&d1;
    dog->makeSound();
    Cat c1;
    Animal* cat=&c1;
    cat->makeSound();
    return 0;
}