#pragma once
#include "CResource.h"
class CTexture :
    public CResource
{

private:
    HDC m_hdc = nullptr;
    HBITMAP m_bit = NULL;
    BITMAP bInfo = {};

    friend class ResourceManager;

public:
    void Load(const wstring& strFile);
    UINT Width();
    UINT Height();

    HDC GetUseDC();

    CTexture();
    virtual ~CTexture();
};

