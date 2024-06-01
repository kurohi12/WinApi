#pragma once
#include"Singleton.h"
#include"Global.h"

class CObject;

class Camera:public Singleton<Camera>
{
public:
	void SetLookAt(Vector2 lookAt) { m_vLookAt = lookAt; }
	void SetTarget(CObject* target) { m_Target = target; }

	void Update();

	Vector2 GetRenderPos(Vector2 vec) { return vec - m_vDiff; }

private:
	Vector2 m_vLookAt; //카메라가 보는 위치
	CObject* m_Target; //카메라 타켓

	Vector2 m_vDiff; //해상도 중심 위치와 카메라 위치 간의 차이

	void CalDiff();
};

