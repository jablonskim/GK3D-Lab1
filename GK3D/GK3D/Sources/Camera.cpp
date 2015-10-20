#include "Camera.h"



Camera::Camera(std::shared_ptr<ShaderProgram> prog) :
	program(prog)
{
	GLfloat ratio = static_cast<GLfloat>(Settings::ScreenWidth) / static_cast<GLfloat>(Settings::ScreenHeight);
	projection = glm::perspective(Settings::FieldOfView, ratio, Settings::PerspectiveNear, Settings::PerspectiveFar);
}


Camera::~Camera()
{
}

void Camera::move(MoveDirection direction)
{
	// TODO: set vecs
}

void Camera::use()
{
	GLint projection_mat = program->getUniformLocation(Settings::ShaderProjectionMatrixLocationName);
	glUniformMatrix4fv(projection_mat, 1, GL_FALSE, glm::value_ptr(projection));

	glm::mat4 view = glm::lookAt(position, position + front, up);

	GLint view_mat = program->getUniformLocation(Settings::ShaderViewMatrixLocationName);
	glUniformMatrix4fv(view_mat, 1, GL_FALSE, glm::value_ptr(view));
}
