#include "StartScene.h"
#include"CObject.h"
#include"Player.h"
#include"CTexture.h"
#include"PathManager.h"
#include"Jewel.h"
#include"ColliderManager.h"
#include"CSceneManager.h"
#include"KeyManager.h"
#include"GFunc.h"
#include"Camera.h"
#include"CCore.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Start()
{
	CObject* pObj = new Player();

	pObj->Init(0, 0, 50, 50,L"Player");
	AddObject(pObj, GROUP_TYPE::PLAYER);

	Camera::getInstance()->SetTarget(pObj);

	CObject* pObj2 = new Jewel();

	pObj2->Init(200, 100, 10, 10,L"Blue_J");
	AddObject(pObj2, GROUP_TYPE::JEWEL);

	ColliderManager::getInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::JEWEL);
	
	Vector2 vResolutuin;
	vResolutuin = CCore::getInstance()->GetPT();
	Camera::getInstance()->SetLookAt(vResolutuin/2);
	
}

void StartScene::Update()
{
	CScene::Update();

	if (KEY_CHECK(KEYLIST::ENTER, KEYSTATE::KEYDOWN)) {
		ChangeScene(SCENE_TYPE::MAIN);
	}

}

void StartScene::Exit()
{
	DeleteAll();
	ColliderManager::getInstance()->Reset();
}
