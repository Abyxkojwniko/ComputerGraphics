#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::processInputSingle(GLFWwindow* window, Camera& camera, float deltaTime) {
	// 退出键逻辑保留
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// 彻底抛弃在这里手动算数学！把所有的按键指令，直接汇报给 Camera 黑盒！
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}


Window::Window(int width, int height, const char* title) {
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		exit(-1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // core profile
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// glfwCreateWindow函数需要窗口的宽和高作为它的前两个参数。
	// 第三个参数表示这个窗口的名称（标题）。最后两个参数我们暂时忽略。这个函数将会返回一个GLFWwindow对象，
	// 我们会在其它的GLFW操作中使用到。创建完窗口我们就可以通知GLFW将我们窗口的上下文设置为当前线程的主上下文了。

	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (m_window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	glfwSetWindowUserPointer(m_window, this);
	// 告诉 GLFW 鼠标移动时调用我们的静态函数
	glfwSetCursorPosCallback(m_window, static_mouse_callback);
	glfwSetScrollCallback(m_window, static_scroll_callback);
	// 隐藏并捕捉鼠标
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glViewport(0, 0, width, height);
}
Window::~Window(){
		glfwTerminate();
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(m_window);
}

void Window::OnUpdate(Camera& camera, float deltaTime) {
	processInputSingle(m_window, camera, deltaTime);
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void Window::MakeCurrent() {
	glfwMakeContextCurrent(m_window);
}

void Window::static_mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
	// 从 GLFW 窗口里，把我们刚才藏进去的 this 指针拿出来！
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));

	// 如果拿到了，就调用这个对象真正的成员函数
	if (win) {
		win->ProcessMouse(xposIn, yposIn);
	}
}

void Window::ProcessMouse(double xposIn, double yposIn) {
	// 如果还没绑定相机，就先不处理
	if (!m_camera) return;

	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (m_firstMouse) {
		m_lastX = xpos;
		m_lastY = ypos;
		m_firstMouse = false;
	}

	float xoffset = xpos - m_lastX;
	float yoffset = m_lastY - ypos; // 注意这里是相反的

	m_lastX = xpos;
	m_lastY = ypos;

	// 直接调用我们存下来的相机指针！
	m_camera->ProcessMouseMovement(xoffset, yoffset);
}

void Window::static_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	// 熟悉的配方：拿出 this 指针
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (win) {
		// xoffset 咱们用不到，只把 yoffset 传进去
		win->ProcessScroll(yoffset);
	}
}

void Window::ProcessScroll(double yoffset) {
	// 保护机制：如果没有绑定相机，直接退出
	if (!m_camera) return;

	// 直接调用相机的缩放方法！
	m_camera->ProcessMouseScroll(static_cast<float>(yoffset));
}