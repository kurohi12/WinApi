#pragma once
#include"Global.h"
#include"Singleton.h"
#include"GFunc.h"

struct Event{
	EVENT_TYPE eEvent;
	DWORD_PTR lParam;
	DWORD_PTR wParam;
};

class EventManager:public Singleton<EventManager>
{

private:
	vector<Event> m_vecEvent;
	vector<CObject*> m_vecDead;

	void Excute(const Event& even);

public:
	void Init();
	void Update();
	void Release();

	void AddEvent(const Event& even);
};

