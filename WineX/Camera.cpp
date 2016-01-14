#include "Camera.h"
#include "WineObject.h"
#include "Transform.h"

using namespace WineX;

Camera::Camera()
{
	_name = TypeHelper<Camera>::GetType();
}

Camera::~Camera()
{

}

void Camera::Init()
{
	_transform = _parent->GetComponent<Transform>();
	_upVec = { 0.0f, 1.0f, 0.0f };
}

void Camera::Update()
{
	if (_parent->IsVisible() == false)
	{
		return;
	}

	D3DXMatrixLookAtLH(&_view,
		&_transform->GetPosition(),
		&_look,
		&_upVec);

	D3DXMatrixIdentity(&_world);

	D3DXMatrixRotationX(&_world,
		_transform->GetRotate().x);

	D3DXMatrixRotationY(&_world,
		_transform->GetRotate().y);

	D3DXMatrixRotationZ(&_world,
		_transform->GetRotate().z);

	D3DXMatrixMultiply(&_view, &_view, &_world);

	_parent->GetDevice()->SetTransform(D3DTS_VIEW, &_view);

	D3DXMatrixPerspectiveFovLH(&_projection, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	_parent->GetDevice()->SetTransform(D3DTS_PROJECTION, &_projection);
}

void Camera::SetLook(Vector3 position)
{
	_look.x = position.x;
	_look.y = position.y;
	_look.z = position.z;
}

void Camera::SetLook(const float x, const float y, const float z)
{
	_look.x = x;
	_look.y = y;
	_look.z = z;
}

void Camera::SetLookX(const float x)
{
	_look.x = x;
}

void Camera::SetLookY(const float y)
{
	_look.y = y;
}

void Camera::SetLookZ(const float z)
{
	_look.z = z;
}