#pragma once

#include "Includes.h"
#include "Settings.h"

namespace InputCallbacks
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
}

class Input
{
public:
	~Input();
	static Input* instance();
	void registerKeyboard(GLFWwindow* window);
	void registerMouse(GLFWwindow* window);
	void disableCursor(GLFWwindow* window, bool disabled);
	void handleInput();

private:
	Input();
	Input(const Input &) = delete;
	Input& operator=(const Input &) = delete;

	void onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
	void onMouse(GLFWwindow* window, double xpos, double ypos);

	friend void InputCallbacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	friend void InputCallbacks::mouse_callback(GLFWwindow* window, double xpos, double ypos);

	bool keys_state[Settings::NumInputKeys];
};
