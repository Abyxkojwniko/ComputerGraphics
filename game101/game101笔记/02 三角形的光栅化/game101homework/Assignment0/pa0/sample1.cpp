#include<iostream>
#include<eigen3/Eigen/Core>

int main(){
    std::cout <<"Example of matrix \n";
    //here is a matrix definition,and you can see 3,so it has three dimensions
    Eigen::Matrix3f i,j;
    i << 1.0 , 2.0 , 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0 , 3.0 , 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    std::cout<<"Example of outpu \n";
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    return 0;
}

/*
PS:
dont care about the space
i just copy from the pdf sometime
and i write some part too
and if you run successfully 
you can see the num is a matrix 3*3
*/
