#include "Sprite.h"
#include "WineObject.h"
#include "Transform.h"
#include "TypeHelper.h"

using namespace WineX;

Sprite::Sprite(const std::wstring & filename)
{
	_filename = filename;
	_name = TypeHelper<Sprite>::GetType();
}

Sprite::~Sprite()
{
	SAFE_RELEASE(_texture);
	SAFE_RELEASE(_sprite);
}

void Sprite::Init()
{
	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(_filename.c_str(), &info);
	D3DXCreateSprite(_parent->GetDevice(), &_sprite);
	D3DXCreateTextureFromFileEx(_parent->GetDevice(), _filename.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 1, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT,
		NULL, NULL, NULL, &_texture);
	_transform = _parent->GetTransform();
}

void Sprite::Update()
{
	_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	_sprite->Draw(_texture, nullptr, nullptr, &D3DXVECTOR3(_transform->GetPosition().x, _transform->GetPosition().y, 0), 0xffffffff);
	_sprite->End();
}

void Sprite::SetTexture(const std::wstring & filename)
{
	_filename = filename;

	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(_filename.c_str(), &info);
	D3DXCreateTextureFromFileEx(_parent->GetDevice(), _filename.c_str(), info.Width, info.Height, 0, 1, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT,
		NULL, NULL, NULL, &_texture);
}
