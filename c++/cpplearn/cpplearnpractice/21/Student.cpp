#include "Student.h"

Student::Student(const std::string& name, int age):
    _name(name), _age(age){}


int Student::GetAge(){
    return _age;
}


std::string Student::GetName(){
    return _name;
}
