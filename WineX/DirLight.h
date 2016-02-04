#pragma once

#include "BaseComponent.h"
#include "Light.h"

namespace WineX
{
	class DirLight
		:public BaseComponent
		, public Light
	{
	private:
		Vector3 _direction;

	public:
		DirLight(const int index);
		virtual ~DirLight();

		void Init() override;
		void Update() override;

		void SetDirection(Vector3 direction);
		void SetDirection(const float x, const float y, const float z);

		const Vector3& getDirection() { return _direction; }

	};
}