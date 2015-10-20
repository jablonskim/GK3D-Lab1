#include "Model.h"

Model::Model(std::shared_ptr<ShaderProgram> prog, std::shared_ptr<Mesh> mesh) :
	program(prog),
	model_mesh(mesh)
{
	color = glm::vec4(0.f, 0.f, 0.f, 0.f);
}

void Model::useColor()
{
	glUniform4fv(program->getUniformLocation(Settings::ShaderModelColorLocationName), 1, glm::value_ptr(color));
}

std::shared_ptr<Model> Model::fromMesh(std::shared_ptr<Mesh> mesh, std::shared_ptr<ShaderProgram> prog)
{
	auto m = std::shared_ptr<Model>(new Model(prog, mesh));
	
	// TODO: po³o¿enie modelu?
	return m;
}

std::shared_ptr<Model> Model::createTerrain(std::shared_ptr<ShaderProgram> prog)
{
	auto m = Model::fromMesh(Mesh::createTerrain(), prog);

	m->setColor(glm::vec4(0.f, .5f, 0.f, 1.f));
	// TODO: po³o¿enie modelu przekazane dalej
	return m;
}

Model::~Model()
{
}

void Model::draw()
{
	program->use();

	useColor();

	model_mesh->draw();
}

void Model::setColor(glm::vec4 col)
{
	color = col;
}
