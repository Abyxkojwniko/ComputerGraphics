#pragma once
#include "stb.h"
#include <string>
#include <glad/glad.h>

struct TextureParameters {
	GLenum minFilter = GL_LINEAR;
	GLenum magFilter = GL_LINEAR;
	GLenum wrapS = GL_REPEAT;
	GLenum wrapT = GL_REPEAT;
};

class Texture {
public:
	Texture(const std::string& path, const TextureParameters& params);
	~Texture();
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	void setBorderColor(float v0, float v1, float v2, float v3);
private:
	
	int width, height, nrChannels;
	unsigned int m_RenderedID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
};