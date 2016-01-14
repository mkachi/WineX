#include "Time.h"
#include <Windows.h>

using namespace WineX;

Time::Time()
	:_startTime(0.0f)
	, _deltaTime(0.0f)
	, _curTime(0.0f)
{

}

Time::~Time()
{

}

void Time::Run()
{
	_curTime = GetTickCount();

	if (_startTime == 0.0f)
	{
		_startTime = _curTime;
	}
	_deltaTime = (_curTime - _startTime) / 1000.0f;
	_startTime = _curTime;
}