#include "CCore.h"
#include"CObject.h"
#include"KeyManager.h"
#include"CSceneManager.h"
#include"PathManager.h"

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
	KeyManager::getInstance()->Init();
	PathManager::getInstance()->Init();
	CSceneManager::getInstance()->Init();


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

POINT CCore::GetPT()
{
	return m_pt;
}

void CCore::Update()
{
	CTime::getInstance()->Update();
	KeyManager::getInstance()->Update();
	CSceneManager::getInstance()->Update();

	
}

void CCore::Render()
{
	//Clear
	PatBlt(m_mDC, 0, 0, m_pt.x, m_pt.y, WHITENESS);

	CSceneManager::getInstance()->Render(m_mDC);



	BitBlt(m_hdc, 0, 0, m_pt.x, m_pt.y,m_mDC,0,0,SRCCOPY);
}	
