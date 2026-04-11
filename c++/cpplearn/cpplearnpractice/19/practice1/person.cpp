#include "person.h"

Person::Person():_name("npc"),_age(18){}

Person::Person(const std::string& name,int age):
    _name(name),_age(age){
        
}

void Person::displayInfo(){
    std::cout << "name is:" << _name << std::endl
    << "age is:" << _age << std::endl;
}

Student::Student():Person(), _StudentId("0000"){}  

Student::Student(const std::string& name,int age,const std::string& StudentId)
    :Person(name,age),_StudentId(StudentId){}

void Student::displayInfo(){
    Person::displayInfo();
    std::cout<< "Studentid is:" << _StudentId << std::endl;
}