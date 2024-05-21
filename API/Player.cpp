#include "Player.h"
#include"KeyManager.h"
#include"Misille.h"
#include"CSceneManager.h"
#include"CScene.h"

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
	Rectangle(hdc, int(m_position.x - m_scale.x / 2),
		int(m_position.y - m_scale.y / 2),
		int(m_position.x + m_scale.x / 2),
		int(m_position.y + m_scale.y / 2));
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
