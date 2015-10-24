#include "Application.h"

Application::Application() :
	is_initialized(false),
	window(nullptr),
	current_width(0),
	current_height(0)
{
	if (!initGLFW())
		return;

	if (!createWindow())
		return;

	Input::instance()->registerKeyboard(window);
	Input::instance()->registerMouse(window);

	Input::instance()->disableCursor(window, true);

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

	glViewport(0, 0, current_width, current_height);
	glEnable(GL_DEPTH_TEST);

	program = ShaderProgram::create(Settings::VertexShaderPath, Settings::FragmentShaderPath);
	if (program == nullptr)
		return 1;

	camera = std::make_shared<Camera>(program, current_width, current_height);

	createModels();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		Input::instance()->handleInput(camera);
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

	glGetError();

	return true;
}

bool Application::createWindow()
{
	std::cout << "Creating window" << std::endl;

	if (Settings::Fullscreen)
	{
		GLFWmonitor *monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode *mode = glfwGetVideoMode(monitor);
		window = glfwCreateWindow(mode->width, mode->height, Settings::WindowTitle, monitor, nullptr);
	}
	else
	{
		window = glfwCreateWindow(Settings::ScreenWidth, Settings::ScreenHeight, Settings::WindowTitle, nullptr, nullptr);
	}

	glfwGetWindowSize(window, &current_width, &current_height);

	if (window == nullptr)
	{
		std::cerr << "Failed to create window." << std::endl;
		return false;
	}

	glfwMakeContextCurrent(window);

	return true;
}

void Application::createModels()
{
	terrain = Model::createTerrain(program);

	/*auto lamp_mesh = Mesh::fromFile(Settings::LampModelPath);
	auto lamp1 = Model::fromMeshes(lamp_mesh, program);
	lamp1->setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	models.push_back(lamp1);*/

	/*auto tree_mesh = Mesh::fromFile(Settings::TreeModelPath);
	auto tree1 = Model::fromMeshes(tree_mesh, program);
	tree1->setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	models.push_back(tree1);*/

	/*auto bench_mesh = Mesh::fromFile(Settings::BenchModelPath);
	auto bench1 = Model::fromMeshes(bench_mesh, program);
	bench1->setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	models.push_back(bench1);*/

	// TODO
}

void Application::renderFrame()
{
	glClearColor(0.f, 0.f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program->use();
	camera->use();

	terrain->draw();
	std::for_each(std::cbegin(models), std::cend(models), [](auto model) { model->draw(); });
}
