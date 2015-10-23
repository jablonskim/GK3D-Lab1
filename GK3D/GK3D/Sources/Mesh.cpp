#include "Mesh.h"

Mesh::Mesh() :
	vao(0),
	vbo(0),
	ebo(0)
{
	std::cout << "Creating new mesh..." << std::endl;
}

void Mesh::setupArrays()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(offsetof(Vertex, position)));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(offsetof(Vertex, normal)));

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteVertexArrays(1, &vbo);
	glDeleteVertexArrays(1, &ebo);

	std::cout << "Destroying mesh..." << std::endl;
}

std::vector<std::shared_ptr<Mesh>> Mesh::createTerrain()
{
	auto m = std::shared_ptr<Mesh>(new Mesh());

	int num_vertices = Settings::TerrainSize;

	float ter_from = -1.f;
	float ter_to = 1.f;
	float ter_s = ter_to - ter_from;

	for (int i = 0; i <= num_vertices; ++i)
	{
		for (int j = 0; j <= num_vertices; ++j)
		{
			float x = (i * ter_s / num_vertices) + ter_from;
			float y = (j * ter_s / num_vertices) + ter_from;

			Vertex v;
			float r = static_cast<float>(rand());
			v.position = glm::vec3(x, y, (r / RAND_MAX) * 0.02f - 0.02f);
			v.normal = glm::vec3(0.f, 0.f, 0.f);

			m->vertices.push_back(v);
		}
	}

	int n = Settings::TerrainSize;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			m->indices.push_back((i + 0) * (n + 1) + j + 0);
			m->indices.push_back((i + 1) * (n + 1) + j + 0);
			m->indices.push_back((i + 0) * (n + 1) + j + 1);

			m->indices.push_back((i + 0) * (n + 1) + j + 1);
			m->indices.push_back((i + 1) * (n + 1) + j + 0);
			m->indices.push_back((i + 1) * (n + 1) + j + 1);
		}
	}

	for (auto i = std::begin(m->indices); i != std::end(m->indices); std::advance(i, 3))
	{
		glm::vec3 v[] = { m->vertices[i[0]].position, m->vertices[i[1]].position, m->vertices[i[2]].position };
		glm::vec3 norm = glm::cross(v[1] - v[0], v[2] - v[0]);

		for (int j = 0; j < 3; ++j)
		{
			m->vertices[*(i + j)].normal += norm;
		}
	}

	for (auto i = std::begin(m->vertices); i != std::end(m->vertices); std::advance(i, 1))
		i->normal = glm::normalize(i->normal);

	m->setupArrays();

	return { m };
}

std::vector<std::shared_ptr<Mesh>> Mesh::fromFile()
{
	// TODO
	return std::vector<std::shared_ptr<Mesh>>();
}

void Mesh::draw()
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
