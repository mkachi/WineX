#pragma once

#include "BaseComponent.h"
#include "WineDefines.h"

namespace WineX
{
	class Transform
		:public BaseComponent
	{
	private:
		Vector3		_position;
		Vector3		_scale;
		Vector3		_rotate;

	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;

		void SetPosition(Vector3 position);
		void SetPosition(const float x, const float y, const float z);
		Vector3 GetPosition() { return _position; }

		void SetPosition(Vector2 position);
		void SetPosition(const float x, const float y);

		void SetPositionX(const float x);
		void SetPositionY(const float y);
		void SetPositionZ(const float z);

		void SetScale(Vector3 scale);
		void SetScale(const float x, const float y, const float z);
		const Vector3& GetScale() { return _scale; }

		void SetScale(Vector2 scale);
		void SetScale(const float x, const float y);

		void SetScaleX(const float x);
		void SetScaleY(const float y);
		void SetScaleZ(const float z);

		void SetRotate(Vector3 rotate);
		void SetRotate(const float x, const float y, const float z);
		const Vector3& GetRotate() { return _rotate; }

		void SetRotate(Vector2 rotate);
		void SetRotate(const float x, const float y);

		void SetRotateX(const float x);
		void SetRotateY(const float y);
		void SetRotateZ(const float z);

	};
}