#include "EventManager.h"
#include"CSceneManager.h"
#include"CScene.h"

void EventManager::Excute(const Event& even)
{
	switch (even.eEvent)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		CObject* newObj = (CObject*)even.lParam;
		GROUP_TYPE type = (GROUP_TYPE)even.wParam;
		CSceneManager::getInstance()->CurScene()->AddObject(newObj, type);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT: {
		CObject* deadObj = (CObject*)even.lParam;
		deadObj->SetDead();
		m_vecDead.push_back(deadObj);
	}
	
		break;
	case EVENT_TYPE::CHANGE_SCENE:
		CSceneManager::getInstance()->ChangeScene((SCENE_TYPE)even.lParam);
		break;
	default:
		break;
	}
}

void EventManager::Init()
{
}

void EventManager::Update()
{
	for (size_t i = 0; i < m_vecDead.size(); ++i) {
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	for (size_t i = 0; i < m_vecEvent.size(); ++i) {
		Excute(m_vecEvent[i]);
	}

	m_vecEvent.clear();
}

void EventManager::Release()
{
}

void EventManager::AddEvent(const Event& even)
{
	m_vecEvent.push_back(even);
}
