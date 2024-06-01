#include "ResourceManager.h"
#include"CTexture.h"
#include"PathManager.h"
#include"GFunc.h"

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
    map<wstring, CResource*>::iterator iter = m_mapTex.find(strKey);
    
    if (iter == m_mapTex.end()) {
        return nullptr;
    }

    return (CTexture*)iter->second;
}

void ResourceManager::Release()
{
    DeleteMap(m_mapTex);
}
