#include "Animator.h"
#include"GFunc.h"
#include"Animation.h"
#include"CTexture.h"

Animator::Animator() :m_object(nullptr), m_curAnim(nullptr), m_repeat(false)
{
}

Animator::~Animator()
{
	DeleteMap(m_mapAnim);
}

void Animator::CreateAnimation(const wstring& name, CTexture* tex, Vector2 vLT, Vector2 vSlideSize, Vector2 step, float duration, UINT frameCount)
{
	Animation* anim = FindAnimation(name);

	assert(nullptr == anim);

	anim = new Animation;

	anim->SetName(name);
	wstring a = anim->Getname();
	anim->m_animator = this;

	anim->Create(tex, vLT, vSlideSize, step, duration, frameCount);
	m_mapAnim.insert(make_pair(name, anim));
}

Animation* Animator::FindAnimation(const wstring& name)
{
	map<wstring, Animation*>::iterator iter = m_mapAnim.find(name);

	if (iter == m_mapAnim.end())
		return nullptr;

	return iter->second;
}

void Animator::Play(const wstring& name, bool ctn)
{
	m_curAnim = FindAnimation(name);
	m_repeat = ctn;
}

void Animator::Render(HDC hdc)
{
	if (nullptr != m_curAnim) {
		m_curAnim->Render(hdc);
	}
}

void Animator::Update()
{
	if (nullptr != m_curAnim) {
		m_curAnim->Update();

		if (m_repeat && m_curAnim->IsFinish()) {
			m_curAnim->SetFrame(0);
		}
	}
}
