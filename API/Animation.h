#pragma once
#include"Global.h"
#include"CResource.h"

class Animator;
class CTexture;

struct AnimFrm {
	Vector2 vLT;
	Vector2 vSlice;
	Vector2 vOffset;
	float fDuration;
};

class Animation : public CResource
{
private:
	wstring m_name;
	Animator* m_animator;

	CTexture* m_tex;

	vector<AnimFrm> m_vecFrm;
	int m_curFrm;
	float m_fAccTime;

	bool m_finish;

public:
	Animation();
	virtual ~Animation();

	void SetName(const wstring name) { m_name = name; }
	wstring& Getname() { return m_name; }
	bool IsFinish() { return m_finish; }
	void SetFrame(int frm);

	AnimFrm& GetFrm(int idx) {
		return m_vecFrm[idx];
	}

	void Create(CTexture* tex, Vector2 vLT, Vector2 vSlideSize, Vector2 step, float duration,UINT frameCount);


	void Update();
	void Render(HDC hdc);

	friend class Animator;
};

