#pragma once
#include "Transform.h"
#include "XMesh.h"
#include "DirLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Camera.h"
#include "Font.h"

using namespace WineX;

template<typename T>
class TypeHelper;

#define TYPE_HELPER_DEFINE_TYPES(type, token) \
template<> \
class TypeHelper<type> \
{ \
public: \
	static constexpr const char* GetType() { return token; } \
}; \

TYPE_HELPER_DEFINE_TYPES(int, "int");
TYPE_HELPER_DEFINE_TYPES(short, "short");
TYPE_HELPER_DEFINE_TYPES(long, "long");
TYPE_HELPER_DEFINE_TYPES(char, "char");
TYPE_HELPER_DEFINE_TYPES(void, "void");
TYPE_HELPER_DEFINE_TYPES(unsigned int, "unsigned int");
TYPE_HELPER_DEFINE_TYPES(unsigned short, "unsigned short");
TYPE_HELPER_DEFINE_TYPES(unsigned long, "unsigned long");
TYPE_HELPER_DEFINE_TYPES(unsigned char, "unsigned char");
TYPE_HELPER_DEFINE_TYPES(Transform, "Transform");
TYPE_HELPER_DEFINE_TYPES(XMesh, "XMesh");
TYPE_HELPER_DEFINE_TYPES(DirLight, "DirLight");
TYPE_HELPER_DEFINE_TYPES(PointLight, "PointLight");
TYPE_HELPER_DEFINE_TYPES(SpotLight, "SpotLight");
TYPE_HELPER_DEFINE_TYPES(Camera, "Camera");
TYPE_HELPER_DEFINE_TYPES(Font, "Font");