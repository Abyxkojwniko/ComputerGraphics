#pragma once

#include <glad/glad.h>
#include <string>
#include <unordered_map>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


class Shader {
public:
	unsigned int ID;
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void checkCompileErrors(unsigned int shader, const std::string type);

	void Bind() const;
	void Unbind() const;
	unsigned int GetID() const { return ID; };

	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniform1f(const std::string& name, float v0);
	void setUniform1i(const std::string& name, int v0);
	void setUniform4mat(const std::string& name, glm::mat4 trans);
private:
	int GetUniformLocation(const std::string& name);
	std::unordered_map<std::string, int> m_UniformLocationCache;

};