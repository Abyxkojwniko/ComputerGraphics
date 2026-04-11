#include<iostream>
#include<eigen3/Eigen/Core>
//这个程序用于测试你的eigen3是否安装成功
int main(){
    // Example of vector
    std :: cout << " Example of vector \n";
    // vector definition
    Eigen :: Vector3f v(1.0f ,2.0f ,3.0f);
    //两个冒号前面实际上就是申明用eigen里面的库定义的vector，后方就是和int x这种差不多
    //从实现来看应该是一个类可以接受多个数值，方便计算
    Eigen :: Vector3f w(1.0f ,0.0f ,0.0f);
    // vector output
    std :: cout << " Example of output \n";
    std :: cout << v << std :: endl;
    // vector add
    std :: cout << " Example of add \n";
    std :: cout << v + w << std :: endl;
    // vector scalar multiply
    std :: cout << " Example of scalar multiply \n";
    std :: cout << v * 3.0f << std :: endl;
    std :: cout << 2.0f * v << std :: endl;
    //so for dot multiply
    std :: cout << "Example of dot Product \n";
    std :: cout << v*w.transpose() << std::endl;
    std :: cout << v.transpose()*w << std::endl;
    std :: cout << std :: endl;
    return 0;
}

/*
and if you run successfully 
you can see 
1 0 0
2 0 0
3 0 0
1
in the terminal
and this is how to dot product
*/
