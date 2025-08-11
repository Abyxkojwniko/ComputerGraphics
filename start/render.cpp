#include "render.h"

Eigen::Vector3d canvasToViewPort(double x,double y){
    x=x*VIEWPORT_SIZE/Width;
    y=y*VIEWPORT_SIZE/Height;
    return Eigen::Vector3d(x,y,PORJECTION_PLANE_Z);
}

bool interserRaySphere(const Eigen::Vector3d& origin,
                    const Eigen::Vector3d& direction,
                    const Sphere& sphere,
                    double &t1,double& t2){
    Eigen::Vector3d oc=origin-sphere.center;
    double k1=direction.dot(direction);
    double k2=2*oc.dot(direction);
    double k3=oc.dot(oc)-sphere.radius*sphere.radius;
    double discriminant=k2*k2-4*k1*k3;
    if(discriminant<0) return false;
    t1=(-k2+sqrt(discriminant))/(2*k1);
    t2=(-k2-sqrt(discriminant))/(2*k1);
    return true;
    
}

Eigen::Vector3d traceRay(const Eigen::Vector3d& origin,
                    const Eigen::Vector3d& direction,
                    double min_t,double max_t,
                    const std::vector<Sphere>& spheres){
    double closest_t=std::numeric_limits<double>::infinity();
    const Sphere* closest_sphere=nullptr;
    for(const auto& sphere:spheres){
        double t1,t2;
        if(interserRaySphere(origin,direction,sphere,t1,t2)){
            if(t1>min_t&&t1<max_t&&t1<closest_t){
                closest_t=t1;
                closest_sphere=&sphere;
            }
            if(t2>min_t&&t2<max_t&&t2<closest_t){
                closest_t=t2;
                closest_sphere=&sphere;
            }
        }
    }
    return (closest_sphere)?closest_sphere->color:BACKGROUND_COLOR;             
}