#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

// 定义摄像机移动的枚举，避免在类外写死 WASD
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// 默认的摄像机参数
const float YAW = -90.0f; // 初始偏航角设为-90度，是因为0度默认指向X轴正方向
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera {
public:
    // 摄像机属性
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    // 欧拉角
    float Yaw;
    float Pitch;

    // 摄像机选项
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // 构造函数
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors(); // 初始化时根据欧拉角计算 Front, Right, Up
    }

    glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp) {
        // 1. 算 Z 轴：指向屏幕外的 Direction 向量 (Position - Target)
        glm::vec3 zaxis = glm::normalize(position - target);
        // 2. 算 X 轴：Right 向量 (Up 叉乘 Z)
        glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
        // 3. 算 Y 轴：真正的 Up 向量 (Z 叉乘 X)
        glm::vec3 yaxis = glm::cross(zaxis, xaxis);

        // 4. 构建左边的【旋转矩阵】 (注意 GLM 是 mat[列][行])
        glm::mat4 rotation = glm::mat4(1.0f);
        rotation[0][0] = xaxis.x; // 第一列，第一行
        rotation[1][0] = xaxis.y; // 第二列，第一行
        rotation[2][0] = xaxis.z; // 第三列，第一行
        rotation[0][1] = yaxis.x;
        rotation[1][1] = yaxis.y;
        rotation[2][1] = yaxis.z;
        rotation[0][2] = zaxis.x;
        rotation[1][2] = zaxis.y;
        rotation[2][2] = zaxis.z;

        // 5. 构建右边的【平移矩阵】
        glm::mat4 translation = glm::mat4(1.0f);
        translation[3][0] = -position.x; // 第四列，第一行
        translation[3][1] = -position.y;
        translation[3][2] = -position.z;

        // 6. 矩阵相乘：先平移世界，再旋转世界
        return rotation * translation;
    }
    // 返回观察矩阵 (View Matrix)
    glm::mat4 GetViewMatrix() {
        return calculate_lookAt_matrix(Position, Position + Front, WorldUp);
    }

    // 接收键盘输入
    void ProcessKeyboard(Camera_Movement direction, float deltaTime) {
        float velocity = MovementSpeed * deltaTime;
        glm::vec3 flatFront = glm::normalize(glm::vec3(Front.x, 0.0f, Front.z));

        // W 和 S 键使用这个拍扁后的 flatFront！
        if (direction == FORWARD)
            Position += flatFront * velocity;
        if (direction == BACKWARD)
            Position -= flatFront * velocity;

        // A 和 D 键不需要改，因为 Right 向量本来就是平行于地面的（它是用绝对向上的 WorldUp 叉乘出来的）
        if (direction == LEFT)
            Position -= Right * velocity;
        if (direction == RIGHT)
            Position += Right * velocity;
    }

    // 接收鼠标移动输入
    void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        // 限制俯仰角，防止“断脖子”
        if (constrainPitch) {
            if (Pitch > 89.0f)  Pitch = 89.0f;
            if (Pitch < -89.0f) Pitch = -89.0f;
        }

        // 每次鼠标移动后，重新计算最新的方向向量
        updateCameraVectors();
    }

    // 接收鼠标滚轮输入 (缩放)
    void ProcessMouseScroll(float yoffset) {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)  Zoom = 1.0f;
        if (Zoom > 45.0f) Zoom = 45.0f;
    }



private:
    // 根据当前的 Euler Angles (Yaw 和 Pitch) 计算 Front, Right 和 Up 向量
    void updateCameraVectors() {
        // 核心数学：球面坐标转笛卡尔坐标
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

        Front = glm::normalize(front);
        // 重新计算 Right 和 Up
        Right = glm::normalize(glm::cross(Front, WorldUp));
        Up = glm::normalize(glm::cross(Right, Front));
    }
};