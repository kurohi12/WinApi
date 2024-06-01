#include "MainScene.h"
#include"KeyManager.h"
#include"GFunc.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Start()
{
}

void MainScene::Update()
{
	CScene::Update();

	if (KEY_CHECK(KEYLIST::ENTER, KEYSTATE::KEYDOWN)) {
		ChangeScene(SCENE_TYPE::START);
	}
}

void MainScene::Exit()
{
}
