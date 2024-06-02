#pragma once
#include"CObject.h"
class CTile : public CObject
{
private:

public:

    virtual void Init(float px, float py, float sx, float sy, wstring _name);
    virtual void Update();
    virtual void Render(HDC hdc);
    virtual void Release();
    virtual CObject* Clone() {
        return new CTile(*this);
    }

    virtual void OnCollision(Collider* other);
    virtual void OnCollisionEnter(Collider* other);
    virtual void OnCollisionExit(Collider* other);

	CTile();
	~CTile();
};

