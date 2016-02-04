#include "HelloWorld.h"

using namespace WineX;

HelloWorld* HelloWorld::CreateScene()
{
	HelloWorld* scene = new (std::nothrow) HelloWorld();

	if (!scene)
	{
		return nullptr;
	}

	return scene;
}

bool HelloWorld::Init()
{
	sprite = new WineObject("SpriteTest");
	sprite->AddComponent(new Sprite(L"ImageTest.png"));
	sprite->InitComponent();
	sprite->GetComponent<Transform>()->SetPosition(0.0f, 0.0f, 0.0f);

	pan = new WineObject("Pan");
	pan->AddComponent(new XMesh(L"ChessBoard.x"));
	pan->InitComponent();
	pan->GetComponent<Transform>()->SetScale(10.0f, 10.0f, 10.0f);

	tiger = new WineObject("tiger");
	tiger->AddComponent(new XMesh(L"tiger.x"));
	tiger->InitComponent();
	tiger->GetComponent<Transform>()->SetPosition(0.0f, 1.0f, 0.0f);
	tiger->GetComponent<XMesh>()->GetMaterial()->Diffuse.a = 0.5f;

	camera = new WineObject("mainCamera");
	camera->AddComponent(new Camera());
	camera->InitComponent();
	camera->GetComponent<Transform>()->SetPosition(0.0f, 3.5f, -9.0f);
	camera->GetComponent<Camera>()->SetLook(0.0f, 1.0f, 0.0f);

	sun = new WineObject("Sun");
	sun->AddComponent(new DirLight(0));
	sun->InitComponent();
	sun->SetVisible(false);

	light = new WineObject("Light");
	light->AddComponent(new XMesh(L"Light.x"));
	light->AddComponent(new PointLight(1));
	light->InitComponent();
	light->GetComponent<PointLight>()->SetDiffuse(ColorRGBA(0.0f, 1.0f, 0.0f, 1.0f));
	light->GetComponent<PointLight>()->SetSpecular(ColorRGBA(0.0f, 1.0f, 0.0f, 1.0f));
	light->GetComponent<PointLight>()->SetAmbient(ColorRGBA(0.0f, 1.0f, 0.0f, 1.0f));
	light->GetComponent<PointLight>()->SetRange(3.0f);
	light->GetComponent<Transform>()->SetPosition(0.0f, 3.0f, 0.0f);

	info = new WineObject("info");
	info->AddComponent(
		new Font(
			L"폰트 테스트", 15, L"바다L"));
	info->InitComponent();
	info->GetComponent<Transform>()->SetPosition(10, 10);
	info->GetComponent<Font>()->SetColor(ColorRGBA(1.0f, 1.0f, 1.0f, 1.0f));

	return true;
}

void HelloWorld::Update(float dt)
{
	r += 3.0f * dt;

	light->GetComponent<Transform>()->SetPositionX(cos(r));
	light->GetComponent<Transform>()->SetPositionZ(sin(r));

	sprite->Update();
	tiger->Update();
	sun->Update();
	light->Update();
	camera->Update();
	info->Update();
	pan->Update();
}

void HelloWorld::Release()
{
	SAFE_DELETE(sprite);
	SAFE_DELETE(pan);
	SAFE_DELETE(tiger);
	SAFE_DELETE(camera);
	SAFE_DELETE(sun);
	SAFE_DELETE(light);
	SAFE_DELETE(info);
}