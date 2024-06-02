#include "Animation.h"
#include"Animator.h"
#include"CTexture.h"
#include"CObject.h"
#include"CTime.h"
#include"Camera.h"

Animation::Animation() :m_animator(nullptr), m_curFrm(5),m_tex(nullptr),m_fAccTime(0.f),m_finish(false)
{
}

Animation::~Animation()
{
}

void Animation::SetFrame(int frm)
{
	m_finish = false;
	m_curFrm = frm;
	m_fAccTime = 0.f;
}

void Animation::Create(CTexture* tex, Vector2 vLT, Vector2 vSlideSize, Vector2 step, float duration, UINT frameCount)
{
	m_tex = tex;

	AnimFrm frm = {};
	for (int i = 0; i < frameCount; ++i) {
		frm.fDuration = duration;
		frm.vSlice = vSlideSize;
		frm.vLT = vLT + step * i;

		m_vecFrm.push_back(frm);
	}
}

void Animation::Update()
{
	if (m_finish) return;

	m_fAccTime += fDeltaTime;
	
	if (m_fAccTime > m_vecFrm[m_curFrm].fDuration) {
		++m_curFrm;
		if (m_vecFrm.size() <= m_curFrm) {
			m_curFrm = -1;
			m_finish = true;
			m_fAccTime = 0.f;
			return;
		}
		m_fAccTime = m_fAccTime - m_vecFrm[m_curFrm].fDuration;
	}
}

void Animation::Render(HDC hdc)
{
	if (m_finish) return;

	CObject* pObj = m_animator->GetObj();
	Vector2 pos = pObj->Position();


	pos += m_vecFrm[m_curFrm].vOffset;
	pos = Camera::getInstance()->GetRenderPos(pos);
	TransparentBlt(hdc, (int)(pos.x - m_vecFrm[m_curFrm].vSlice.x / 2.f),
						(int)(pos.y - m_vecFrm[m_curFrm].vSlice.y / 2.f),
						(int)m_vecFrm[m_curFrm].vSlice.x, 
						(int)m_vecFrm[m_curFrm].vSlice.y, m_tex->GetUseDC(), 
						(int)m_vecFrm[m_curFrm].vLT.x, 
						(int)m_vecFrm[m_curFrm].vLT.y, 
						(int)m_vecFrm[m_curFrm].vSlice.x, 
						(int)m_vecFrm[m_curFrm].vSlice.y, RGB(255, 255, 255));
}
