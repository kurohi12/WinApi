#pragma once
#include "CResource.h"
class CTexture :
    public CResource
{

private:
    HDC m_hdc = nullptr;
    HBITMAP m_bit = NULL;

public:
    void Load(const wstring& strFile);

    CTexture();
    ~CTexture();
};

