#include "CScene.h"
#include"CObject.h"
#include"GFunc.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	Release();
}

void CScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			if(!m_vecObj[i][t]->IsAble())
				m_vecObj[i][t]->Update();
		}
	}
}

void CScene::UpdateFix()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			m_vecObj[i][t]->UpdateFix();
		}
	}
}

void CScene::Render(HDC hdc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {

		vector<CObject*>::iterator iter = m_vecObj[i].begin();

		for (; iter != m_vecObj[i].end(); ) {
			if (!(*iter)->IsAble()) {
				(*iter)->Render(hdc);
				++iter;
			}
			else {
				iter = m_vecObj[i].erase(iter);
			}
		}
	}
}

void CScene::Release()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t t = 0; t < m_vecObj[i].size(); ++t) {
			delete m_vecObj[i][t];
		}
	}
}

void CScene::SetName(char* name)
{
	sceneName = name;
}

char* CScene::GetName()
{
	return sceneName;
}

const vector<CObject*>& CScene::GetGroupObj(GROUP_TYPE type)
{
	return m_vecObj[(UINT)type];
}

void CScene::AddObject(CObject* obj, GROUP_TYPE type)
{
	m_vecObj[(UINT)type].push_back(obj);
}

void CScene::DeleteObject(GROUP_TYPE type)
{
	DeleteVec<CObject*>(m_vecObj[(UINT)type]);
}

void CScene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		DeleteObject((GROUP_TYPE)i);
	}
}


