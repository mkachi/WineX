#include "D3DApp.h"

using namespace WineX;

D3DApp::D3DApp()
{

}

D3DApp::~D3DApp()
{
	SAFE_RELEASE(_device);
	SAFE_RELEASE(_d3d);
}

bool D3DApp::Init(HWND wnd)
{
	if (NULL == (_d3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24X8;

	if (FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &_device)))
	{
		return false;
	}

	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	_device->SetRenderState(D3DRS_ZENABLE, true);
	_device->SetRenderState(D3DRS_LIGHTING, true);
	_device->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	_device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	_device->SetRenderState(D3DRS_SPECULARENABLE, true);

	_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

	_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	return true;
}