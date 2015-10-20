#include "Model.h"

Model::Model(std::shared_ptr<ShaderProgram> prog, std::shared_ptr<Mesh> mesh) :
	program(prog),
	model_mesh(mesh)
{
}

std::shared_ptr<Model> Model::fromMesh(std::shared_ptr<Mesh> mesh, std::shared_ptr<ShaderProgram> prog)
{
	auto m = std::shared_ptr<Model>(new Model(prog, mesh));
	// TODO: po³o¿enie modelu?
	return m;
}

std::shared_ptr<Model> Model::createTerrain(std::shared_ptr<ShaderProgram> prog)
{
	// TODO: po³o¿enie modelu przekazane dalej
	return Model::fromMesh(Mesh::createTerrain(), prog);
}

Model::~Model()
{
}

void Model::draw()
{
	program->use();
	model_mesh->draw();
}
