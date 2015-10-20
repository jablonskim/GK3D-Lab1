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

private:
	Model(std::shared_ptr<ShaderProgram> prog, std::shared_ptr<Mesh> mesh);

	std::shared_ptr<ShaderProgram> program;
	std::shared_ptr<Mesh> model_mesh;
};

