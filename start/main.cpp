#include<iostream>
#include "render.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
int main(){
    std::vector<Sphere> spheres={
        Sphere(Eigen::Vector3d(0, -1, 3), 1, Eigen::Vector3d(255, 0, 0)),
        Sphere(Eigen::Vector3d(2, 0, 4), 1, Eigen::Vector3d(0, 0, 255)),
        Sphere(Eigen::Vector3d(-2, 0, 4), 1, Eigen::Vector3d(0, 255, 0))     
    };
    std::vector<unsigned char>image(Width*Height*3);
    for(int y=Height/2;y>-Height/2;y--){
        for(int x=-Width/2;x<Width/2;x++){
            Eigen::Vector3d direction=canvasToViewPort(x,y);
            Eigen::Vector3d color=traceRay(CAMERA_POSITION,direction,1,10000,spheres);
            int index=((Height/2-y)*Width+(x+Width/2))*3;
            image[index+0]=static_cast<unsigned char>(clamp(color[0], 0.0, 255.0));
            image[index+1]=static_cast<unsigned char>(clamp(color[1], 0.0, 255.0));
            image[index+2]=static_cast<unsigned char>(clamp(color[2], 0.0, 255.0));
        }
    }
    if (stbi_write_png("output.png", Width, Height, 3, image.data(), Width*3)) {
        std::cout << "成功保存图像到 output.png" << std::endl;
    } else {
        std::cerr << "保存图像失败！" << std::endl;
    }
    return 0;
}