#include "Light.h"

using namespace WineX;

Light::Light()
	:_range(1000.0f)
	, _index(-1)
{
	_diffuse.r = _ambient.r = _specular.r = 1.0f;
	_diffuse.g = _ambient.g = _specular.g = 1.0f;
	_diffuse.b = _ambient.b = _specular.b = 1.0f;
	_diffuse.a = _ambient.a = _specular.a = 1.0f;
}

Light::~Light()
{

}

void Light::SetDiffuse(ColorRGBA diffuse)
{
	_diffuse = diffuse;
}

void Light::SetAmbient(ColorRGBA Ambient)
{
	_ambient = Ambient;
}

void Light::SetSpecular(ColorRGBA Specular)
{
	_specular = Specular;
}

void Light::SetRange(float range)
{
	_range = range;
}