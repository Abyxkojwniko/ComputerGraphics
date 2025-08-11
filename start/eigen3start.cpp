#include<eigen3/Eigen/Dense>
#include<iostream>
int main(){
    Eigen::MatrixXd matrix(3,3);
    matrix <<1,2,3,
            4,5,6,
            7,8,9;
            
    std::cout<<"(1,1) is "<<matrix(1,1)<<std::endl;
    return 0;
}