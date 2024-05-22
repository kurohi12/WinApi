#pragma once
#include"Global.h"
#include"Windows.h"

class CObject;

class CScene
{
private:
	char* sceneName;
	vector<CObject*> m_vecObj[(UINT)GROUP_TYPE::END];

public:
	CScene();
	virtual ~CScene();
	virtual void Start() = 0;
	void Update();
	void UpdateFix();
	void Render(HDC hdc);
	virtual void Exit() = 0;
	void Release();

	void SetName(char* name);
	char* GetName();

public:
	void AddObject(CObject* obj, GROUP_TYPE type);
};

