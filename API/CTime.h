#pragma once
#include"Windows.h"
#include"Singleton.h"
#include"profileapi.h"
class CTime:public Singleton<CTime>
{
private:
	LARGE_INTEGER m_CurCount;
	LARGE_INTEGER m_Preqency;
	LARGE_INTEGER m_PreCount;

	double m_deltaTime=0.; //������ ������ �ð�
	double m_DTAcc=0.; //������ ���� �ð�
	UINT m_CallCount; //�ʴ� ȣ�� Ƚ��
	UINT FPS;
public:
	void Init();
	void Update();

	double DeltaTime_d();
	float DeltaTime_f();
};

