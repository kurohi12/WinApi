#pragma once
#include "Global.h"
#include "Singleton.h"
#include"GFunc.h"
class CTexture;
class CResource;

class ResourceManager : public Singleton<ResourceManager>
{
private:
	map<wstring, CResource*> m_mapTex;
public:
	CTexture* Load(const wstring& strKey, const wstring& strPath);
	CTexture* FIndTexture(const wstring& strKey);
	void Release();
};

