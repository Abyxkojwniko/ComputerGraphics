#include "Window.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <chrono>
#include <thread>

int main() {
	
	Window window(800, 600, "LearnOpenGL");

	float vertices[] = {
		// 位置              // 颜色
		 -0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 左上
		 0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 右上
		 0.0f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 底部
	};
	unsigned int indices[] = {
		// 注意索引从0开始! 
		// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
		// 这样可以由下标代表顶点组合成矩形
		0, 1, 2, // 第一个三角形
	};

	VertexBuffer vbo(vertices, sizeof(vertices));
	IndexBuffer ibo(indices, sizeof(indices) / sizeof(unsigned int));

	VertexBufferLayout layout;
	layout.push<float>(3, 0);
	layout.push<float>(3, 0);
	VertexArray vao;
	vao.addBuffer(vbo, layout);
	ibo.Bind();
	Shader shader("shaders/vertexshader.vs", "shaders/fragmentshader.fs");
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	vao.Unbind();

	while (!window.shouldClose()) {
		auto frameStartTime = std::chrono::high_resolution_clock::now();
		window.MakeCurrent();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		float timeValue = (float)glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		shader.Bind();
		vao.Bind();
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
		window.OnUpdate();
		std::this_thread::sleep_until(frameStartTime + std::chrono::milliseconds(200));
	}
	return 0;
}