#include "CTexture.h"

void CTexture::Load(const wstring& strFile)
{
	m_bit = (HBITMAP)LoadImage(nullptr, strFile.c_str(),IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	assert(m_bit);
}

CTexture::CTexture()
{
	m_hdc = NULL;
	m_bit == NULL;
}

CTexture::~CTexture()
{
}
