#pragma once

#include "BaseComponent.h"
#include "WineDefines.h"

namespace WineX
{
	class XMesh
		:public BaseComponent
	{
	private:
		std::wstring		_filename;
		LPD3DXMESH			_mesh = nullptr;
		D3DMATERIAL9*		_Material = nullptr;
		LPDIRECT3DTEXTURE9* _Texture = nullptr;
		DWORD				_MaterialsNum = 0L;

		Matrix44	_meshMatrix;
		Matrix44	_positionMatrix;
		Matrix44	_scaleMatrix;
		Matrix44	_rotateMatrix[3];

		class Transform*	_transform;

	public:
		XMesh(const std::wstring& filename);
		~XMesh();

		void SetMaterial(D3DMATERIAL9* material);
		D3DMATERIAL9* GetMaterial() { return _Material; }

		void Init() override;
		void Update() override;

	};
}