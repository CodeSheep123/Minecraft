#ifndef MVG_GL_WINDOW_HPP_
#define MVG_GL_WINDOW_HPP_

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <cstddef> //std::size_t
#include <string_view>

class Window
{
public:
	enum class KeyState
	{
		Press,
		Release,
		None,
	};

	Window(std::size_t width, std::size_t height, std::string_view caption);
	Window(Window const&) = delete;
	Window(Window&& other);

	Window& operator=(Window const&) = delete;
	Window& operator=(Window&& other);
	~Window();

	void setClose(bool close);
	bool shouldClose() const;
	//Calling this has the same effect as calling setClose(true)
	void close();
	void makeContextCurrent();

	void swapBuffers();

	KeyState getKey(int key) const;

	std::size_t getWidth() const;
	std::size_t getHeight() const;

private:
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

	GLFWwindow* m_window = nullptr;
	std::size_t m_width, m_height;
};

#endif