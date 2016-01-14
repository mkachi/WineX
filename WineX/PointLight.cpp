#include "PointLight.h"
#include "WineObject.h"
#include "Transform.h"

using namespace WineX;

PointLight::PointLight(const int index)
{
	_name = TypeHelper<PointLight>::GetType();
	_index = index;
	_attenuation[0] = 1.0f;
	_attenuation[1] = 0.0f;
	_attenuation[2] = 0.0f;
}

PointLight::~PointLight()
{
	_parent->GetDevice()->LightEnable(_index, false);
}

void PointLight::Init()
{
	_light.Type = D3DLIGHT_POINT;
	_light.Range = _range;
	_light.Diffuse = _diffuse;
	_light.Ambient = _ambient;
	_light.Specular = _specular;
	_light.Position = _parent->GetComponent<Transform>()->GetPosition();
	_light.Attenuation0 = _attenuation[0];
	_light.Attenuation1 = _attenuation[1];
	_light.Attenuation2 = _attenuation[2];

	_parent->GetDevice()->SetLight(_index, &_light);
	_parent->GetDevice()->LightEnable(_index, true);
}

void PointLight::Update()
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
	_light.Position = _parent->GetComponent<Transform>()->GetPosition();
	_light.Attenuation0 = _attenuation[0];
	_light.Attenuation1 = _attenuation[1];
	_light.Attenuation2 = _attenuation[2];

	_parent->GetDevice()->SetLight(_index, &_light);
	_parent->GetDevice()->LightEnable(_index, true);
}

void PointLight::SetAttenuation(const float atten0, const float atten1, const float atten2)
{
	_attenuation[0] = atten0;
	_attenuation[1] = atten1;
	_attenuation[2] = atten2;
}