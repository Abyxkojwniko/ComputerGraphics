#pragma once
#include<iostream>

class Vehicle{
public:
    Vehicle();
    ~Vehicle();
};

class Car:public Vehicle{
public:
    Car();
    ~Car();
};