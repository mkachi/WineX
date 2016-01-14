#include "Transform.h"
#include "TypeHelper.h"

using namespace WineX;

Transform::Transform()
{
	_name = TypeHelper<Transform>::GetType();
}

Transform::~Transform()
{

}

void Transform::Init()
{
	_position = Vector3{ 0.0f, 0.0f, 0.0f };
	_rotate = Vector3{ 0.0f, 0.0f, 0.0f };
	_scale = Vector3{ 1.0f, 1.0f, 1.0f };
}

void Transform::Update()
{

}

void Transform::SetPosition(Vector3 position)
{
	_position.x = position.x;
	_position.y = position.y;
	_position.z = position.z;
}

void Transform::SetPosition(const float x, const float y, const float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

void Transform::SetPosition(Vector2 position)
{
	_position.x = position.x;
	_position.y = position.y;
}

void Transform::SetPosition(const float x, const float y)
{
	_position.x = x;
	_position.y = y;
}

void Transform::SetScale(Vector3 scale)
{
	_scale.x = scale.x;
	_scale.y = scale.y;
	_scale.z = scale.z;
}

void Transform::SetPositionX(const float x)
{
	_position.x = x;
}

void Transform::SetPositionY(const float y)
{
	_position.y = y;
}

void Transform::SetPositionZ(const float z)
{
	_position.z = z;
}

void Transform::SetScale(const float x, const float y, const float z)
{
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
}

void Transform::SetScale(Vector2 scale)
{
	_scale.x = scale.x;
	_scale.y = scale.y;
}

void Transform::SetScale(const float x, const float y)
{
	_scale.x = x;
	_scale.y = y;
}

void Transform::SetScaleX(const float x)
{
	_scale.x = x;
}

void Transform::SetScaleY(const float y)
{
	_scale.y = y;
}

void Transform::SetScaleZ(const float z)
{
	_scale.z = z;
}

void Transform::SetRotate(Vector3 rotate)
{
	_rotate.x = rotate.x;
	_rotate.y = rotate.y;
	_rotate.z = rotate.z;
}

void Transform::SetRotate(const float x, const float y, const float z)
{
	_rotate.x = x;
	_rotate.y = y;
	_rotate.z = z;
}

void Transform::SetRotate(Vector2 rotate)
{
	_rotate.x = rotate.x;
	_rotate.y = rotate.y;
}

void Transform::SetRotate(const float x, const float y)
{
	_rotate.x = x;
	_rotate.y = y;
}

void Transform::SetRotateX(const float x)
{
	_rotate.x = x;
}

void Transform::SetRotateY(const float y)
{
	_rotate.y = y;
}

void Transform::SetRotateZ(const float z)
{
	_rotate.z = z;
}