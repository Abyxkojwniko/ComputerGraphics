#pragma once

#include<string>


class Student{
public:
    Student() = default;
    Student(const std::string& name,int age);
    int GetAge();
    std::string GetName();
private:    
    std::string _name;
    int _age;
};