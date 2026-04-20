#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include "Camera.h"

class Window {
private:
	GLFWwindow* m_window;
	float m_lastX = 400.0f;
	float m_lastY = 300.0f;
	bool m_firstMouse = true;

	// 2. 存一个当前相机的指针，方便回调时调用
	Camera* m_camera = nullptr;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInputSingle(GLFWwindow* window, Camera& camera, float deltaTime);

public:
	Window(int width, int height, const char* title);
	~Window();
	bool shouldClose();
	void OnUpdate(Camera& camera, float deltaTime);
	void MakeCurrent();
	void SetCamera(Camera* camera) { m_camera = camera; }
	static void static_mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
	void ProcessMouse(double xposIn, double yposIn);
	static void static_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void ProcessScroll(double yoffset);
};