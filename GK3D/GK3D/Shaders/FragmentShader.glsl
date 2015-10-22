#version 330 core

#define POINT_LIGHTS 2
#define SPOT_LIGHTS 1

struct PointLight
{
	vec3 position;
	vec3 color;
	
	float constant_factor;
	float linear_factor;
	float quadratic_factor;
};

struct SpotLight
{
	vec3 position;
	vec3 color;
	vec3 direction;

	float inner_cut_angle;
	float outer_cut_angle;
};

in vec3 normal;
in vec3 fragment_position;

out vec4 color;

uniform vec4 model_color;
uniform float ambient_strength;
uniform float specular_strength;
uniform int specular_shininess;
uniform vec3 camera_position;

uniform PointLight point_lights[POINT_LIGHTS];
uniform SpotLight spot_lights[SPOT_LIGHTS];

vec3 calculate_spotlight(SpotLight light, vec3 model_normal, vec3 view_direction)
{
	vec3 light_direction = normalize(light.position - fragment_position);

	float theta = dot(light.direction, normalize(-light_direction));
	float eps = light.inner_cut_angle - light.outer_cut_angle;
	float intensity = clamp((theta - light.outer_cut_angle) / eps, 0.0f, 1.0f);

	float diffuse = max(dot(model_normal, light_direction), 0.0f);

	vec3 reflect_direction = reflect(-light_direction, model_normal);
	float specular = specular_strength * pow(max(dot(view_direction, reflect_direction), 0.0f), specular_shininess);

	return light.color * ((specular + diffuse) * intensity);
}

void main()
{
	// TODO: from sources
	vec3 ambient_light_color = vec3(1.0f, 1.0f, 1.0f);

	vec3 normalized_normal = normalize(normal);
	vec3 view_direction = normalize(camera_position - fragment_position);

	// Ambient
	vec3 light_result = ambient_light_color * ambient_strength;

	// Spotlights
	for(int i = 0; i < SPOT_LIGHTS; ++i)
		light_result += calculate_spotlight(spot_lights[i], normalized_normal, view_direction);

	// Output
	color = model_color * vec4(light_result, 1.0f);
}