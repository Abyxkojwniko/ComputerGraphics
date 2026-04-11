#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>
/*
so here is how to do
first we can know from the pdf the rotation matrix
ans use three dimension matrix to accomplish the translation
*/
Eigen::Matrix3f createRotationmatrix(const double degree,const Eigen::Vector2f& translation){
    //make degree to radians
    double radian=M_PI*degree/180.0f;
    //make a define
    Eigen::Matrix3f rotation;
    //follow the formula to define the rotation
    rotation << std::cos(radian),-std::sin(radian),translation.x(),
                std::sin(radian), std::cos(radian),translation.y(),
                0.0f            ,0.0f             ,1.0f          ;
    return rotation;
}
int main(){
    //first lets define p
    std::cout<< "please input the dot you define"<<std::endl;
    Eigen::Vector3f p,ans;
    Eigen::Vector2f translation;
    Eigen::Matrix3f rotation;
    for(int i=0;i<2;i++){
        std::cin>>p[i];
    }
    p[2]=1.0f;
    std::cout<< "please input the degree you define"<<std::endl;
    double degree;
    std::cin>>degree;
    std::cout<< "please input the translation you define"<<std::endl;
    std::cin >> translation.x() >> translation.y();
    rotation=createRotationmatrix(degree,translation);
    ans=rotation*p;
    std::cout<<"transformed dot position:\n"<<ans<<std::endl;
    return 0;
}