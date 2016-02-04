#pragma once

#include "BaseComponent.h"
#include "WineDefines.h"
#include "Transform.h"

namespace WineX
{
	class Font
		:public BaseComponent
	{
	private:
		std::wstring	_text;
		std::wstring	_font;
		RECT			_rc;
		int				_fontSize;

		ID3DXFont*		_d3dFont;
		ID3DXSprite*	_textSprite;
		Transform*		_transform;
		ColorRGBA		_color;

	public:
		Font(const std::wstring& text, const int fontSize, const std::wstring& font);
		virtual ~Font();

		void SetString(const std::wstring& text);
		void SetColor(ColorRGBA color);

		std::wstring& GetString() { return _text; }
		ColorRGBA GetColor() { return _color; }

		void Init() override;
		void Update() override;

	};
}