#include "ColliderManager.h"
#include"CScene.h"
#include"CSceneManager.h"
#include"CObject.h"
#include"Collider.h"



void ColliderManager::Collied(GROUP_TYPE left, GROUP_TYPE right)
{
	CScene* curScene = CSceneManager::getInstance()->CurScene();
	const vector<CObject*>& vecLeft = curScene->GetGroupObj(left);
	const vector<CObject*>& vecRight = curScene->GetGroupObj(right);
	map<LONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < vecLeft.size(); i++) {
		if (vecLeft[i]->GetCollider() == nullptr) continue;
		for (size_t j = 0; j < vecRight.size(); j++) {

			if (vecRight[j]->GetCollider() == nullptr || vecLeft[i] == vecRight[j])
				continue;


			Collider* leftCol = vecLeft[i]->GetCollider();
			Collider* rightCol = vecRight[j]->GetCollider();

			COLLIDER_ID ID;
			ID.left_Id = leftCol->GetID();
			ID.right_Id = rightCol->GetID();


			iter = m_mapColInfo.find(ID.ID);

			if (m_mapColInfo.end() == iter) {
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}


			if (IsCollision(leftCol, rightCol)) {
				//현재 충돌 중

				if (iter->second)//이전에도 충돌함
				{
					if (vecLeft[i]->IsAble() || vecRight[j]->IsAble()) {
						leftCol->OnCollisionExit(rightCol);
						rightCol->OnCollisionExit(leftCol);
						iter->second = false;
					}
					else {

						leftCol->OnCollision(rightCol);
						rightCol->OnCollision(leftCol);
					}

				}
				else {
					//이전 충돌X 부딪히는 순간

					if (!vecLeft[i]->IsAble() && !vecRight[j]->IsAble()) {
						leftCol->OnCollisionEnter(rightCol);
						rightCol->OnCollisionEnter(leftCol);
						iter->second = true;
					}
				}
			}
			else {
				//충돌 하지 않음
				if (iter->second) {
					//충돌에서 해제됨
					leftCol->OnCollisionExit(rightCol);
					rightCol->OnCollisionExit(leftCol);
					iter->second = false;
				}

			}
		}
	}
}

bool ColliderManager::IsCollision(Collider* left, Collider* right)
{
	Vector2 leftPos = left->GetFinalPos();
	Vector2 leftSize = left->GetSize();

	Vector2 rightPos = right->GetFinalPos();
	Vector2 rightSIze = right->GetSize();

	if (abs(rightPos.x - leftPos.x) < (leftSize.x + rightSIze.x) / 2.f&& abs(rightPos.y - leftPos.y) < (leftSize.y + rightSIze.y) / 2.f){
		return true;
	}
	

	return false;
}

void ColliderManager::Init()
{
}

void ColliderManager::CheckGroup(GROUP_TYPE left, GROUP_TYPE right)
{
	UINT row = (UINT)left;
	UINT col = (UINT)right;

	if (col < row) {
		row = (UINT)right;
		col = (UINT)left;
	}

	if (m_arrCheck[row] & (1 << col)) {
		m_arrCheck[row] &= ~(1 << col);
	}else
		m_arrCheck[row] |= (1 << col);


}

void ColliderManager::Update()
{

	for (UINT row = 0; row < (UINT)GROUP_TYPE::END; row++) {
		for (UINT col = row; col < (UINT)GROUP_TYPE::END; col++) {
			if (m_arrCheck[row] & (1 << col)) {
				Collied(GROUP_TYPE(row), GROUP_TYPE(col));
			}
		}
	}
}

void ColliderManager::Reset()
{
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
}
