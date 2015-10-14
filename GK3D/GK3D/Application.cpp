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
	std::cout << "Cleaning..." << std::endl;
	glfwTerminate();
}

int Application::run()
{
	std::cout << "Starting Application" << std::endl;

	if (!is_initialized)
	{
		std::cerr << "Application is not initialized!" << std::endl;
		return 1;
	}

	glViewport(0, 0, Settings::ScreenWidth, Settings::ScreenHeight);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		renderFrame();
		glfwSwapBuffers(window);
	}

	return 0;
}

bool Application::initGLFW()
{
	std::cout << "Initializing GLFW" << std::endl;

	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Settings::OpenGlMinVersionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Settings::OpenGlMinVersionMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, Settings::WindowResizable ? GL_TRUE : GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	return true;
}

bool Application::initGLEW()
{
	std::cout << "Initializing GLEW" << std::endl;

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
	std::cout << "Creating window" << std::endl;

	window = glfwCreateWindow(Settings::ScreenWidth, Settings::ScreenHeight, "Test", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cerr << "Failed to create window." << std::endl;
		return false;
	}

	glfwMakeContextCurrent(window);

	return true;
}

void Application::renderFrame()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// TODO
}
