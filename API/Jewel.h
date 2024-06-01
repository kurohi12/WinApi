#pragma once
#include "CObject.h"

class Jewel :
    public CObject
{
public:
    virtual void Init(float px, float py, float sx, float sy, wstring _name);
    virtual void Update();
    virtual void Render(HDC hdc);
    virtual void Release();
    virtual void OnCollision(Collider* other);
    virtual void OnCollisionEnter(Collider* other);
    virtual void OnCollisionExit(Collider* other);
    virtual CObject* Clone() {
        return new Jewel(*this);
    }
private :
    CTexture* tex;

};

