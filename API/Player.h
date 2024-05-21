#pragma once
#include "CObject.h"
class Player :
    public CObject
{
public:
    virtual void Update();
    virtual void Render(HDC hdc);

private:
    void CreateMissile();
};

