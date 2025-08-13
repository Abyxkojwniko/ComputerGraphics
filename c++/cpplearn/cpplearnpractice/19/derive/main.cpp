#include "derive.h"

int main(){
    // Derived d(10,20);
    // d.derivedFunc();
    // d.baseFunc();

    Derived d2;
    // d2.derivedFunc();
    // d2.baseFunc();
    d2.display();

    Base *dp=new Derived();//此时调用虚函数就是调用的子类的方法
    dp->display();

    return 0;
}