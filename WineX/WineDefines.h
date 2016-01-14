#pragma once
#include <d3dx9.h>
#include <cstdio>

#define CREATE_SCENE(_scene_) \
	static _scene_* CreateScene(); \
	bool Init() override; \
	void Update(float dt) override; \
	void Release() override; \

typedef D3DXVECTOR3		Vector3;
typedef D3DXVECTOR2		Vector2;
typedef D3DXMATRIX		Matrix44;
typedef D3DLIGHT9		DXLight;
typedef D3DXCOLOR		ColorRGBA;

template<typename T>
inline void SAFE_DELETE(T*& _obj_)
{
	if (_obj_ != nullptr)
	{
		delete _obj_;
		_obj_ = nullptr;
	}
}

template<typename T>
inline void SAFE_RELEASE(T*& _obj_)
{
	if (_obj_ != nullptr)
	{
		_obj_->Release();
		_obj_ = nullptr;
	}
}

inline void WXLog(const wchar_t* log, ...)
{
	va_list args;
	wchar_t str[2048];
	va_start(args, log);
	vswprintf(str, log, args);
	va_end(args);
	OutputDebugStringW(str);
}