#pragma once


#include <iostream>
#include <vector>
#include <glad/glad.h>


struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type) {
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}
		return 0;
	}
};


class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout() : m_Stride(0) {};

	template<typename T>
	void push(unsigned int count, unsigned int normalized) {
		std::cout << "Unsupported type!" << std::endl;
	}

	template<>
	void push<float>(unsigned int count, unsigned int normalized) {
		m_elements.push_back({ GL_FLOAT, count, normalized ? true : false });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void push<unsigned int>(unsigned int count, unsigned int normalized) {
		m_elements.push_back({ GL_UNSIGNED_INT, count, normalized ? true : false });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void push<unsigned char>(unsigned int count, unsigned int normalized) {
		m_elements.push_back({ GL_UNSIGNED_BYTE, count, normalized ? true : false });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return m_elements; }
	inline unsigned int GetStride() const { return m_Stride; }
};