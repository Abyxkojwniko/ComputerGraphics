#include<iostream>
#include<math.h>

int main(){
    float a=10,b=2.0;
    std::cout<<a<<std::endl;
    std::cout<<a/b<<std::endl;
    std::cout<<std::sqrt(a)<<std::endl;
    /*
        acos here is the opposite of cos
        but here it was show as radians,not degrees
        so if you need degree
        you should mutliply 180/pi
        so cos(180 degree)=-1
        acos(-1)=180 degree
        for how much pi? it was one pi
        so for sin(30/180*pi) this is 30 degree
        so the answer is 0.5
    */   
    std::cout<<std::acos(-1)<<std::endl;
    std::cout<<std::sin(30.0/180.0*acos(-1))<<std::endl;
    return 0;
}