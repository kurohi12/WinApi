#include "CCore.h"
#include"CObject.h"

int CCore::Init(HWND phWnd, POINT pPt)
{
	m_hwnd = phWnd;
	m_pt = pPt;

	RECT rt = {0,0,m_pt.x,m_pt.y};

	//해상도 조정
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);

	SetWindowPos(m_hwnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	
	m_hdc = GetDC(m_hwnd);

	//더블 더퍼링
	m_hBit = CreateCompatibleBitmap(m_hdc, m_pt.x, m_pt.y);
	m_mDC = CreateCompatibleDC(m_hdc);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_mDC, m_hBit);
	DeleteObject(hOldBit);

	//매니저 초기화
	CTime::getInstance()->Init();

	m_obj = new CObject();
	m_obj->Position() = { 100,100 };
	m_obj->Scale() = { 50,50 };


	return S_OK;
}

void CCore::Release()
{
	ReleaseDC(m_hwnd, m_hdc);
	DeleteDC(m_mDC);
	DeleteObject(m_hBit);
}

void CCore::Progress()
{
	Update();
	Render();
}

HWND CCore::GetHwnd()
{
	return m_hwnd;
}

HDC CCore::GetHDC()
{
	return m_hdc;
}

void CCore::Update()
{
	CTime::getInstance()->Update();
}

void CCore::Render()
{
	//Clear
	PatBlt(m_mDC, 0, 0, m_pt.x, m_pt.y, WHITENESS);

	Rectangle(m_mDC, int(m_obj->Position().x - m_obj->Scale().x / 2),
				     int(m_obj->Position().y - m_obj->Scale().y / 2),
					 int(m_obj->Position().x + m_obj->Scale().x / 2),
					 int(m_obj->Position().y + m_obj->Scale().y / 2));

	BitBlt(m_hdc, 0, 0, m_pt.x, m_pt.y,m_mDC,0,0,SRCCOPY);
}	
