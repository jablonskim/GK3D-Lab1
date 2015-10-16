#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() :
	shader_program(0)
{
}

bool ShaderProgram::createProgram(std::string vertex_shader_path, std::string fragment_shader_path)
{
	// TODO
	return true;
}

ShaderProgram::~ShaderProgram()
{
	if (shader_program != 0)
	{
		glDeleteProgram(shader_program);
	}
}

void ShaderProgram::use()
{
	glUseProgram(shader_program);
}

std::shared_ptr<ShaderProgram> ShaderProgram::create(std::string vertex_shader_path, std::string fragment_shader_path)
{
	auto program = std::shared_ptr<ShaderProgram>(new ShaderProgram());

	if (!program->createProgram(vertex_shader_path, fragment_shader_path))
	{
		return std::shared_ptr<ShaderProgram>();
	}

	return program;
}
