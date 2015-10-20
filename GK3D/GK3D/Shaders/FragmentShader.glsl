#version 330 core

in vec3 normal;
in vec3 fragment_position;

out vec4 color;

uniform vec4 model_color;
uniform float ambient_strength;

void main()
{
	// TODO: from sources
	vec3 light_color = vec3(1.0f, 1.0f, 1.0f);

	// Ambient
	vec4 ambient = vec4(light_color * ambient_strength, 1.0f);

	// Diffuse
	vec3 normalized_normal = normalize(normal);
	// TODO

	// Specular
	// TODO

	// Output
	color = model_color * ambient;
}