#include "StartScene.h"
#include"CObject.h"
#include"Player.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Start()
{
	char name[255] = "StartScene";
	SetName(name);

	CObject* pObj = new Player;
	pObj->Init(640, 384, 50, 50);
	AddObject(pObj, GROUP_TYPE::DEFAULT);
}

void StartScene::Exit()
{
}
