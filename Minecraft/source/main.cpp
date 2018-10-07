#include "gl/Window.hpp"
#include "gl/Shader.hpp"
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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD\n";
		return -1;
	}
	
	Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");
	shader.use();

	glClearColor(0, 0, 255, 0);

	while (!win.shouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		win.swapBuffers();
		glfwPollEvents();
	}
}
