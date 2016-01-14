#include "SpotLight.h"
#include "WineObject.h"
#include "Transform.h"

using namespace WineX;

SpotLight::SpotLight(const int index)
{
	_name = TypeHelper<SpotLight>::GetType();
	_index = index;
	_direction = { 0.0f, -1.0f, 0.0f };
	_phi = D3DXToRadian(60);
	_theta = D3DXToRadian(15);
	_falloff = 1.0f;
	_attenuation[0] = 1.0f;
	_attenuation[1] = 0.0f;
	_attenuation[2] = 0.0f;
}

SpotLight::~SpotLight()
{
	_parent->GetDevice()->LightEnable(_index, false);
}

void SpotLight::Init()
{
	_light.Type = D3DLIGHT_SPOT;
	_light.Range = _range;
	_light.Diffuse = _diffuse;
	_light.Ambient = _ambient;
	_light.Specular = _specular;
	_light.Direction = _direction;

	_light.Position = _parent->GetComponent<Transform>()->GetPosition();
	_light.Phi = _phi;
	_light.Theta = _theta;
	_light.Falloff = _falloff;
	_light.Attenuation0 = _attenuation[0];
	_light.Attenuation1 = _attenuation[1];
	_light.Attenuation2 = _attenuation[2];

	_parent->GetDevice()->SetLight(_index, &_light);
	_parent->GetDevice()->LightEnable(_index, true);
}

void SpotLight::Update()
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

	_light.Position = _parent->GetComponent<Transform>()->GetPosition();
	_light.Phi = _phi;
	_light.Theta = _theta;
	_light.Falloff = _falloff;
	_light.Attenuation0 = _attenuation[0];
	_light.Attenuation1 = _attenuation[1];
	_light.Attenuation2 = _attenuation[2];

	_parent->GetDevice()->SetLight(_index, &_light);
	_parent->GetDevice()->LightEnable(_index, true);
}

void SpotLight::SetDirection(Vector3 direction)
{
	_direction.x = direction.x;
	_direction.y = direction.y;
	_direction.z = direction.z;
}

void SpotLight::SetDirection(const float x, const float y, const float z)
{
	_direction.x = x;
	_direction.y = y;
	_direction.z = z;
}

void SpotLight::SetAttenuation(const float atten0, const float atten1, const float atten2)
{
	_attenuation[0] = atten0;
	_attenuation[1] = atten1;
	_attenuation[2] = atten2;
}

void SpotLight::SetPhi(const float phi)
{
	_phi = phi;
}

void SpotLight::SetTheta(const float theta)
{
	_theta = theta;
}

void SpotLight::SetFalloff(const float falloff)
{
	_falloff = falloff;
}