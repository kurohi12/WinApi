#include "StartScene.h"
#include"CObject.h"
#include"Player.h"
#include"CTexture.h"
#include"PathManager.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Start()
{
	CObject* pObj = new Player();
	
	pObj->Init(640, 384, 50, 50);
	
	
	AddObject(pObj, GROUP_TYPE::DEFAULT);
}

void StartScene::Exit()
{
}
