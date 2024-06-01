#pragma once
#include"Global.h"
#include"Singleton.h"

class CScene;

class CSceneManager:public Singleton<CSceneManager>
{
private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END];
	CScene* m_curScene;

	friend class EventManager;
	void ChangeScene(SCENE_TYPE scene);
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);
	CScene* CurScene();
};

