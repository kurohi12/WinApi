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
	virtual void Update();
	void UpdateFix();
	void Render(HDC hdc);
	virtual void Exit() = 0;
	void Release();

	void SetName(char* name);
	char* GetName();

	const vector<CObject*>& GetGroupObj(GROUP_TYPE type);

public:
	void AddObject(CObject* obj, GROUP_TYPE type);
	void DeleteObject(GROUP_TYPE type);
	void DeleteAll();
};

