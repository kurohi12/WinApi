#pragma once
#include"CObject.h"
class Misille :
    public CObject
{
private:
    float m_dir = 1;

    float m_fTheta;
public:
    virtual void Update();
    virtual void Render(HDC hdc);

    void SetDir(float fTheta);

    Misille();
    ~Misille();
};

