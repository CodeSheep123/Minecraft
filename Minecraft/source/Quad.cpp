#include "Quad.hpp"

#include <exception>

Quad::Quad(glm::vec3 tl, glm::vec3 tr, glm::vec3 bl, glm::vec3 br)
{
	m_corners[TL] = tl;
	m_corners[TR] = tr;
	m_corners[BL] = bl;
	m_corners[BR] = br;
}

glm::vec3& Quad::operator[](std::size_t index)
{
	if (index >= 4)
	{
		throw std::out_of_range("Quad index out of range");
	}

	return m_corners[index];
}

glm::vec3 const& Quad::operator [](std::size_t index) const
{
	if (index >= 4)
	{
		throw std::out_of_range("Quad index out of range");
	}

	return m_corners[index];
}

glm::vec3& Quad::top_left()  { return m_corners[TL]; }
glm::vec3& Quad::top_right() { return m_corners[TR]; }
glm::vec3& Quad::btm_left()  { return m_corners[BL]; }
glm::vec3& Quad::btm_right() { return m_corners[BR]; }

glm::vec3 const& Quad::top_left()  const { return m_corners[TL]; }
glm::vec3 const& Quad::top_right() const { return m_corners[TR]; }
glm::vec3 const& Quad::btm_left()  const { return m_corners[BL]; }
glm::vec3 const& Quad::btm_right() const { return m_corners[BR]; }