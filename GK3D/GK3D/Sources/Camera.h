#pragma once

#include "Includes.h"
#include "LookDirection.h"
#include "MoveDirection.h"

class Camera
{
public:
	Camera();
	~Camera();

	void move(MoveDirection direction);
};

