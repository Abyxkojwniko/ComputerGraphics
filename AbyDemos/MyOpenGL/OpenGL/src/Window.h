#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
	GLFWwindow* m_window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
	void processinput(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
public:
	Window(int width, int height, const char* title) {
		if(!glfwInit()) {
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
		if(m_window == NULL) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
			exit(-1);
		}
		glViewport(0, 0, width, height);
	}
	~Window() {
		glfwTerminate();
	}

	bool shouldClose() {
		return glfwWindowShouldClose(m_window);
	}

	void OnUpdate() {
		processinput(m_window);
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void MakeCurrent(){
		glfwMakeContextCurrent(m_window);
	} //后续实现
};