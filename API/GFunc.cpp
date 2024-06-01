#include"GFunc.h"

void CreateObject(CObject* obj, GROUP_TYPE type) {
	Event evn = {};
	evn.eEvent = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)obj;
	evn.wParam = (DWORD_PTR)type;

	EventManager::getInstance()->AddEvent(evn);
}

void Destroy(CObject* obj) {
	Event evn = {};
	evn.eEvent = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)obj;

	EventManager::getInstance()->AddEvent(evn);
}

void ChangeScene(SCENE_TYPE scene)
{
	Event evn = {};
	evn.eEvent = EVENT_TYPE::CHANGE_SCENE;
	evn.lParam = (DWORD_PTR)scene;

	EventManager::getInstance()->AddEvent(evn);
}
