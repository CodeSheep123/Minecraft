#pragma once

#include <GLFW/glfw3.h>

//RAII wrapper around OpenGL Vertex Attribute Objects
class VAO
{
public:
	VAO();
	VAO(VAO const&) = delete;
	VAO& operator=(VAO const&) = delete;

	~VAO();

	GLuint vao();

private:
	GLuint m_vao;
};