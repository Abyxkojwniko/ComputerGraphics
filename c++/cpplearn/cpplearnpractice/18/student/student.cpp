#include "student.h"
#include<iostream>

int Student::_money=100;

std::string Student::GetName() const{
    return _name;
}

int Student::GetAge() const{
    return _age;
}

std::string Student::GetNum() const{
    return _num;
}

void Student::ChangeName(const std::string& name){
    _name=name;
}

void Student::ChangeAge(const int age){
    _age=age;
}

void Student::ChangeNum(const std::string& num){
    _num=num;
}

Student::Student():_age(0),_name("npc"),_num("0"){
    _data=new int();
}

// Student::Student(const std::string& name,int age,const std::string& num){
//     _name=name;
//     _age=age;
//     _num=num;
// }

Student::Student(const std::string& name,int age,const std::string& num)
                :_name(name),_age(age),_num(num)
{
    _data=new int();
}


int Student::GetMoney() const{
    std::cout<<"this value is"<< this<< std::endl;
    return _money;
}


void Student::ChangeMoney(const int& cost){
    _money-=cost;
}

Student::Student(const Student& student):
                _name(student._name),_age(student._age),_num(student._num)
{
    _data=new int();
    *_data=*(student._data);
    //在拷贝构造中，深拷贝是非常必要的，因为析构函数会处理之前的空间
    //浅拷贝只修改指针，这样指向的空间是被删除了
    //不仅指向会有问题，同时在析构函数中会被删除两次，这样也会出现问题

}

Student::Student(Student&& student):
        _name(std::move(student._name)),_age(std::move(student._age)),_num(std::move(student._num)),_thread(std::move(student._thread))
{
    _data=new int();
    *_data=std::move(*(student._data));//深拷贝
    //_data=student._data 浅拷贝，移动的过程中转移值但是不转移指针
} 

Student::~Student(){
    if(_thread.joinable())  _thread.join();
    delete _data;
    std::cout<<"successful"<<std::endl;
}
//要判断是否是自拷贝
Student &Student::operator=(const Student& student){
    if(&student==this) return *this;
    this->_name=student._name;
    this->_age=student._age;
    this->_num=student._num;
    (*_data)=*(student._data);
    return *this;
}
Student &Student::operator=(Student &&student){
    if(this==&student) return *this;
    this->_name=std::move(student._name);
    this->_age=student._age;
    this->_num=std::move(student._num);
    *(this->_data)=std::move(*(student._data));
    return *this;
}
void Student::TestStatic(){
    std::cout<<"this money is"<<_money<<std::endl;
}


void ChangeAge(Student &student,int age){
    student._age=age;
}

void StudentFriend::ChangeAge(Student &student,int age){
    student._age=age;
}

std::ostream& operator << (std::ostream &os, const Student &student){
    os << "student name is "<< student._name <<" age is"<<student._age
    << "num is "<<student._num<<std::endl;
    return os;
}