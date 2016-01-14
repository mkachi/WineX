#pragma once

#include "Scene.h"

namespace WineX
{
	class Director
	{
	private:
		bool _end = false;
		bool _pause;

	public:
		Director();
		~Director();

		static Director* getInstance();

		const bool isEnd() { return _end; }
		void StopApplication();

		const bool isPause() { return _pause; }
		void pause();
		void resume();

		void replaceScene(Scene* scene);
		void Destroy();

	};
}