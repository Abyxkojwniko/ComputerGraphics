#pragma once
#include<iostream>

class Shape{
public:
    virtual void draw();
};


class Circle:public Shape{
public:
    void draw();
};


class Rectangle:public Shape{
public:
    void draw();
};