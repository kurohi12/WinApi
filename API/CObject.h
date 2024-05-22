#pragma once
#include"Windows.h"
#include"Global.h"

class Collider;
class CTexture;

class CObject
{
protected:
	Vector2 m_position;
	Vector2 m_scale;

	Collider* m_collider;

	//float m_dir; //πÊ«‚
public:
	CObject();
	virtual ~CObject();
	Vector2& Position();
	Vector2& Scale();

	void CreateCollider();

	virtual void Init(float px, float py, float sx, float sy);
	virtual void Release();
	virtual void Update() = 0;
	void UpdateFix();
	virtual void Render(HDC hdc) = 0;
	void ComponentRender(HDC hdc);
};

