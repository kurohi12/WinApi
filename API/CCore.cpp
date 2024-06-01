#include "CCore.h"
#include"CObject.h"
#include"KeyManager.h"
#include"CSceneManager.h"
#include"PathManager.h"
#include"ResourceManager.h"
#include"ColliderManager.h"
#include"EventManager.h"
#include"Camera.h"

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

	CreateBrushPen();

	//매니저 초기화
	CTime::getInstance()->Init();
	KeyManager::getInstance()->Init();
	PathManager::getInstance()->Init();
	CSceneManager::getInstance()->Init();
	ColliderManager::getInstance()->Init();


	return S_OK;
}

void CCore::Release()
{
	CSceneManager::getInstance()->Release();
	ResourceManager::getInstance()->Release();
	ReleaseDC(m_hwnd, m_hdc);
	DeleteDC(m_mDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; i++) {
		DeleteObject(m_arrPen[i]);
	}
}

void CCore::Progress()
{
	Update();
	Render();

	//이벤트 지연처리
	EventManager::getInstance()->Update();
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

HBRUSH CCore::GetBrush(BRUSH_TYPE type)
{
	return m_arrBrush[(UINT)type];
}

HPEN CCore::GetPen(PEN_TYPE type)
{
	return m_arrPen[(UINT)type];
}

void CCore::Update()
{
	CTime::getInstance()->Update();
	KeyManager::getInstance()->Update();
	Camera::getInstance()->Update();
	CSceneManager::getInstance()->Update();
	ColliderManager::getInstance()->Update();
	
}

void CCore::Render()
{
	//Clear
	PatBlt(m_mDC, 0, 0, m_pt.x, m_pt.y, WHITENESS);

	CSceneManager::getInstance()->Render(m_mDC);



	BitBlt(m_hdc, 0, 0, m_pt.x, m_pt.y,m_mDC,0,0,SRCCOPY);
}
void CCore::CreateBrushPen()
{
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

