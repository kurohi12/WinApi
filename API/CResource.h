#pragma once
#include"Global.h"
class CResource
{
private : 
	wstring m_strKey; //���ҽ� Ű
	wstring m_strRealativeRath; //���ҽ� ���

public:
	void SetKey(const wstring& key);
	void SetPath(const wstring& path);
	const wstring& GetKey();
	const wstring& GetPath();

	CResource();
	~CResource();
};

