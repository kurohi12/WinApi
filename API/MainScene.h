#pragma once
#include"CScene.h"

class MainScene : public CScene
{
public:
	MainScene();
	~MainScene();

	virtual void Start();
	virtual void Update();
	virtual void Exit();
};

