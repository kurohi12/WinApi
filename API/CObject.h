#pragma once
#include"Windows.h"
#include"Global.h"
#include"Camera.h"


class Collider;
class CTexture;
class Animator;

class CObject
{
protected:
	Vector2 m_position;
	Vector2 m_scale;

	Collider* m_collider;
	Animator* m_animator;

	bool m_able;

	wstring name;

	Vector2 m_renderPos;

	//float m_dir; //πÊ«‚
public:
	CObject();
	CObject(const CObject& origin);
	virtual ~CObject();
	Vector2& Position();
	Vector2& Scale();
	wstring& Name();

	void CreateCollider();
	void CreateAnimator();

	virtual CObject* Clone() = 0;

	virtual void Init(float px, float py, float sx, float sy,wstring _name);
	virtual void Release();
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

	virtual void OnCollision(Collider* other) {}
	virtual void OnCollisionEnter(Collider* other) {}
	virtual void OnCollisionExit(Collider* other) {}

	void UpdateFix();
	void ComponentRender(HDC hdc);
	Collider* GetCollider();
	Animator* GetAnimator();
	bool IsAble();

	friend class EventManager;
private:
	void SetDead();
};

