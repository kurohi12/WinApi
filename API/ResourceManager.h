#pragma once
#include "Global.h"
#include "Singleton.h"

class CTexture;

class ResourceManager : public Singleton<ResourceManager>
{
private:
	map<wstring, CTexture*> m_mapTex;
public:
	CTexture* Load(const wstring& strKey, const wstring& strPath);
	CTexture* FIndTexture(const wstring& strKey);
	void Release();
};

