#pragma once

#include <d3dx9.h>
#include "WineDefines.h"

namespace WineX
{
	class D3DApp
	{
	private:
		IDirect3D9* _d3d = nullptr;
		IDirect3DDevice9* _device = nullptr;

	public:
		D3DApp();
		~D3DApp();

		bool Init(HWND wnd);
		IDirect3DDevice9* GetDevice() { return _device; }

	};
}