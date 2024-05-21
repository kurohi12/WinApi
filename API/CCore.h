#pragma once
#include"Singleton.h"
#include"Windows.h"
#include"CObject.h"
#include"CTime.h"
class CCore :public Singleton<CCore>{

public:
	int Init(HWND phWnd, POINT pPt);
	void Release();
	void Progress();
	HWND GetHwnd();
	HDC GetHDC();
	POINT GetPT();
private:
	HWND m_hwnd; //������ �ڵ�
	POINT m_pt; //�ػ�
	HDC m_hdc;

	HBITMAP m_hBit;
	HDC m_mDC;

	CObject* m_obj;

	void Update();
	void Render();
};

