#include "Application.h"
#include "Director.h"

using namespace WineX;

Application* _instance = nullptr;

Application::Application()
{

}

Application::~Application()
{

}

Application* Application::Excute()
{
	if (_instance == nullptr)
	{
		_instance = new Application();
	}

	return _instance;
}

bool Application::Initialize(const std::wstring& title, const int width, const int height)
{
	_winApp = new WinApp();
	_d3dApp = new D3DApp();

	if (_winApp != nullptr &&
		_d3dApp != nullptr)
	{
		if (!_winApp->Init(title, width, height))
		{
			return false;
		}

		if (!_d3dApp->Init(_winApp->GetWnd()))
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	_device = _d3dApp->GetDevice();

	return true;
}

void Application::Run()
{
	_winApp->Loop(_d3dApp->GetDevice());
}

void Application::Destroy()
{
	Director::getInstance()->Destroy();
	SAFE_DELETE(_d3dApp);
	SAFE_DELETE(_winApp);
	SAFE_DELETE(_instance);
}

void Application::SetStartScene(Scene* scene)
{
	_curScene = scene;
}

void Application::ReplaceScene(Scene* scene)
{
	_curScene->Release();
	SAFE_DELETE(_curScene);
	_curScene = scene;
	_curScene->Init();
}