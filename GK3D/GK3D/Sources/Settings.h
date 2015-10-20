#pragma once

class Settings
{
public:
	static const int ScreenWidth = 1280;
	static const int ScreenHeight = 720;

	static const int OpenGlMinVersionMajor = 3;
	static const int OpenGlMinVersionMinor = 3;

	static const bool WindowResizable = false;
	static constexpr char* WindowTitle = "Test";

	static constexpr int MessageBufferSize = 1024;

	static constexpr float FieldOfView = 45.0f;
	static constexpr float PerspectiveNear = .01f;
	static constexpr float PerspectiveFar = 1000.f;

	static constexpr int NumInputKeys = 1024;

	static const int MoveUpKey = GLFW_KEY_UP;
	static const int MoveDownKey = GLFW_KEY_DOWN;
	static const int MoveLeftKey = GLFW_KEY_A;
	static const int MoveRightKey = GLFW_KEY_D;
	static const int MoveForwardKey = GLFW_KEY_W;
	static const int MoveBackwardKey = GLFW_KEY_S;

	static const int WireframeModeKey = GLFW_KEY_H;

	static constexpr float MovementSpeed = .3f;
	static constexpr float MouseSensitivityX = .1f;
	static constexpr float MouseSensitivityY = .1f;
	static const bool MoveToLookDirection = true;

	static const int TerrainSize = 50;

	static const bool InvertMouseX = false;
	static const bool InvertMouseY = false;

	static constexpr char* VertexShaderPath = "C:\\Users\\jablonskim\\Documents\\GitHub\\GK3D-Lab1\\GK3D\\Debug\\VertexShader.glsl";
	static constexpr char* FragmentShaderPath = "C:\\Users\\jablonskim\\Documents\\GitHub\\GK3D-Lab1\\GK3D\\Debug\\FragmentShader.glsl";

	static constexpr char* ShaderModelColorLocationName = "model_color";

	static constexpr char* ShaderProjectionMatrixLocationName = "projection_matrix";
	static constexpr char* ShaderViewMatrixLocationName = "view_matrix";
	static constexpr char* ShaderModelMatrixLocationName = "model_matrix";

private:
	Settings() = delete;
	Settings(const Settings &) = delete;
};

