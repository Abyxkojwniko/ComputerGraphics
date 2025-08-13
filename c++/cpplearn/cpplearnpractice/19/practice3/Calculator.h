#pragma once
#include<iostream>

class Calculator{
public:
    virtual int add(int a,int b);
    double add(double a,double b);
};

class AdvancedCalculator:public Calculator{
public:
    int add(int a,int b,int c);
    int callCalint(int a,int b);
    double callCaldouble(double a,double b);
};