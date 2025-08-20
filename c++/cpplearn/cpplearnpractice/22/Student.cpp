#include "Student.h"

Student::Student(const std::string& name, int age):
    _name(name), _age(age){}


int Student::GetAge(){
    return _age;
}


std::string Student::GetName(){
    return _name;
}

Student::~Student(){
    std::cout << "student destroy" << std::endl;
}

std::ostream& operator<<(std::ostream& out, Student& stu){
    out << "The name is:" << stu._name << ", the age is:" << stu._age << std::endl;
    return out;
}

void Student::print(){
    std::cout << this->_name << std::endl;
}