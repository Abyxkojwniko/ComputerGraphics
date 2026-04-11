#pragma once
#include<iostream>
#include<string>

class Person{
public:
    Person();
    Person(const std::string& name,int age);

    virtual void displayInfo();
    virtual ~Person()=default;
private:
    std::string _name;
    int _age;
};


class Student:public Person{
public:
    Student();
    Student(const std::string& name,int age,const std::string& StudentId);
    void displayInfo() override;
private:
    std::string _StudentId;
};