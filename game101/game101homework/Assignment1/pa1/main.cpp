#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(const Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(const float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    Eigen::Matrix4f rotation;
    float radian=MY_PI*rotation_angle/180.0f;
    rotation << std::cos(radian),-std::sin(radian),0.0f,0.0f,
                std::sin(radian), std::cos(radian),0.0f,0.0f,
                0.0f            ,0.0f             ,1.0f,0.0f,
                0.0f            ,0.0f             ,0.0f,1.0f;  
    model*=rotation;
    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();
    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.
    //这里分别定义投影矩阵，然后正交投影矩阵的坐标变换矩阵和
    Eigen::Matrix4f preps,ortho,trans;
    preps<< zNear,0.0f,0.0f,0.0f,
                0.0f ,zNear,0.0f,0.0f,
                0.0f ,0.0f ,(zNear+zFar),-zNear*zFar,
                0.0f ,0.0f ,1.0f,0.0f;  
    double width,height,z;
    height=zNear*std::tan(eye_fov/2)*2;
    width=height*aspect_ratio;
    z=zNear-zFar;
    ortho<< 2.0f/width,0.0f,0.0f,0.0f,
            0.0f ,2.0f/height,0.0f,0.0f,
            0.0f ,0.0f ,2.0f/z,0.0f,
            0.0f ,0.0f ,0.0f,1.0f; 
    trans<< 1.0f,0.0f,0.0f,0.0f,
            0.0f,1.0f,0.0f,0.0f,
            0.0f,0.0f,1.0f,-(zNear+zFar)/2,
            0.0f,0.0f,0.0f,1.0f; 
    ortho*=trans;
    projection=ortho*preps*projection;
    return projection;
}
//这里按照任意轴进行旋转
Eigen::Matrix4f get_random_model_matrix(Eigen::Vector3f n,float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    float angle = rotation_angle * MY_PI / 180.0f;
    float nx = n[0];
    float ny = n[1];
    float nz = n[2];
    Eigen::Matrix3f N;
    N <<
        0, -nz, ny,
        nz, 0, -nx,
        -ny, nx, 0;
    Eigen::Matrix3f I=Eigen::Matrix3f::Identity();
    Eigen::Matrix3f R=std::cos(angle)*I+(1-std::cos(angle))*n*n.transpose()+std::sin(angle)*N;
    model <<
        R(0,0),R(0,1),R(0,2),0,
        R(1,0),R(1,1),R(1,2),0,
        R(2,0),R(2,1),R(2,2),0,
        0,0,0,1;
    return model;
}
int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
