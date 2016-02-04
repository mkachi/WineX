#include "WineObject.h"
#include "BaseComponent.h"
#include "Application.h"
#include "Transform.h"

using namespace WineX;

typedef std::pair<std::string, BaseComponent*> Pair;

WineObject::WineObject(const std::string& name)
	:_name(name)
{
	_device = Application::Excute()->getDevice();
	AddComponent(new Transform());
	_transform = GetComponent<Transform>();
}

WineObject::~WineObject()
{
	if (_components.empty() != true)
	{
		for (auto& C : _components)
		{
			SAFE_DELETE(C.second);
		}
	}
}

void WineObject::SetName(const std::string& name)
{
	_name = name;
}

void WineObject::SetTag(const std::string& tag)
{
	_tag = tag;
}

void WineObject::SetVisible(const bool visible)
{
	_isVisible = visible;
}

void WineObject::InitComponent()
{
	if (_components.empty() != true)
	{
		for (auto& C : _components)
		{
			C.second->Init();
		}
	}
}

void WineObject::AddComponent(BaseComponent* component)
{
	component->SetParent(this);
	_components.insert(Pair(component->GetName(), component));
}

BaseComponent* WineObject::GetComponentToName(const std::string & name)
{
	if (_components.empty())
	{
		return nullptr;
	}
	BaseComponent* result = _components.find(name)->second;
	return result;
}

void WineObject::Update()
{
	if (_components.empty() != true)
	{
		for (auto& C : _components)
		{
			if (C.second->IsEnable())
			{
				C.second->Update();
			}
		}
	}
}