#include "Window.hpp"

#include <exception>

Window::Window(std::size_t width, std::size_t height, std::string_view caption) 
	: m_width(width), m_height(height)
{
	m_window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), caption.data(), nullptr, nullptr);
	
	
	if (m_window == nullptr)
	{
		throw std::exception("Failed to create window");
	}

	glfwSetFramebufferSizeCallback(m_window, &Window::framebufferResizeCallback);
}

Window::Window(Window&& other)
{
	if (other.m_window != m_window)
	{
		m_width = other.m_width;
		m_height = other.m_height;
		m_window = other.m_window;

		other.m_window = nullptr;
		other.m_width = 0;
		other.m_height = 0;
	}
}

Window& Window::operator=(Window&& other)
{
	if (other.m_window != m_window)
	{
		m_width = other.m_width;
		m_height = other.m_height;
		m_window = other.m_window;

		other.m_window = nullptr;
		other.m_width = 0;
		other.m_height = 0;
	}

	return *this;
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
}

void Window::setClose(bool close)
{
	glfwSetWindowShouldClose(m_window, close);
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void Window::close()
{
	setClose(true);
}

void Window::makeContextCurrent()
{
	glfwMakeContextCurrent(m_window);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(m_window);
}

typename Window::KeyState Window::getKey(int key) const
{
	auto state = glfwGetKey(m_window, key);
	if (state == GLFW_PRESS) return KeyState::Press;
	else if (state == GLFW_RELEASE) return KeyState::Release;
	else return KeyState::None;
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

std::size_t Window::getWidth() const { return m_width; }
std::size_t Window::getHeight() const { return m_height; }