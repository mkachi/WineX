#pragma once

namespace WineX
{
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		virtual bool Init() = 0;
		virtual void Update(float dt) = 0;
		virtual void Release() = 0;

	};
}