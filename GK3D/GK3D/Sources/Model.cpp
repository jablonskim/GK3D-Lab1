#include "Model.h"

Model::Model(std::shared_ptr<ShaderProgram> prog, std::shared_ptr<Mesh> mesh) :
	program(prog),
	model_mesh(mesh)
{
	color = glm::vec4(0.f, 0.f, 0.f, 0.f);
	setMatrix(glm::mat4());
}

void Model::useColor()
{
	glUniform4fv(program->getUniformLocation(Settings::ShaderModelColorLocationName), 1, glm::value_ptr(color));
}

void Model::useMatrix()
{
	GLint model_mat = program->getUniformLocation(Settings::ShaderModelMatrixLocationName);
	glUniformMatrix4fv(model_mat, 1, GL_FALSE, glm::value_ptr(model_matrix));

	GLint normal_mat = program->getUniformLocation(Settings::ShaderNormalMatrixLocationName);
	glUniformMatrix3fv(normal_mat, 1, GL_FALSE, glm::value_ptr(normal_matrix));
}

std::shared_ptr<Model> Model::fromMesh(std::shared_ptr<Mesh> mesh, std::shared_ptr<ShaderProgram> prog)
{
	return std::shared_ptr<Model>(new Model(prog, mesh));
}

std::shared_ptr<Model> Model::createTerrain(std::shared_ptr<ShaderProgram> prog)
{
	auto m = Model::fromMesh(Mesh::createTerrain(), prog);

	m->setColor(glm::vec4(0.f, .5f, 0.f, 1.f));
	auto rotated = glm::rotate(m->model_matrix, glm::radians(90.f), glm::vec3(-1.f, 0.f, 0.f));
	auto scaled = glm::scale(rotated, glm::vec3(Settings::TerrainScaleFactor));
	m->setMatrix(scaled);

	return m;
}

Model::~Model()
{
}

void Model::draw()
{
	useColor();
	useMatrix();

	model_mesh->draw();
}

void Model::setColor(glm::vec4 col)
{
	color = col;
}

void Model::setMatrix(glm::mat4 matrix)
{
	model_matrix = matrix;
	normal_matrix = glm::mat3(glm::transpose(glm::inverse(matrix)));
}
