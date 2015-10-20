#pragma once

#include "Includes.h"
#include "LookDirection.h"
#include "MoveDirection.h"
#include "ShaderProgram.h"
#include "Settings.h"

class Camera
{
public:
	Camera(std::shared_ptr<ShaderProgram> prog);
	~Camera();

	void move(MoveDirection direction);
	void use();

private:
	std::shared_ptr<ShaderProgram> program;

	glm::mat4 projection;

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
};

