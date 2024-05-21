#include "CResource.h"

void CResource::SetKey(const wstring& key)
{
	m_strKey = key;
}

void CResource::SetPath(const wstring& path)
{
	m_strRealativeRath = path;
}

const wstring& CResource::GetKey()
{
	return m_strKey;
}

const wstring& CResource::GetPath()
{
	return m_strRealativeRath;
}

CResource::CResource()
{
}

CResource::~CResource()
{
}
