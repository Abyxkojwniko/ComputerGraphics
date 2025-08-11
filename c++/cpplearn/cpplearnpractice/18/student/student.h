#pragma once
#include<iostream>
#include<string>
#include<thread>
class StudentFriend;
class Student{
public:
    Student();
    Student(const std::string& name,int age,const std::string& num);
    Student(const Student& student);//如果不使用引用就会无限拷贝构造
    Student(Student&& student);
    ~Student();//基本只用于公有，私有可以用，但是现在还不用了解
    std::string GetName() const;
    int GetAge() const;
    std::string GetNum() const;
    int GetMoney() const;
    void ChangeName(const std::string& name);
    void ChangeAge(const int age);
    void ChangeNum(const std::string& num);
    void ChangeMoney(const int& cost);
    Student& operator=(const Student& student);
    //共用的成员函数不要使用this指针,因为this不是共有的，在共有的函数中不能访问某个对象的共有的
    //所以只能访问static变量，因为实际上name什么都是this->name进行实现的
    Student& operator=(Student &&student);
    static void TestStatic();//只能访问类中的static变量
    friend void ChangeAge(Student &student,int age);
    friend StudentFriend;
    friend std::ostream& operator <<(std::ostream &os,const Student & student);
private:
    std::string _name;
    int _age; 
    std::string _num;
    static int _money;
    std::thread _thread;//不可拷贝的对象不能够使用拷贝构造
    int *_data;
};

class StudentFriend{
public:
    StudentFriend()=default;
    void ChangeAge(Student &student,int age);
};

