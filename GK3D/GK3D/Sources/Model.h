#pragma once

#include "Includes.h"
#include "Mesh.h"
#include "ShaderProgram.h"

class Model
{
public:
	static std::shared_ptr<Model> fromMesh(std::shared_ptr<Mesh> mesh, std::shared_ptr<ShaderProgram> prog);
	static std::shared_ptr<Model> createTerrain(std::shared_ptr<ShaderProgram> prog);

	~Model();
	void draw();
	void setColor(glm::vec4 col);
	void setMatrix(glm::mat4 matrix);

private:
	Model(std::shared_ptr<ShaderProgram> prog, std::shared_ptr<Mesh> mesh);

	void useColor();
	void useMatrix();

	std::shared_ptr<ShaderProgram> program;
	std::shared_ptr<Mesh> model_mesh;
	
	glm::mat4 model_matrix;
	glm::mat3 normal_matrix;
	glm::vec4 color;
};

