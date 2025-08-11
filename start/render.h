#pragma once
#include<vector>
#include<eigen3/Eigen/Dense>
//画布大小和简单其他变量的设定
const int Width=600;
const int Height=600;

const double VIEWPORT_SIZE=1.0;
const double PORJECTION_PLANE_Z=1.0;

//各种常规图形的设定
struct Sphere{
    Eigen::Vector3d center;
    double radius;
    Eigen::Vector3d color;
    Sphere(const Eigen::Vector3d& c,double r,const Eigen::Vector3d col):
        center(c),radius(r),color(col){
        }
};


//设定简单的场景
const Eigen::Vector3d CAMERA_POSITION(0,0,0);
const Eigen::Vector3d BACKGROUND_COLOR(255,255,255);


//函数实现
template<typename T>
T clamp(T value, T min, T max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
Eigen::Vector3d canvasToViewPort(double x,double y);//进行坐标转换

bool interserRaySphere(const Eigen::Vector3d& origin,
                    const Eigen::Vector3d& direction,
                    const Sphere& sphere,
                    double &t1,double& t2);//进行交叉判断

Eigen::Vector3d traceRay(const Eigen::Vector3d& origin,
                    const Eigen::Vector3d& direction,
                    double min_t,double max_t,
                    const std::vector<Sphere>& spheres);