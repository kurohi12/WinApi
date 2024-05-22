#include "ResourceManager.h"
#include"CTexture.h"
#include"PathManager.h"

CTexture* ResourceManager::Load(const wstring& strKey, const wstring& strPath)
{
    CTexture* pTex = FIndTexture(strKey);
    if (pTex != nullptr) {
        return pTex;
    }

    pTex = new CTexture;
    

    wstring strFile = PathManager::getInstance()->GetContenPath();
    strFile += strPath;

    pTex->Load(strFile);
    pTex->SetKey(strKey);
    pTex->SetPath(strPath);


    m_mapTex.insert(make_pair(strKey, pTex));

    return pTex;
}

CTexture* ResourceManager::FIndTexture(const wstring& strKey)
{
    map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);
    
    if (iter == m_mapTex.end()) {
        return nullptr;
    }

    return iter->second;
}

void ResourceManager::Release()
{
    map<wstring, CTexture*>::iterator iter = m_mapTex.begin();
    for (; iter != m_mapTex.end(); iter++) {
        delete iter->second;
    }
}
