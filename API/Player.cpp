#include "Player.h"
#include"KeyManager.h"
#include"Misille.h"
#include"CSceneManager.h"
#include"CScene.h"
#include"ResourceManager.h"
#include"CTexture.h"
#include"Collider.h"
#include"GFunc.h"
#include"Animator.h"
#include"Animation.h"

void Player::Init(float px, float py, float sx, float sy,wstring _name)
{
	CObject::Init(px, py, sx, sy, _name);
	CTexture* headTex = ResourceManager::getInstance()->Load(L"WaterGirl", L"texture\\WaterGirlStay.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"WaterGirlStay", headTex, Vector2(0.f, 0.f), Vector2(135.f, 130.f), Vector2(135.f, 0.f), 0.1f, 6);
	GetAnimator()->Play(L"WaterGirlStay",true);
	CreateCollider();

	m_collider->SetOffSetPos(Vector2(0.f,25.f));
	m_collider->SetSize(Vector2(50.f, 70.f));

	Animation* anim = GetAnimator()->FindAnimation(L"WaterGirlStay");
	anim->GetFrm(1).vOffset = Vector2(2.5f,0.f);
	anim->GetFrm(2).vOffset = Vector2(2.5f, 0.f);
	anim->GetFrm(3).vOffset = Vector2(2.5f, 0.f);
	anim->GetFrm(4).vOffset = Vector2(3.5f, 0.f);
	anim->GetFrm(5).vOffset = Vector2(4.f, 0.f);

}

void Player::Update()
{

	if (KEY_CHECK(KEYLIST::D,KEYSTATE::HOLD)) {
		m_position.x += 200.f * fDeltaTime;
	}
	if (KEY_CHECK(KEYLIST::A, KEYSTATE::HOLD)) {
		m_position.x -= 200.f * fDeltaTime;
	}
	if (KEY_CHECK(KEYLIST::S, KEYSTATE::HOLD)) {
		m_position.y += 200.f * fDeltaTime;
	}
	if (KEY_CHECK(KEYLIST::W, KEYSTATE::HOLD)) {
		m_position.y -= 200.f * fDeltaTime;
	}
	if (KEY_CHECK(KEYLIST::SPACE, KEYSTATE::KEYDOWN)) {
		CreateMissile();
	}
	GetAnimator()->Update();
}

void Player::Render(HDC hdc)
{
	
	ComponentRender(hdc);
}

void Player::Release()
{
	CObject::Release();
}

void Player::OnCollision(Collider* other)
{
}

void Player::OnCollisionEnter(Collider* other)
{
}

void Player::OnCollisionExit(Collider* other)
{
}

void Player::CreateMissile()
{
	Vector2 vMissilePos = Position();
	vMissilePos.y -= Scale().y / 2.f;


	Misille* pMissile = new Misille();
	pMissile->Init(vMissilePos.x, vMissilePos.y, 25.f, 25.f, L"Misille");
	float theta = PI;
	pMissile->SetDir(3*theta/2.f);
	
	CreateObject(pMissile, GROUP_TYPE::DEFAULT);
}
