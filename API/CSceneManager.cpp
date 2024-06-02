#include "CSceneManager.h"
#include"StartScene.h"
#include"EventManager.h"
#include"MainScene.h"
#include"ToolScene.h"

void CSceneManager::Init()
{
	m_arrScene[(UINT)SCENE_TYPE::START] = new StartScene;
	m_arrScene[(UINT)SCENE_TYPE::MAIN] = new MainScene;
	m_arrScene[(UINT)SCENE_TYPE::TOOL] = new ToolScene;

	m_curScene = m_arrScene[(UINT)SCENE_TYPE::TOOL];
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
	m_curScene->UpdateFix();
}

void CSceneManager::Render(HDC hdc)
{
	m_curScene->Render(hdc);
}

CScene* CSceneManager::CurScene()
{
	return m_curScene;
}

void CSceneManager::ChangeScene(SCENE_TYPE scene)
{
	m_curScene->Exit();
	m_curScene = m_arrScene[(UINT)scene];
	m_curScene->Start();
}
