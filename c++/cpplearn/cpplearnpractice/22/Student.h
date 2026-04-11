#pragma once

#include <string>
#include <memory>
#include <iostream>
class Student{
public:
    Student() = default;
    Student(const std::string& name,int age);
    ~Student();
    int GetAge();
    std::string GetName();
    friend std::ostream& operator<<(std::ostream& out, Student& stu);
    std::string _name;
    int _age;
    void print();
private:    

};



class B;
class A{
public:
    std::shared_ptr<B> ptrB;
    A(){
        std::cout << "A()" << std::endl;
    }

    ~A(){
        std::cout << "~A()" << std::endl;
    }
};

class B{
public:
    std::weak_ptr<A> ptrA;
    B(){
        std::cout << "B()" << std::endl;
    }

    ~B(){
        std::cout << "~B()" << std::endl;
    }
};