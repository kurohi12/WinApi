#pragma once
#include"Global.h"

class SelectGDI
{
private:
	HPEN m_pen;
	HBRUSH m_brush;
	HDC hdc;
public:
	void Init(HDC dc, PEN_TYPE pType, BRUSH_TYPE bType);
	void Release();
};

