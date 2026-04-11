#pragma once

#include<iostream>


class Base{
public:
    Base(int num1,int num2):privateNum(num1),protectedNum(num2){
        std::cout<<"Base Constructor"<<std::endl;
    };

    void baseFunc(){
        std::cout<<"Base Func"<<std::endl;
        std::cout<<"Protected num "<<privateNum<<std::endl;
        std::cout<<"Private Num "<<protectedNum<<std::endl;
    }

    ~Base(){
        //std::cout<<"Base Destroyed"<<std::endl;
    }

    virtual void display();//virtual在申明的时候被使用，在cpp中定义中不使用
private:
    int privateNum;
protected:
    int protectedNum;
};

class Derived: public Base{
public:
    Derived():Base(1,2){};

    Derived(int num1,int num2):Base(num1,num2){
        std::cout<<"Derived Constractor"<<std::endl;
    };

    void derivedFunc(){
        std::cout<<"Derived Func " << std::endl;
        std::cout<<"Protected Num "<< protectedNum << std::endl;
    };

    ~Derived(){
        //std::cout<<"Derived Destoryed"<<std::endl;
    }
    //这里叫做重写，这里的函数名和返回类型必须要和基类中一致才能叫重写
    void display() override{
        std::cout << "Derived Vitual Func" << std::endl;
        std::cout << "Protected Num " << protectedNum << std::endl;
    }//上面是虚函数，下面的也会是虚函数
    //子类中调用基类的方法
    void callBaseDisplay(){
        Base::display();
    }
};