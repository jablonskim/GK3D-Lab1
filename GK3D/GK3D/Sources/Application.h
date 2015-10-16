#pragma once

#include <memory>
#include <iostream>

#include "Includes.h"
#include "Settings.h"

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
