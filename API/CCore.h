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
	HBRUSH GetBrush(BRUSH_TYPE type);
	HPEN GetPen(PEN_TYPE type);
private:
	HWND m_hwnd =nullptr; //윈도우 핸들
	POINT m_pt = {}; //해상도
	HDC m_hdc=nullptr;

	HBITMAP m_hBit =nullptr;
	HDC m_mDC=nullptr;

	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];

	CObject* m_obj;

	void Update();
	void Render();

	void CreateBrushPen();
};

