#include "CObject.h"

CObject::CObject()
{
	m_position = { 0,0 };
	m_scale = { 0,0 };
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
