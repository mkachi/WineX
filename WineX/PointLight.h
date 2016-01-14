#pragma once

#include "BaseComponent.h"
#include "Light.h"

namespace WineX
{
	class PointLight
		:public BaseComponent
		, public Light
	{
	private:
		float	_attenuation[3];

	public:
		PointLight(const int index);
		~PointLight();

		void Init() override;
		void Update() override;

		void SetDirection(Vector3 direction);
		void SetDirection(const float x, const float y, const float z);

		void SetAttenuation(const float atten0, const float atten1, const float atten2);

		const float GetAtten0() { return _attenuation[0]; }
		const float GetAtten1() { return _attenuation[1]; }
		const float GetAtten2() { return _attenuation[2]; }

	};
}