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
	Vector2 m_vLookAt; //ī�޶� ���� ��ġ
	CObject* m_Target; //ī�޶� Ÿ��

	Vector2 m_vDiff; //�ػ� �߽� ��ġ�� ī�޶� ��ġ ���� ����

	void CalDiff();
};

