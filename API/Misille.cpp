#include "Misille.h"

void Misille::Update()
{
	Vector2 vPos = Position();

	vPos.x += 400.f * cosf(m_fTheta) * fDeltaTime;
	vPos.y -= 400.f * sinf(m_fTheta) * fDeltaTime;

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

Misille::Misille()
{
}

Misille::~Misille()
{
}
