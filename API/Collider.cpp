#include "Collider.h"
#include"CObject.h"
#include"CCore.h"
#include"SelectGDI.h"

void Collider::Render(HDC hdc)
{
	SelectGDI gdi = SelectGDI();
	gdi.Init(hdc, PEN_TYPE::GREEN, BRUSH_TYPE::HOLLOW);

	Rectangle(hdc, (int)m_FinalPos.x - m_Size.x / 2.f, 
				   (int)m_FinalPos.y - m_Size.y / 2.f, 
				   (int)m_FinalPos.x + m_Size.x / 2.f, 
				   (int)m_FinalPos.y + m_Size.y / 2.f);

}

void Collider::UpdateFix()
{
	Vector2 objectPos = m_Object->Position();
	m_FinalPos = objectPos + m_OffsetPos;
}

void Collider::SetOffSetPos(Vector2 vec)
{
	m_OffsetPos = vec;
}

void Collider::SetSize(Vector2 vec)
{
	m_Size = vec;
}

Vector2 Collider::GetOffSet()
{
	return m_OffsetPos;
}

Vector2 Collider::GetSize()
{
	return m_Size;
}
