#include "Input.h"

namespace InputCallbacks
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		Input::instance()->onKey(window, key, scancode, action, mode);
	}

	void mouse_callback(GLFWwindow * window, double xpos, double ypos)
	{
		Input::instance()->onMouse(window, xpos, ypos);
	}
}

Input::Input()
{
}

void Input::onKey(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		return;
	}

	if (key >= 0 && key < Settings::NumInputKeys)
	{
		switch (action)
		{
		case GLFW_PRESS:
			keys_state[key] = true;
			break;

		case GLFW_RELEASE:
			keys_state[key] = false;
			break;

		default:
			break;
		}
	}
}

void Input::onMouse(GLFWwindow * window, double xpos, double ypos)
{
	// TODO
}

Input::~Input()
{
}

Input* Input::instance()
{
	static Input input;

	return &input;
}

void Input::registerKeyboard(GLFWwindow * window)
{
	glfwSetKeyCallback(window, InputCallbacks::key_callback);
}

void Input::registerMouse(GLFWwindow * window)
{
	glfwSetCursorPosCallback(window, InputCallbacks::mouse_callback);
}

void Input::disableCursor(GLFWwindow * window, bool disabled)
{
	glfwSetInputMode(window, GLFW_CURSOR, disabled ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Input::handleInput(std::shared_ptr<Camera> & camera)
{
	if (keys_state[Settings::MoveForwardKey])
		camera->move(MoveDirection::Forward);

	if (keys_state[Settings::MoveBackwardKey])
		camera->move(MoveDirection::Backward);

	if (keys_state[Settings::MoveLeftKey])
		camera->move(MoveDirection::Left);

	if (keys_state[Settings::MoveRightKey])
		camera->move(MoveDirection::Right);

	if (keys_state[Settings::MoveUpKey])
		camera->move(MoveDirection::Up);

	if (keys_state[Settings::MoveDownKey])
		camera->move(MoveDirection::Down);

	// TODO: mouse
}
