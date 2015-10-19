#include "Model.h"

Model::Model()
{
}

std::shared_ptr<Model> Model::fromMesh(std::shared_ptr<Mesh> mesh)
{
	return std::shared_ptr<Model>();
}

std::shared_ptr<Model> Model::createTerrain()
{
	// TODO
	return Model::fromMesh(Mesh::createTerrain());
}

Model::~Model()
{
}

void Model::draw()
{
	// TODO: glDrawArrays
}
