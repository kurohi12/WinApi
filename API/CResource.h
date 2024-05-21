#pragma once
#include"Global.h"
class CResource
{
private : 
	wstring m_strKey; //리소스 키
	wstring m_strRealativeRath; //리소스 경로

public:
	void SetKey(const wstring& key);
	void SetPath(const wstring& path);
	const wstring& GetKey();
	const wstring& GetPath();

	CResource();
	~CResource();
};

