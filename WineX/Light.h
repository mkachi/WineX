#pragma once

#include "WineDefines.h"

namespace WineX
{
	class Light
	{
	protected:
		DXLight		_light;
		ColorRGBA	_diffuse;
		ColorRGBA	_ambient;
		ColorRGBA	_specular;
		float		_range;
		int			_index;

	public:
		Light();
		virtual ~Light();

		virtual void SetDiffuse(ColorRGBA diffuse);
		virtual const ColorRGBA GetDiffuse() { return _diffuse; }

		virtual void SetAmbient(ColorRGBA ambient);
		virtual const ColorRGBA GetAmbient() { return _ambient; }

		virtual void SetSpecular(ColorRGBA specular);
		virtual const ColorRGBA GetSpecular() { return _specular; }

		virtual void SetRange(const float range);
		virtual const float GetRange() { return _range; }

	};
}