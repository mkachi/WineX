#pragma once

#include "WineX.h"

class HelloWorld
	: public WineX::Scene
{
public:
	WineX::WineObject* sprite;
	WineX::WineObject* pan;
	WineX::WineObject* tiger;
	WineX::WineObject* camera;
	WineX::WineObject* sun;
	WineX::WineObject* light;
	WineX::WineObject* info;

	float r = 0.0f;

	CREATE_SCENE(HelloWorld)
};