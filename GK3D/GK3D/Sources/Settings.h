#pragma once

class Settings
{
public:
	static const int ScreenWidth = 800;
	static const int ScreenHeight = 600;

	static const int OpenGlMinVersionMajor = 3;
	static const int OpenGlMinVersionMinor = 3;

	static const bool WindowResizable = false;
	static constexpr char* WindowTitle = "Test";

	static constexpr int MessageBufferSize = 1024;

	static constexpr float FieldOfView = 45.0f;
	static constexpr int NumInputKeys = 1024;

	static const int MoveUpKey = GLFW_KEY_UP;
	static const int MoveDownKey = GLFW_KEY_DOWN;
	static const int MoveLeftKey = GLFW_KEY_A;
	static const int MoveRightKey = GLFW_KEY_D;
	static const int MoveForwardKey = GLFW_KEY_W;
	static const int MoveBackwardKey = GLFW_KEY_S;

	static const int TerrainSize = 10;

	static const bool InvertMouseX = false;
	static const bool InvertMouseY = false;

private:
	Settings() = delete;
	Settings(const Settings &) = delete;
};

