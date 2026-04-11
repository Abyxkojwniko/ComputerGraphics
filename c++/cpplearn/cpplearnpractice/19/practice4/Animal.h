#pragma once
#include<iostream>

class Animal{
public:
    virtual void makeSound() const;
};


class Dog:public Animal{
public:
    void makeSound() const;
};

class Cat:public Animal{
public:
    void makeSound() const;
};