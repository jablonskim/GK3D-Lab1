#include "Application.h"

Application::Application() :
	is_initialized(false),
	window(nullptr)
{
	if (!initGLFW())
		return;

	if (!createWindow())
		return;

	if (!initGLEW())
		return;

	is_initialized = true;
}

Application::~Application()
{
	glfwTerminate();
}

int Application::run()
{
	if (!is_initialized)
	{
		std::cerr << "Application is not initialized!" << std::endl;
		return 1;
	}

	// TODO

	return 0;
}

bool Application::initGLFW()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	return true;
}

bool Application::initGLEW()
{
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW." << std::endl;
		return false;
	}

	return true;
}

bool Application::createWindow()
{
	window = glfwCreateWindow(800, 600, "Test", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cerr << "Failed to create window." << std::endl;
		return false;
	}

	glfwMakeContextCurrent(window);

	return true;
}
