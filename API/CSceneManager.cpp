#include "CSceneManager.h"
#include"StartScene.h"

void CSceneManager::Init()
{
	m_arrScene[(UINT)SCENE_TYPE::START] = new StartScene;

	m_curScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_curScene->Start();
}

void CSceneManager::Release()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i) {
		if (m_arrScene[i] != nullptr) {
			delete m_arrScene[i];
		}
	}
}

void CSceneManager::Update()
{
	m_curScene->Update();
}

void CSceneManager::Render(HDC hdc)
{
	m_curScene->Render(hdc);
}

CScene* CSceneManager::CurScene()
{
	return m_curScene;
}
