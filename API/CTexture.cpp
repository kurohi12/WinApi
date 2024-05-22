#include "CTexture.h"
#include "CCore.h"

void CTexture::Load(const wstring& strFile)
{
	m_bit = (HBITMAP)LoadImage(nullptr, strFile.c_str(),IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_bit);


	m_hdc = CreateCompatibleDC(CCore::getInstance()->GetHDC());

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hdc, m_bit);
	DeleteObject(hPrevBit);

	
	GetObject(m_bit, sizeof(BITMAP), &bInfo);

}

UINT CTexture::Width()
{
	return bInfo.bmWidth;
}

UINT CTexture::Height()
{
	return bInfo.bmHeight;
}

HDC CTexture::GetUseDC()
{
	return m_hdc;
}

CTexture::CTexture()
{
	m_hdc = NULL;
	m_bit == NULL;
}

CTexture::~CTexture()
{
}
