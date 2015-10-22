#include "PointLight.h"



PointLight::PointLight(std::shared_ptr<ShaderProgram> prog, glm::vec3 col, glm::vec3 pos) :
	Light(prog, col, pos)
{
	setFactors(Settings::PointLightConstantFactor, Settings::PointLightLinearFactor, Settings::PointLightQuadraticFactor);
}


PointLight::~PointLight()
{
}
