/*
#### 示例项目1：学生信息管理系统

**需求分析：**

创建一个程序，管理学生的信息，包括添加、删除、显示和查找学生。每个学生包含ID、姓名和成绩。

*/

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

struct Student{
    int id;
    std::string name;
    float grade;
    void printstudentinfo() const{
        std::cout<<"id:"<<id
            <<",name:"<<name
            <<",grade"<<grade<<std::endl;
    }
};


//这里注意因为是直接对原数据进行操作，所以必须要加上&
void addStudent(std::vector<Student> &studends){
    Student s={};
    std::cout<<"please input the id"<<std::endl;
    std::cin>>s.id;
    std::cout<<"please input the name"<<std::endl;
    std::cin>>s.name;
    std::cout<<"please input the grade"<<std::endl;
    std::cin>>s.grade;
    studends.push_back(s);
    std::cout<<"add successfully"<<std::endl;
}

void deleteStudent(std::vector<Student> &students){
    if(students.empty()){
        std::cout<<"there is no student"<<std::endl;
    }
    std::cout<<"please input the student's id you want to delete";
    int id;
    std::cin>>id;
    auto it=std::find_if(students.begin(),students.end(),[id](const Student &s){
        return s.id==id;
    });
    if(it!=students.end()){
        students.erase(it);
        std::cout<<"delete sucessfully"<<std::endl;
    }
    else{
        std::cout<<"cant find the student's id "<<id<<std::endl;
    }
    return ;
}

//这里注意因为这个函数是不能更改值的，所以加入const，加入引用，这样就可以减少创建的临时变量
void showstudentinfo(const std::vector<Student>& students){
    std::cout<<"show all the student's info"<<std::endl;
    for(auto student:students){
        student.printstudentinfo();
        std::cout<<std::endl;
    }
    std::cout<<"already show all student information"<<std::endl;
}

void findStudent(const std::vector<Student>& students){
    int id;
    std::cout<<"please input the student's id you want to find"<<std::endl;
    std::cin>>id;
    auto it=std::find_if(students.begin(),students.end(),[id](const Student &s){
        return s.id==id;
    });
    if(it!=students.end()){
        std::cout<<"find successfully"<<std::endl;
        (*it).printstudentinfo();
    }
    else{
        std::cout<<"cant find the id "<<id<<std::endl;
    }
}

int main(){
    std::cout<<"welcome to the student information manage system"<<std::endl;
    int choice;
    do{
        std::cout<<"please choose the funciton you need"<<std::endl;
        std::cout<<"1.add student"<<std::endl;
        std::cout<<"2.delete student"<<std::endl;
        std::cout<<"3.show all student"<<std::endl;
        std::cout<<"4.find student by id"<<std::endl;
        std::cout<<"5.exit"<<std::endl;
        std::cout<<"please choose from 1-5"<<std::endl;
        std::vector<Student> students;
        std::cin>>choice;
        if(choice==1){
            addStudent(students);
        }
        else if(choice==2){
            deleteStudent(students);
        }
        else if(choice==3){
            showstudentinfo(students);
        }
        else if(choice==4){
            findStudent(students);
        }
        else if(choice==5){
            std::cout<<"exit the system"<<std::endl;
        }
        else{
            std::cout<<"meaningless choice,please choose again"<<std::endl;
        }
    }while(choice!=5);
    return 0;
}
