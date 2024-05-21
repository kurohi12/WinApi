#pragma once
#include"Global.h"
#include"Singleton.h"


enum KEYSTATE {
	KEYUP,
	KEYDOWN,
	HOLD,
	NONE
};

enum KEYLIST {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,

	ENTER,
	SPACE,
	ESC,

	LAST
};

struct KeyInfo {
	KEYSTATE keyState; //키 상태
	bool prev; //이전 프레임에 눌렸는가
};

class KeyManager : public Singleton<KeyManager>
{
private :
	vector<KeyInfo> m_vecKey;


public:
	void Init();
	void Update();
	KEYSTATE GetKeyState(KEYLIST key);
	
};

