#include "Application.h"
#include "HelloWorld.h"
#include <crtdbg.h>

using namespace WineX;

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	//	_CrtSetBreakAlloc(332);

	UNREFERENCED_PARAMETER(hInst);
	if (!(Application::Excute()->Initialize(L"WineX", 1280, 800)))
	{
		return -1;
	}
	Application::Excute()->SetStartScene(HelloWorld::CreateScene());
	Application::Excute()->Run();
	Application::Excute()->Destroy();

	return 0;
}