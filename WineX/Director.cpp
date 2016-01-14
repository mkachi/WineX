#include "Director.h"
#include "Application.h"

using namespace WineX;

Director* _instance = nullptr;

Director::Director()
{

}

Director::~Director()
{

}

Director* Director::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Director();
	}

	return _instance;
}

void Director::StopApplication()
{
	_end = true;
}

void Director::pause()
{
	_pause = true;
}

void Director::resume()
{
	_pause = false;
}

void Director::replaceScene(Scene* scene)
{
	Application::Excute()->ReplaceScene(scene);
}

void Director::Destroy()
{
	SAFE_DELETE(_instance);
}