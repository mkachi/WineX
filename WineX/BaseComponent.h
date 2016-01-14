#pragma once

#include <string>

namespace WineX
{
	class WineObject;
	class BaseComponent
	{
	protected:
		std::string		_name;
		WineObject*		_parent;

	public:
		BaseComponent();
		virtual ~BaseComponent();

		virtual void Init() = 0;
		virtual void Update() = 0;

		virtual void SetName(const std::string& name);
		std::string& GetName() { return _name; }

		virtual void SetParent(WineObject* parent);
		WineObject& GetParent() { return *_parent; }

	};
}