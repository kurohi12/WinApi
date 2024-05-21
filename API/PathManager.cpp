#include "PathManager.h"



void PathManager::Init()
{
	GetCurrentDirectory(255, m_ContentPath);

	int len = wcslen(m_ContentPath);

	for (int i = len - 1; i <= 0; i--) {
		if ('\\' == m_ContentPath[i]) {
			m_ContentPath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_ContentPath, 255, L"\\bin\\content\\");
}

const wchar_t* PathManager::GetContenPath()
{
	return m_ContentPath;
}
