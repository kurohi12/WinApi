#include "Camera.h"
#include"CObject.h"
#include"CCore.h"

#include"CTime.h"
#include"KeyManager.h"

void Camera::Update()
{
	if (m_Target!=nullptr) {
		if (m_Target->IsAble())
			m_Target = nullptr;
		else
		{
			m_vLookAt.x = m_Target->Position().x;
			m_vLookAt.y = m_Target->Position().y;
		}
	}

	CalDiff();
}

void Camera::CalDiff()
{
	m_fAccTime += fDeltaTime;

	if (m_fAccTime > m_fTime) {
		m_vCurLookAt = m_vLookAt;
	}
	else {
		//이전 위치와 현재 위치의 차이값을 보정
		if (!(m_vCurLookAt.x == m_vLookAt.x && m_vCurLookAt.y == m_vLookAt.y)) {
			Vector2 vLookDir = m_vLookAt - m_vPreLookAt;
			m_vCurLookAt = m_vPreLookAt + vLookDir.Normalize() * m_fSpeed * fDeltaTime;
		}
		
	}
	
	


	Vector2 vResolutuin;
	vResolutuin = CCore::getInstance()->GetPT();
	Vector2 vCenter = vResolutuin/2;

	m_vDiff = m_vCurLookAt - vCenter;

	m_vPreLookAt = m_vCurLookAt;

}
