#pragma once
#include"Global.h"

class CObject;
class Animation;
class CTexture;

class Animator
{
private:
	CObject* m_object;
	map<wstring, Animation*> m_mapAnim;
	Animation* m_curAnim;
	bool m_repeat;

public:
	Animator();
	~Animator();

	void CreateAnimation(const wstring& name, CTexture* tex,Vector2 vLT,Vector2 vSlideSize, Vector2 step, float duration, UINT frameCount);
	Animation* FindAnimation(const wstring& name);
	void Play(const wstring& name,bool ctn);
	void Render(HDC hdc);
	void Update();

	CObject* GetObj() { return m_object; }

	friend class CObject;
};

