#include "CScene.h"
#include"CObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	Release();
}

void CScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			m_vecObj[i][t]->Update();
		}
	}
}

void CScene::UpdateFix()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			m_vecObj[i][t]->UpdateFix();
		}
	}
}

void CScene::Render(HDC hdc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			m_vecObj[i][t]->Render(hdc);
		}
	}
}

void CScene::Release()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			delete m_vecObj[i][t];
		}
	}
}

void CScene::SetName(char* name)
{
	sceneName = name;
}

char* CScene::GetName()
{
	return sceneName;
}

void CScene::AddObject(CObject* obj, GROUP_TYPE type)
{
	m_vecObj[(UINT)type].push_back(obj);
}
