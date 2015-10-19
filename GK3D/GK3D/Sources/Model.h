#pragma once

#include "Includes.h"
#include "Mesh.h"

class Model
{
public:
	static std::shared_ptr<Model> fromMesh(std::shared_ptr<Mesh> mesh);
	static std::shared_ptr<Model> createTerrain();

	~Model();
	void draw();

private:
	Model();
};

