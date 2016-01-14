#pragma once

#include <Windows.h>
#include <string>
#include <d3dx9.h>
#include "Time.h"

namespace WineX
{
	class WinApp
	{
	private:
		std::wstring _title;
		WNDCLASSEX _wcx;
		HWND _wnd;
		Time _timer;

	public:
		WinApp();
		~WinApp();

		bool Init(const std::wstring& title, const int width, const int height);
		void Loop(IDirect3DDevice9* device);

		std::wstring& GetTitle() { return _title; }
		HWND GetWnd() { return _wnd; }
		HINSTANCE GetInstance() { return _wcx.hInstance; }

	};
}