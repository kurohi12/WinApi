#pragma once
#include"Global.h"
#include"Singleton.h"
class PathManager :public Singleton<PathManager>
{
private:
	wchar_t m_ContentPath[255];
public:
	void Init();
	const wchar_t* GetContenPath();
};

