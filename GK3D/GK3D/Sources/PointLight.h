#pragma once

#include "Light.h"

class PointLight :
	public Light
{
public:
	PointLight(std::shared_ptr<ShaderProgram> prog, glm::vec3 col = glm::vec3(), glm::vec3 pos = glm::vec3());
	virtual ~PointLight();
};

