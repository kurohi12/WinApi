#pragma once
#include"Global.h"

class CObject;

class Collider
{
private:
	CObject* m_Object;

	Vector2 m_OffsetPos;
	Vector2 m_FinalPos;
	Vector2 m_Size;


public:
	void Render(HDC hdc);
	void UpdateFix();

	void SetOffSetPos(Vector2 vec);
	void SetSize(Vector2 vec);

	Vector2 GetOffSet();
	Vector2 GetSize();
	
	
	friend class CObject;
};

