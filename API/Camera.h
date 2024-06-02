#pragma once
#include"Singleton.h"
#include"Global.h"

class CObject;

class Camera:public Singleton<Camera>
{
public:
	void SetLookAt(Vector2 lookAt) 
	{ 
		m_vLookAt = lookAt; 
		float fMoveDIs = (m_vLookAt - m_vPreLookAt).Distance();
		m_fSpeed = fMoveDIs / m_fTime;
		m_fAccTime = 0.f;
	}
	void SetTarget(CObject* target) { m_Target = target; }
	Vector2 GetLookAt() { return m_vCurLookAt; }


	void Update();

	Vector2 GetRenderPos(Vector2 vec) { return vec - m_vDiff; }
	Vector2 GetRealPos(Vector2 renderPos) { return renderPos + m_vDiff; }

private:
	Vector2 m_vLookAt; //카메라가 보는 위치
	Vector2 m_vCurLookAt; //보정 위치
	Vector2 m_vPreLookAt;
	CObject* m_Target; //카메라 타켓

	Vector2 m_vDiff; //해상도 중심 위치와 카메라 위치 간의 차이

	float m_fTime = 2.f;	//타켓을 따라가는 시간
	float m_fSpeed;		//	타켓을 따라가는 속도
	float m_fAccTime; //누적 시간

	void CalDiff();
};

