#pragma once
#include"Windows.h"
#include"Global.h"
class CObject
{
protected:
	Vector2 m_position;
	Vector2 m_scale;
	//float m_dir; //πÊ«‚
public:
	CObject();
	virtual ~CObject();
	Vector2& Position();
	Vector2& Scale();
	void Init(float px, float py, float sx, float sy);
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
};

