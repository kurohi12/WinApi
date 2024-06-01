#include "CObject.h"
#include"Collider.h"
#include"Animator.h"

CObject::CObject()
{
}

CObject::CObject(const CObject& origin)
{
	m_position = origin.m_position;
	m_scale = origin.m_scale;

	if (origin.m_collider != nullptr) {
		m_collider = new Collider(*origin.m_collider);
		m_collider->m_Object = this;
	}
	if (origin.m_animator != nullptr) {
		m_animator = new Animator(*origin.m_animator);
		m_animator->m_object = this;
	}


	m_able = true;

	name = origin.name;
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

wstring& CObject::Name()
{
	return name;
}

void CObject::CreateCollider()
{
	m_collider = new Collider;
	m_collider->m_Object = this;
}

void CObject::CreateAnimator()
{
	m_animator = new Animator;
	m_animator->m_object = this;
}

void CObject::Init(float px, float py, float sx, float sy, wstring _name)
{
	m_position.x = px;
	m_position.y = py;
	m_scale.x = sx;
	m_scale.y = sy;
	m_collider = nullptr;
	m_able = true;
	name = _name;
}

void CObject::Release()
{
	if (m_collider != nullptr)
		delete m_collider;
	if (m_animator != nullptr)
		delete m_animator;
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
	if (m_animator) {
		m_animator->Render(hdc);
	}
}

Collider* CObject::GetCollider()
{
	return m_collider;
}

Animator* CObject::GetAnimator()
{
	return m_animator;
}

bool CObject::IsAble()
{
	return !m_able;
}

void CObject::SetDead()
{
	m_able = false;
}


