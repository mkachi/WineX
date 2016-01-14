#pragma once

#include <string>
#include <map>
#include "WineDefines.h"
#include "TypeHelper.h"

namespace WineX
{
	class BaseComponent;
	class WineObject
	{
	private:
		std::string		_name;
		std::string		_tag;
		bool			_isVisible = true;
		IDirect3DDevice9* _device;
		std::multimap<std::string, BaseComponent*> _components;
		Transform* _transform;

	public:
		WineObject(const std::string& name);
		virtual ~WineObject();

		Transform* GetTransform() { return _transform; }

		const std::string& getName() { return _name; }
		const std::string& getTag() { return _tag; }

		void SetName(const std::string& name);
		void SetTag(const std::string& tag);

		void SetVisible(const bool visible);
		const bool IsVisible() { return _isVisible; }

		IDirect3DDevice9* GetDevice() { return _device; }

		void InitComponent();

		void AddComponent(BaseComponent* component);
		
		BaseComponent* GetComponentToName(const std::string& name);

		template<typename T>
		T* GetComponent()
		{
			std::string key = TypeHelper<T>::GetType();
			return static_cast<T*>(GetComponentToName(key));
		}

		void Update();

	};
}