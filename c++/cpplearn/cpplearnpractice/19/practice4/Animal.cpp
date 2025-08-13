#include "Animal.h"


void Animal::makeSound() const{}

void Dog::makeSound() const{
    std::cout << "Woof!" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow!" << std::endl;
}