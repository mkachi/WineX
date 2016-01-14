#pragma once

namespace WineX
{
	class Time
	{
	private:
		float _startTime;
		float _curTime;
		float _deltaTime;

	public:
		Time();
		~Time();

		void Run();
		const float GetDeltaTime() { return _deltaTime; }

	};
}