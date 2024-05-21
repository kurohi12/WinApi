#include "Misille.h"

void Misille::Update()
{
	Vector2 vPos = Position();

	//vPos.x += 400.f * cosf(m_fTheta) * fDeltaTime;
	//vPos.y -= 400.f * sinf(m_fTheta) * fDeltaTime;

	vPos.x += 400.f * m_vDir.x * fDeltaTime;
	vPos.y -= 400.f * m_vDir.y * fDeltaTime;

	Position() = vPos;
}

void Misille::Render(HDC hdc)
{
	Ellipse(hdc, int(m_position.x - m_scale.x / 2),
		int(m_position.y - m_scale.y / 2),
		int(m_position.x + m_scale.x / 2),
		int(m_position.y + m_scale.y / 2));
}

void Misille::SetDir(float fTheta)
{
	m_fTheta = fTheta;
}

void Misille::SetVDir(Vector2 v)
{
	m_vDir = v;
	m_vDir.Normalize();
}

Misille::Misille()
{
	m_vDir.Normalize();
}

Misille::~Misille()
{
}
