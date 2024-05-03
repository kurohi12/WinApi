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

	double m_deltaTime=0.; //프레임 사이의 시간
	double m_DTAcc=0.; //프레임 누적 시간
	UINT m_CallCount; //초당 호출 횟수
	UINT FPS;
public:
	void Init();
	void Update();

	double DeltaTime_d();
	float DeltaTime_f();
};

