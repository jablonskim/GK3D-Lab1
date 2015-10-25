#include "PointLight.h"

PointLight::PointLight(std::shared_ptr<ShaderProgram> prog, glm::vec3 col, glm::vec3 pos) :
	Light(prog, col, pos),
	is_broken(false)
{
	setFactors(Settings::PointLightConstantFactor, Settings::PointLightLinearFactor, Settings::PointLightQuadraticFactor);
}

PointLight::~PointLight()
{
}

void PointLight::use()
{
	if (is_broken)
		simulateBroken();

	Light::use();
}

void PointLight::setBroken(bool broken)
{
	is_broken = broken;
}

const char * PointLight::getLightArrayLocName()
{
	return Settings::ShaderPointLightsArrayLocationName;
}

int PointLight::getId()
{
	static int sid = 0;
	return sid++;
}

void PointLight::simulateBroken()
{
	// TODO
}
