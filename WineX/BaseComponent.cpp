#include "BaseComponent.h"

using namespace WineX;

BaseComponent::BaseComponent()
	: _enable(true)
{

}

BaseComponent::~BaseComponent()
{

}

void BaseComponent::SetName(const std::string& name)
{
	_name = name;
}

void BaseComponent::SetParent(WineObject* parent)
{
	_parent = parent;
}

void BaseComponent::SetEnable(const bool enable)
{
	_enable = enable;
}