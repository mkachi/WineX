#pragma once

#include "BaseComponent.h"
#include "WineDefines.h"

namespace WineX
{
	class Sprite
		: public BaseComponent
	{
	private:
		std::wstring		_filename;
		ID3DXSprite*		_sprite = nullptr;
		IDirect3DTexture9*	_texture = nullptr;
		class Transform*	_transform = nullptr;
		ColorRGBA			_alpha;

	public:
		Sprite() = delete;
		Sprite(const std::wstring& filename);
		virtual ~Sprite();

		void Init() override;
		void Update() override;

		void SetTexture(const std::wstring& filename);

	};
}