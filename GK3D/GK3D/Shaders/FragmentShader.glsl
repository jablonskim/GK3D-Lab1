#version 330 core

out vec4 color;

uniform vec4 model_color;
uniform float ambient_strength;

void main()
{
	// TODO: from sources
	vec3 light_color = vec3(1.0f, 1.0f, 1.0f);

	vec4 ambient = vec4(light_color * ambient_strength, 1.0f);

	color = model_color * ambient;
}