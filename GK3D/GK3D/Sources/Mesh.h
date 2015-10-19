#pragma once

#include "Includes.h"
#include "Vertex.h"
#include "Settings.h"

class Mesh
{
public:
	~Mesh();
	static std::shared_ptr<Mesh> createTerrain();
	static std::shared_ptr<Mesh> fromFile();
	void draw();

private:
	Mesh();
	void setupArrays();

	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	Mesh(const Mesh &) = delete;
	Mesh& operator=(const Mesh &) = delete;

};

