#pragma once
#include"Global.h"

class CObject;

class Collider
{
private:
	static  UINT nextID;

	CObject* m_Object = nullptr;

	Vector2 m_OffsetPos;
	Vector2 m_FinalPos;
	Vector2 m_Size;

	UINT id;

	int colCount;

public:
	void Render(HDC hdc);
	void UpdateFix();

	void SetOffSetPos(Vector2 vec);
	Vector2 GetFinalPos();
	void SetSize(Vector2 vec);

	Vector2 GetOffSet();
	Vector2 GetSize();

	UINT GetID();
	CObject* GetObj();

	void OnCollision(Collider* other);
	void OnCollisionEnter(Collider* other);
	void OnCollisionExit(Collider* other);


	//대입연산자 삭제
	Collider& operator = (Collider& origin) = delete;
	

	Collider();

	//id를 다르게 하기 위한 복사 생성자
	Collider(const Collider& origin);
	~Collider();
	
	friend class CObject;
};

