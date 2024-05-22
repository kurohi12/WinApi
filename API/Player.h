#pragma once
#include "CObject.h"

class Player :
    public CObject
{
public:
    virtual void Init(float px, float py, float sx, float sy);
    virtual void Update();
    virtual void Render(HDC hdc);
    virtual void Release();

private:
    CTexture* headTex = NULL;
    void CreateMissile();
};

