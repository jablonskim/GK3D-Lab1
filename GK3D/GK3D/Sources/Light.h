#pragma once

#include "Includes.h"
#include "Settings.h"
#include "ShaderProgram.h"

class Light
{
public:
	Light(std::shared_ptr<ShaderProgram> prog, glm::vec3 col = glm::vec3(), glm::vec3 pos = glm::vec3());
	virtual ~Light();

	void setPosition(glm::vec3 pos);
	void setColor(glm::vec3 col);

	virtual void use();

protected:
	GLint getUniformLocation(const char* struct_name, const char* field_name);
	virtual const char* getLightArrayLocName() = 0;

	bool is_on;

private:
	virtual int getId() = 0;

	std::shared_ptr<ShaderProgram> program;
	int light_id;

	glm::vec3 position;
	glm::vec3 color;
};

