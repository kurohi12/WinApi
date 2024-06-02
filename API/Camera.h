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
	Vector2 m_vLookAt; //ī�޶� ���� ��ġ
	Vector2 m_vCurLookAt; //���� ��ġ
	Vector2 m_vPreLookAt;
	CObject* m_Target; //ī�޶� Ÿ��

	Vector2 m_vDiff; //�ػ� �߽� ��ġ�� ī�޶� ��ġ ���� ����

	float m_fTime = 2.f;	//Ÿ���� ���󰡴� �ð�
	float m_fSpeed;		//	Ÿ���� ���󰡴� �ӵ�
	float m_fAccTime; //���� �ð�

	void CalDiff();
};

