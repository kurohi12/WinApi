#include "Collider.h"
#include"CObject.h"
#include"CCore.h"
#include"SelectGDI.h"
#include "Camera.h"

UINT Collider::nextID = 0;

void Collider::Render(HDC hdc)
{
	SelectGDI gdi = SelectGDI();
	gdi.Init(hdc, PEN_TYPE::GREEN, BRUSH_TYPE::HOLLOW);

	Vector2 vRenderPos = Camera::getInstance()->GetRenderPos(m_FinalPos);

	Rectangle(hdc, (int)vRenderPos.x - m_Size.x / 2.f,
				   (int)vRenderPos.y - m_Size.y / 2.f,
				   (int)vRenderPos.x + m_Size.x / 2.f,
				   (int)vRenderPos.y + m_Size.y / 2.f);

	
}

void Collider::UpdateFix()
{
	Vector2 objectPos = m_Object->Position();
	m_FinalPos = objectPos + m_OffsetPos;
	assert(0 <= colCount);

}

void Collider::SetOffSetPos(Vector2 vec)
{
	m_OffsetPos = vec;
}

void Collider::SetSize(Vector2 vec)
{
	m_Size = vec;
}

Vector2 Collider::GetFinalPos()
{
	return m_FinalPos;
}

Vector2 Collider::GetOffSet()
{
	return m_OffsetPos;
}

Vector2 Collider::GetSize()
{
	return m_Size;
}

UINT Collider::GetID()
{
	return id;
}

Collider::Collider()
{
	m_Object = nullptr;
	id = nextID++;
}

void Collider::OnCollision(Collider* other)
{
	m_Object->OnCollision(other);
}

Collider::~Collider()
{
}

Collider::Collider(const Collider& origin)
{
	m_OffsetPos = origin.m_OffsetPos;
	m_Size = origin.m_Size;
	id = nextID++;
}

void Collider::OnCollisionEnter(Collider* other)
{
	m_Object->OnCollisionEnter(other);
	colCount++;
}

CObject* Collider::GetObj()
{
	return m_Object;
}

void Collider::OnCollisionExit(Collider* other)
{
	m_Object->OnCollisionExit(other);
	colCount--;
}
