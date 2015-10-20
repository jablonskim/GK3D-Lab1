#include "Camera.h"



Camera::Camera(std::shared_ptr<ShaderProgram> prog) :
	program(prog),
	position(glm::vec3(0.f, 0.1f, 0.5f)),
	front(glm::vec3(0.0f, 0.0f, -1.0f)),
	world_up(glm::vec3(0.f, 1.f, 0.f))
{
	GLfloat ratio = static_cast<GLfloat>(Settings::ScreenWidth) / static_cast<GLfloat>(Settings::ScreenHeight);
	projection = glm::perspective(Settings::FieldOfView, ratio, Settings::PerspectiveNear, Settings::PerspectiveFar);

	update();
}


Camera::~Camera()
{
}

void Camera::move(MoveDirection direction, GLfloat delta)
{
	GLfloat v = delta * Settings::MovementSpeed;

	switch (direction)
	{
	case MoveDirection::Up:
		position += world_up * v;
		break;

	case MoveDirection::Down:
		position -= world_up * v;
		break;

	case MoveDirection::Left:
		position -= right * v;
		break;

	case MoveDirection::Right:
		position += right * v;
		break;

	case MoveDirection::Forward:
		position += front * v;
		break;

	case MoveDirection::Backward:
		position -= front * v;
		break;

	default:
		break;
	}
}

void Camera::use()
{
	GLint projection_mat = program->getUniformLocation(Settings::ShaderProjectionMatrixLocationName);
	glUniformMatrix4fv(projection_mat, 1, GL_FALSE, glm::value_ptr(projection));

	glm::mat4 view = glm::lookAt(position, position + front, up);

	GLint view_mat = program->getUniformLocation(Settings::ShaderViewMatrixLocationName);
	glUniformMatrix4fv(view_mat, 1, GL_FALSE, glm::value_ptr(view));
}

void Camera::update()
{
	front = glm::normalize(front);
	right = glm::normalize(glm::cross(front, world_up));
	up = glm::normalize(glm::cross(right, front));
}
