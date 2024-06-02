#include "KeyManager.h"

#include"CCore.h"

int arrVK[(int)KEYLIST::LAST] = {
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',

	VK_RETURN,
	VK_SPACE,
	VK_ESCAPE,
	VK_LBUTTON,
	VK_RBUTTON,

	
	/*LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,

	ENTER,
	SPACE,
	ESC,

	LAST*/
};

void KeyManager::Init()
{
	for (int i = 0; i < (int)KEYLIST::LAST; ++i) {
		m_vecKey.push_back(KeyInfo{ KEYSTATE::NONE,false });
	}
}

void KeyManager::Update()
{
	//윈도우 포커싱
	HWND mainHwnd = CCore::getInstance()->GetHwnd();
	HWND hwnd = GetFocus(); // 현재 포커싱 핸들

	if (hwnd == mainHwnd) {
		for (int i = 0; i < (int)KEYLIST::LAST; ++i) {
			if (GetAsyncKeyState(arrVK[i]) & 0x8000) {
				if (m_vecKey[i].prev) {
					m_vecKey[i].keyState = KEYSTATE::HOLD;
				}
				else {
					m_vecKey[i].keyState = KEYSTATE::KEYDOWN;
				}
				m_vecKey[i].prev = true;
			}
			else {
				if (m_vecKey[i].prev) {
					m_vecKey[i].keyState = KEYSTATE::KEYUP;
				}
				else {
					m_vecKey[i].keyState = KEYSTATE::NONE;
				}
				m_vecKey[i].prev = false;
			}
		}
	}
	else {
		for (int i = 0; i < (int)KEYLIST::LAST; ++i) {
			m_vecKey[i].prev = false;
			if (m_vecKey[i].keyState == KEYSTATE::KEYDOWN || m_vecKey[i].keyState == KEYSTATE::HOLD)
				m_vecKey[i].keyState = KEYSTATE::KEYUP;
			else if (m_vecKey[i].keyState == KEYSTATE::KEYUP)
				m_vecKey[i].keyState == KEYSTATE::NONE;
		}
	}

	POINT ptPos = {};
	GetCursorPos(&ptPos);


	ScreenToClient(CCore::getInstance()->GetHwnd(), &ptPos);

	m_mousePos = Vector2((float)ptPos.x,(float)ptPos.y );
	
}

KEYSTATE KeyManager::GetKeyState(KEYLIST key)
{
	return m_vecKey[(int)key].keyState;
}


