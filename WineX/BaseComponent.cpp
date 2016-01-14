#include "BaseComponent.h"

using namespace WineX;

BaseComponent::BaseComponent()
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