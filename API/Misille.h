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
    virtual void Update();
    virtual void Render(HDC hdc);

    void SetDir(float fTheta);
    void SetVDir(Vector2 v);

    Misille();
    ~Misille();
};

