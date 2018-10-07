#include "gl/Window.hpp"
#include <iostream>

void init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW\n";
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	/*OS X needs this line of code to initialize*/
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

int main()
{
	init();

	Window win(800, 600, "Minecraft");
	win.makeContextCurrent();

	while (!win.shouldClose())
	{
		win.swapBuffers();
	}
}
