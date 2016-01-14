#pragma once

#include "WinApp.h"
#include "D3DApp.h"
#include "WineDefines.h"
#include "Scene.h"

namespace WineX
{
	class Application
	{
	private:
		WinApp* _winApp = nullptr;
		D3DApp* _d3dApp = nullptr;
		IDirect3DDevice9* _device = nullptr;
		Scene* _curScene;

	public:
		Application();
		~Application();

		static Application* Excute();

		IDirect3DDevice9* getDevice() { return _device; }

		bool Initialize(const std::wstring& title, const int width, const int height);
		void Run();
		void Destroy();

		void SetStartScene(Scene * scene);
		Scene* GetCurScene() { return _curScene; }
		void ReplaceScene(Scene * scene);

	};
}