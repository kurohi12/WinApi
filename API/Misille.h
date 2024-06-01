#pragma once
#include"CObject.h"
class Misille :
    public CObject
{
private:
    float m_dir = 1;

    Vector2 m_vDir = Vector2(1.f,1000.f);

    float m_fTheta = 1;
public:
    virtual void Init(float px, float py, float sx, float sy, wstring _name);
    virtual void Update();
    virtual void Render(HDC hdc);
    virtual void OnCollision(Collider* other);
    virtual void OnCollisionEnter(Collider* other);
    virtual void OnCollisionExit(Collider* other);
    virtual CObject* Clone() {
        return new Misille(*this);
    }

    void SetDir(float fTheta);
    void SetVDir(Vector2 v);

    Misille();
    ~Misille();
};

