#include "Font.h"
#include "WineObject.h"

using namespace WineX;

Font::Font(const std::wstring& text, const int fontSize, const std::wstring& font)
	:_text(text)
	, _font(font)
	, _fontSize(fontSize)
	, _color(ColorRGBA(0, 0, 0, 1.0f))
{
	_name = TypeHelper<Font>::GetType();
}

Font::~Font()
{
	SAFE_RELEASE(_d3dFont);
	SAFE_RELEASE(_textSprite);
}

void Font::SetString(const std::wstring& text)
{
	_text = text;
}

void Font::SetColor(ColorRGBA color)
{
	_color = color;
}

void Font::Init()
{
	_transform = _parent->GetComponent<Transform>();
	D3DXCreateSprite(_parent->GetDevice(), &_textSprite);
	// FW_NORMAL 이 설정을 변경 할 수 있는 함수 제작 필요
	D3DXCreateFont(_parent->GetDevice(), _fontSize, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _font.c_str(), &_d3dFont);
	SetRect(&_rc, _transform->GetPosition().x, _transform->GetPosition().y, 0, 0);
}

void Font::Update()
{
	SetRect(&_rc, _transform->GetPosition().x, _transform->GetPosition().y, 0, 0);
	_textSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	_d3dFont->DrawTextW(_textSprite, _text.c_str(), -1, &_rc, DT_NOCLIP, _color);
	_textSprite->End();
}