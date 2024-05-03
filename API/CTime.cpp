#include "CTime.h"
#include"CCore.h"

void CTime::Init()
{
	QueryPerformanceCounter(&m_PreCount); //초당 카운트

	//초당 수를 세는 빈번도
	QueryPerformanceFrequency(&m_Preqency);


}

void CTime::Update()
{
	QueryPerformanceCounter(&m_CurCount);

	//이전 프레임 카운트와 현재 프레임 카운트의 차이 계산
	m_deltaTime = (double)(m_CurCount.QuadPart - m_PreCount.QuadPart) / 
		(double)m_Preqency.QuadPart;

	m_PreCount = m_CurCount;

	++m_CallCount;
	m_DTAcc += m_deltaTime;
	int i = 0;

	if (m_DTAcc>=1.) {
		FPS = m_CallCount;
		
		m_DTAcc = 0;
		m_CallCount = 0;
		
		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, deltaTime : %f", FPS, DeltaTime);
		SetWindowText(CCore::getInstance()->GetHwnd(), szBuffer);
	}
}

double CTime::DeltaTime_d()
{
	return m_deltaTime;
}

float CTime::DeltaTime_f() {
	return (float)m_deltaTime;
}
