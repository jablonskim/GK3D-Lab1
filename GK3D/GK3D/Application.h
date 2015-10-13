#pragma once

#include <memory>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Application
{
public:
	Application();
	~Application();

	int run();

private:
	bool initGLFW();
	bool initGLEW();
	bool createWindow();
	void renderFrame();

	bool is_initialized;
	GLFWwindow* window;
};
