#include "CObject.h"
#include"Collider.h"

CObject::CObject()
{
}

CObject::~CObject()
{
}

Vector2& CObject::Position()
{
	return m_position;
}

Vector2& CObject::Scale()
{
	return m_scale;
}

void CObject::CreateCollider()
{
	m_collider = new Collider;
	m_collider->m_Object = this;
}

void CObject::Init(float px, float py, float sx, float sy)
{
	m_position.x = px;
	m_position.y = py;
	m_scale.x = sx;
	m_scale.y = sy;
	m_collider = nullptr;
}

void CObject::Release()
{
	if (m_collider != nullptr)
		delete m_collider;
}

void CObject::UpdateFix()
{
	if (m_collider) {
		m_collider->UpdateFix();
	}
}

void CObject::ComponentRender(HDC hdc)
{
	if (m_collider) {
		m_collider->Render(hdc);
	}
}


