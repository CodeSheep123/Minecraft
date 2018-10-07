#pragma once

#include <array>
#include <GLM\glm.hpp>

#include <GLFW/glfw3.h>

class Quad
{
public:
	Quad(glm::vec3 tl, glm::vec3 tr, glm::vec3 bl, glm::vec3 br);
	
	glm::vec3& operator[](std::size_t index);
	glm::vec3 const& operator[](std::size_t index) const;

	glm::vec3& top_left();
	glm::vec3& top_right();
	glm::vec3& btm_left();
	glm::vec3& btm_right();

	glm::vec3 const& top_left() const;
	glm::vec3 const& top_right() const;
	glm::vec3 const& btm_left() const;
	glm::vec3 const& btm_right() const;

	static constexpr std::size_t TL = 0;
	static constexpr std::size_t TR = 1;
	static constexpr std::size_t BL = 2;
	static constexpr std::size_t BR = 3;

private:
	std::array<glm::vec3, 4> m_corners;
	GLuint VBO;
	GLuint EBO;
};