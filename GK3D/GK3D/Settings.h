#pragma once

class Settings
{
public:
	static const int ScreenWidth = 800;
	static const int ScreenHeight = 600;

	static const int OpenGlMinVersionMajor = 3;
	static const int OpenGlMinVersionMinor = 3;

	static const bool WindowResizable = false;

private:
	Settings() = delete;
	Settings(const Settings &) = delete;
};

