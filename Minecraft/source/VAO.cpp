#include "VAO.hpp"

#include "glad/glad.h"

VAO::VAO()
{
	glGenVertexArrays(1, &m_vao);
}

VAO::~VAO()
{
	glDeleteBuffers(1, &m_vao);
}

GLuint VAO::vao()
{
	return m_vao;
}