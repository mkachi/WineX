#include "WinApp.h"
#include "Application.h"
#include "Director.h"

using namespace WineX;

WinApp::WinApp()
{

}

WinApp::~WinApp()
{

}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool WinApp::Init(const std::wstring& title, const int width, const int height)
{
	_title = title;
	_wcx =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		_title.c_str(), NULL
	};
	_wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassEx(&_wcx);

	_wnd = CreateWindowEx(NULL, _title.c_str(), _title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, _wcx.hInstance, NULL);

	return true;
}

void WinApp::Loop(IDirect3DDevice9* device)
{
	ShowWindow(_wnd, SW_SHOWDEFAULT);
	UpdateWindow(_wnd);

	Application::Excute()->GetCurScene()->Init();
	Director* director = Director::getInstance();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (director->isEnd() == true)
		{
			break;
		}

		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			_timer.Run();
			device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(48, 75, 144), 1.0f, 0);
			device->BeginScene();

			if (director->isPause() == true)
			{
				Application::Excute()->GetCurScene()->Update(1.0f);
			}
			else
			{
				Application::Excute()->GetCurScene()->Update(_timer.GetDeltaTime());
			}

			device->EndScene();
			device->Present(NULL, NULL, NULL, NULL);
		}
	}
}