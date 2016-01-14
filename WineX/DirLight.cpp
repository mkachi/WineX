#include "DirLight.h"
#include "WineObject.h"

using namespace WineX;

DirLight::DirLight(const int index)
{
	_name = TypeHelper<DirLight>::GetType();
	_index = index;
	_direction = { -1.0f, 1.0f, 1.0f };
}

DirLight::~DirLight()
{
	_parent->GetDevice()->LightEnable(_index, false);
}

void DirLight::Init()
{
	_light.Type = D3DLIGHT_DIRECTIONAL;
	_light.Range = _range;
	_light.Diffuse = _diffuse;
	_light.Ambient = _ambient;
	_light.Specular = _specular;
	_light.Direction = _direction;

	_parent->GetDevice()->SetLight(_index, &_light);
	_parent->GetDevice()->LightEnable(_index, true);
}

void DirLight::Update()
{
	if (_parent->IsVisible() == false)
	{
		_parent->GetDevice()->LightEnable(_index, false);
		return;
	}

	_light.Range = _range;
	_light.Diffuse = _diffuse;
	_light.Ambient = _ambient;
	_light.Specular = _specular;
	_light.Direction = _direction;
	_parent->GetDevice()->SetLight(_index, &_light);
	_parent->GetDevice()->LightEnable(_index, true);
}

void DirLight::SetDirection(Vector3 direction)
{
	_direction.x = direction.x;
	_direction.y = direction.y;
	_direction.z = direction.z;
}

void DirLight::SetDirection(const float x, const float y, const float z)
{
	_direction.x = x;
	_direction.y = y;
	_direction.z = z;
}