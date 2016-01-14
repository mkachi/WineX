#include "XMesh.h"
#include "WineObject.h"
#include <d3dx9math.h>

using namespace WineX;

XMesh::XMesh(const std::wstring& filename)
	:_filename(filename)
{
	_name = TypeHelper<XMesh>::GetType();
}

XMesh::~XMesh()
{
	delete[] _Material;

	if (_Texture)
	{
		for (DWORD i = 0; i < _MaterialsNum; i++)
		{
			SAFE_RELEASE(_Texture[i]);
		}
		delete[] _Texture;
	}
	SAFE_RELEASE(_mesh);
}

void XMesh::Init()
{
	_transform = _parent->GetComponent<Transform>();

	LPD3DXBUFFER buffer;
	D3DXLoadMeshFromX(_filename.c_str(), D3DXMESH_SYSTEMMEM, _parent->GetDevice(), NULL, &buffer, NULL, &_MaterialsNum, &_mesh);

	D3DXMATERIAL* d3dMaterials = (D3DXMATERIAL*)buffer->GetBufferPointer();
	_Material = new _D3DMATERIAL9[_MaterialsNum];
	_Texture = new LPDIRECT3DTEXTURE9[_MaterialsNum];

	for (DWORD i = 0; i < _MaterialsNum; i++)
	{
		_Material[i] = d3dMaterials[i].MatD3D;
		_Material[i].Ambient = _Material[i].Diffuse;
		_Texture[i] = NULL;

		if (d3dMaterials[i].pTextureFilename != NULL &&
			lstrlenA(d3dMaterials[i].pTextureFilename) > 0)
		{
			D3DXCreateTextureFromFileA(_parent->GetDevice(), d3dMaterials[i].pTextureFilename, &_Texture[i]);
		}
	}

	SAFE_RELEASE(buffer);
}

void XMesh::Update()
{
	D3DXMatrixIdentity(&_meshMatrix);

	D3DXMatrixScaling(&_scaleMatrix,
		_transform->GetScale().x,
		_transform->GetScale().y,
		_transform->GetScale().z);

	D3DXMatrixRotationX(&_rotateMatrix[0],
		_transform->GetRotate().x);

	D3DXMatrixRotationY(&_rotateMatrix[1],
		_transform->GetRotate().y);

	D3DXMatrixRotationZ(&_rotateMatrix[2],
		_transform->GetRotate().z);

	D3DXMatrixTranslation(&_positionMatrix,
		_transform->GetPosition().x,
		_transform->GetPosition().y,
		_transform->GetPosition().z);

	D3DXMatrixMultiply(&_meshMatrix, &_meshMatrix, &_scaleMatrix);

	for (int i = 0; i < 3; i++)
	{
		D3DXMatrixMultiply(&_meshMatrix, &_meshMatrix, &_rotateMatrix[i]);
	}
	D3DXMatrixMultiply(&_meshMatrix, &_meshMatrix, &_positionMatrix);

	_parent->GetDevice()->SetTransform(D3DTS_WORLD, &_meshMatrix);

	if (_parent->IsVisible() == false)
	{
		return;
	}

	for (DWORD i = 0; i < _MaterialsNum; i++)
	{
		_parent->GetDevice()->SetMaterial(&_Material[i]);
		_parent->GetDevice()->SetTexture(0, _Texture[i]);

		_mesh->DrawSubset(i);
	}
}

void XMesh::SetMaterial(D3DMATERIAL9* material)
{
	_Material = material;
}