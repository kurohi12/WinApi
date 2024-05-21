#include "CObject.h"


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

void CObject::Init(float px, float py, float sx, float sy)
{
	m_position.x = px;
	m_position.y = py;
	m_scale.x = sx;
	m_scale.y = sy;
}


