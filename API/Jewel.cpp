#include "Jewel.h"
#include"CSceneManager.h"
#include"CScene.h"
#include"ResourceManager.h"
#include"CTexture.h"
#include"Collider.h"
#include"GFunc.h"

void Jewel::Init(float px, float py, float sx, float sy, wstring _name)
{
	CObject::Init(px, py, sx, sy,_name);
	tex = ResourceManager::getInstance()->Load(L"WaterDia", L"texture\\WaterDia.bmp");
	CreateCollider();

	m_collider->SetOffSetPos(Vector2(0.f, 0.f));
	m_collider->SetSize(Vector2(25.f, 25.f));
}

void Jewel::Update()
{
}

void Jewel::Render(HDC hdc)
{
	int hWidth = (int)tex->Width();
	int hHeight = (int)tex->Height();

	Vector2  hPos = Camera::getInstance()->GetRenderPos(m_position);
	ComponentRender(hdc);
	TransparentBlt(hdc, int(hPos.x - (float)(hWidth / 2)), int(hPos.y - (float)(hHeight / 2)), hWidth, hHeight, tex->GetUseDC(), 0, 0, hWidth, hHeight, RGB(255, 255, 255));
}

void Jewel::Release()
{
	if (tex != nullptr)
		delete tex;
	CObject::Release();
}

void Jewel::OnCollision(Collider* other)
{
}

void Jewel::OnCollisionEnter(Collider* other)
{
	CObject* otherObj = other->GetObj();

	if (otherObj->Name() == L"Player") {
		Destroy(this);
	}
}

void Jewel::OnCollisionExit(Collider* other)
{
}
