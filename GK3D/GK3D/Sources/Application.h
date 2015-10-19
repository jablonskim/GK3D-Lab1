#pragma once

#include <memory>
#include <iostream>

#include "Includes.h"
#include "Settings.h"
#include "Input.h"
#include "Camera.h"
#include "Model.h"

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
	void createModels();
	void renderFrame();

	bool is_initialized;
	GLFWwindow* window;
	std::shared_ptr<Camera> camera;

	std::shared_ptr<Model> terrain;
};
