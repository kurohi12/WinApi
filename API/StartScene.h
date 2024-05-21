#pragma once
#include "CScene.h"

class StartScene : public CScene
{
public:
	StartScene();
	~StartScene();

	virtual void Start();
	virtual void Exit();
};

