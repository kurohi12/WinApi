#pragma once
#include"Windows.h"
#include"Global.h"
class CObject
{
private:
	Vector2 m_position;
	Vector2 m_scale;
public:
	CObject();
	~CObject();
	Vector2& Position();
	Vector2& Scale();
};

