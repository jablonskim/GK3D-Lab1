#include "Camera.h"



Camera::Camera(std::shared_ptr<ShaderProgram> prog) :
	program(prog),
	position(glm::vec3(0.f, 0.02f, 0.5f)),
	front(glm::vec3(0.0f, 0.0f, -1.0f)),
	world_up(glm::vec3(0.f, 1.f, 0.f)),
	pitch(0.f),
	yaw(-90.f)
{
	GLfloat ratio = static_cast<GLfloat>(Settings::ScreenWidth) / static_cast<GLfloat>(Settings::ScreenHeight);
	projection = glm::perspective(glm::radians(Settings::FieldOfView), ratio, Settings::PerspectiveNear, Settings::PerspectiveFar);

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
		position += Settings::MoveToLookDirection ? up * v : world_up * v;
		break;

	case MoveDirection::Down:
		position -= Settings::MoveToLookDirection ? up * v : world_up * v;
		break;

	case MoveDirection::Left:
		position -= right * v;
		break;

	case MoveDirection::Right:
		position += right * v;
		break;

	case MoveDirection::Forward:
		position += (Settings::MoveToLookDirection ?
			front * v :
			glm::normalize(glm::cross(world_up, right)) * v);
		break;

	case MoveDirection::Backward:
		position -= (Settings::MoveToLookDirection ?
			front * v : 
			glm::normalize(glm::cross(world_up, right)) * v);
		break;

	default:
		break;
	}
}

void Camera::look(GLfloat x, GLfloat y)
{
	yaw += x * Settings::MouseSensitivityX * (Settings::InvertMouseX ? -1 : 1);
	pitch -= y * Settings::MouseSensitivityY * (Settings::InvertMouseY ? -1 : 1);

	const auto FullAngle = 360;
	const auto UpDownLimit = 89.9f;

	while (yaw < -FullAngle)
		yaw += FullAngle;

	while (yaw > FullAngle)
		yaw -= FullAngle;

	if (pitch > UpDownLimit)
		pitch = UpDownLimit;

	if (pitch < -UpDownLimit)
		pitch = -UpDownLimit;

	update();
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
	front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, world_up));
	up = glm::normalize(glm::cross(right, front));
}
