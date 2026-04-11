#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer {
private:
	unsigned int m_rendererID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	void Bind() const;
	void Unbind() const;
};