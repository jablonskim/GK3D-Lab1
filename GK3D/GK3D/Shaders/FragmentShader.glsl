#version 330 core

out vec4 color;

uniform vec4 model_color;

void main()
{
	color = model_color;
}