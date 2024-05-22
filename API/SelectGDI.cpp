#include "SelectGDI.h"
#include"CCore.h"

void SelectGDI::Init(HDC dc, PEN_TYPE pType, BRUSH_TYPE bType)
{
	hdc = hdc;

	HPEN hPen = CCore::getInstance()->GetPen(pType);
	m_pen = (HPEN)SelectObject(hdc, hPen);

	HBRUSH hBrush = CCore::getInstance()->GetBrush(bType);
	m_brush = (HBRUSH)SelectObject(hdc, hBrush);
}

void SelectGDI::Release()
{
	SelectObject(hdc, m_brush);
	SelectObject(hdc, m_pen);
}
