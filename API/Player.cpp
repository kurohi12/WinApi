#include "Player.h"
#include"KeyManager.h"
#include"Misille.h"
#include"CSceneManager.h"
#include"CScene.h"
#include"ResourceManager.h"
#include"CTexture.h"
#include"Collider.h"

void Player::Init(float px, float py, float sx, float sy)
{
	CObject::Init(px, py, sx, sy);
	headTex = ResourceManager::getInstance()->Load(L"WaterGirlNarmal", L"texture\\WaterGirlNarmal.bmp");
	CreateCollider();

	m_collider->SetSize(Vector2(100.f, 130.f));
}

void Player::Update()
{
	if (KEY_CHECK(KEYLIST::D,KEYSTATE::HOLD)) {
		m_position.x += 200.f * DeltaTime;
	}
	if (KEY_CHECK(KEYLIST::A, KEYSTATE::HOLD)) {
		m_position.x -= 200.f * DeltaTime;
	}
	if (KEY_CHECK(KEYLIST::S, KEYSTATE::HOLD)) {
		m_position.y += 200.f * DeltaTime;
	}
	if (KEY_CHECK(KEYLIST::W, KEYSTATE::HOLD)) {
		m_position.y -= 200.f * DeltaTime;
	}
	if (KEY_CHECK(KEYLIST::SPACE, KEYSTATE::KEYDOWN)) {
		CreateMissile();
	}
}

void Player::Render(HDC hdc)
{
	int hWidth = (int)headTex->Width();
	int hHeight = (int)headTex->Height();

	Vector2  hPos = Position();
	ComponentRender(hdc);
	TransparentBlt(hdc, int(hPos.x - (float)(hWidth / 2)), int(hPos.y - (float)(hHeight / 2)), hWidth, hHeight, headTex->GetUseDC(), 0, 0, hWidth, hHeight, RGB(255, 255, 255));
}

void Player::Release()
{
	CObject::Release();
	if (headTex != nullptr)
		delete headTex;
}

void Player::CreateMissile()
{
	Vector2 vMissilePos = Position();
	vMissilePos.y -= Scale().y / 2.f;


	Misille* pMissile = new Misille;
	pMissile->Position() = vMissilePos;
	pMissile->Scale() = Vector2(25.f, 25.f);
	float theta = PI;
	pMissile->SetDir(3*theta/2.f);
	

	CScene* pCurScene =  CSceneManager::getInstance()->CurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}
