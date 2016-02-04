#pragma once

#include "BaseComponent.h"
#include "Transform.h"
#include "WineDefines.h"

namespace WineX
{
	class Camera
		:public BaseComponent
	{
	private:
		Matrix44	_world;
		Matrix44	_view;
		Matrix44	_projection;
		Vector3		_look;
		Vector3		_upVec;

		Transform*	_transform;

	public:
		Camera();
		virtual ~Camera();

		void SetLook(Vector3 look);
		void SetLook(const float x, const float y, const float z);
		void SetLookX(const float x);
		void SetLookY(const float y);
		void SetLookZ(const float z);
		const Vector3& GetLook() { return _look; }

		void Init() override;
		void Update() override;

	};
}