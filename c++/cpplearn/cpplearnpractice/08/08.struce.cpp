//实现一个简单的学生信息管理系统，允许添加，显示，查找学生信息
/*
- 添加新学生的信息（ID、姓名、成绩）
- 显示所有学生的信息
- 根据学生ID查找学生信息
*/
#include<iostream>
#include<vector>
#include<string>

struct Student{
    int id;
    std::string name;
    int grade;
    void printInfo() const{
        std::cout<<"id:"<<id
                <<",name:"<<name
                <<",grade:"<<grade<<std::endl;
    }
};


void addStudent(std::vector<Student> &students,int id,std::string name,int grade){
    Student student={id,name,grade};
    students.push_back(student);
    std::cout<<"add successfully"<<std::endl;
}

void showStudentinfo(std::vector<Student> &students){
    if(students.empty()){
        std::cout<<"no student here"<<std::endl;
        return ;
    }
    std::cout<<"all student info"<<std::endl;
    for(const auto& student:students){
        student.printInfo();
    }
}

void findStudent(std::vector<Student> &students,int id){
    for(const auto& student:students){
        if(student.id==id){
            student.printInfo();
            return ;
        }
    }
    std::cout<<"cant find the student"<<std::endl;
}

int main(){
    std::vector<Student> stundents;
    int choice;
    do{
        std::cout<<"zhis is student manage system,please choice the function you need"<<std::endl;
        std::cout<<"1.add student"<<std::endl;
        std::cout<<"2.show all student"<<std::endl;
        std::cout<<"3.find student by id"<<std::endl;
        std::cout<<"4.exit"<<std::endl;
        std::cout<<"please choose from 1-4"<<std::endl;
        std::cin>>choice;
        if(choice==1){
            std::cout<<"please input the id name grade one by one"<<std::endl;
            int id;
            std::string name;
            int grade;
            std::cout<<"please input the id"<<std::endl;
            std::cin>>id;
            std::cout<<"please input the name"<<std::endl;
            std::cin>>name;        
            std::cout<<"please input the grade"<<std::endl;
            std::cin>>grade;
            addStudent(stundents,id,name,grade);
        }
        else if(choice==2){
            showStudentinfo(stundents);
        }
        else if(choice==3){
            int id;
            std::cout<<"please input the student id you want to find"<<std::endl;
            std::cin>>id;
            findStudent(stundents,id);
        }
        else if(choice==4){
            std::cout<<"exit the system"<<std::endl;
        }
        else{
            std::cout<<"meaningless choice,please choose again"<<std::endl;
        }
    }while(choice!=4);
    return 0;
}