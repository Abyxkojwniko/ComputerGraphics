#include "student.h"

int main(){
    Student student1;
    student1.ChangeAge(50);
    student1.ChangeName("john");
    student1.ChangeNum("10001");
    std::cout<<"name:"<<student1.GetName()<<std::endl;
    std::cout<<"age:"<<student1.GetAge()<<std::endl;
    std::cout<<"num:"<<student1.GetNum()<<std::endl;
    
    Student student2("npc",18,"10002");
    std::cout<<"name:"<<student2.GetName()<<std::endl;
    std::cout<<"age:"<<student2.GetAge()<<std::endl;
    std::cout<<"num:"<<student2.GetNum()<<std::endl;
    std::cout<<"money:"<<student2.GetMoney()<<std::endl;
    
    student2.ChangeMoney(5);
    std::cout<<"money:"<<student2.GetMoney()<<std::endl;
    Student student4(student1);
    std::cout<<"name:"<<student4.GetName()<<std::endl;
    std::cout<<"age:"<<student4.GetAge()<<std::endl;
    std::cout<<"num:"<<student4.GetNum()<<std::endl;
    
    Student student5(std::move(student1));
    std::cout<<"name:"<<student5.GetName()<<std::endl;
    std::cout<<"age:"<<student5.GetAge()<<std::endl;
    std::cout<<"num:"<<student5.GetNum()<<std::endl;   
    // std::cout<<"name:"<<student1.GetName()<<std::endl;
    // std::cout<<"age:"<<student1.GetAge()<<std::endl;
    // std::cout<<"num:"<<student1.GetNum()<<std::endl;
    //被移动后的对象不要再进行使用

    Student student6;
    student6.GetMoney();
    std::cout<<"student6 address is "<<&student6<<std::endl;
    std::cout<<"name:"<<student6.GetName()<<std::endl;
    std::cout<<"age:"<<student6.GetAge()<<std::endl;
    std::cout<<"num:"<<student6.GetNum()<<std::endl;
    
    student6=student2;
    std::cout<<"student6 address is "<<&student6<<std::endl;
    std::cout<<"name:"<<student6.GetName()<<std::endl;
    std::cout<<"age:"<<student6.GetAge()<<std::endl;
    std::cout<<"num:"<<student6.GetNum()<<std::endl;
    
    Student student7=std::move(student6);
    //Studetn student7(std::move(student6)) 等价
    std::cout<<"name:"<<student7.GetName()<<std::endl;
    std::cout<<"age:"<<student7.GetAge()<<std::endl;
    std::cout<<"num:"<<student7.GetNum()<<std::endl;
    ChangeAge(student7,20);
    std::cout<<"age:"<<student7.GetAge()<<std::endl;
    
    Student student8(student7);
    std::cout<<student8;
    
    return 0;
}