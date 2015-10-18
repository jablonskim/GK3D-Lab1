#pragma once

#include "Includes.h"

class Model
{
public:
	static std::shared_ptr<Model> createTerrain();

	~Model();
	void draw();

private:
	Model();
};

