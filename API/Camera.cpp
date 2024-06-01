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

	if (KEY_CHECK(KEYLIST::UP, KEYSTATE::HOLD)) {
		m_vLookAt.y -= 200.f * fDeltaTime;
	}
	if (KEY_CHECK(KEYLIST::RIGHT, KEYSTATE::HOLD)) {
		m_vLookAt.x += 200.f * fDeltaTime;
	}

	CalDiff();
}

void Camera::CalDiff()
{
	Vector2 vResolutuin;
	vResolutuin = CCore::getInstance()->GetPT();
	Vector2 vCenter = vResolutuin/2;

	m_vDiff = m_vLookAt - vCenter;

}
