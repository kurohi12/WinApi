#pragma once
#include"CTime.h"
#include<vector>
#include<stdio.h>
#include<math.h>

using namespace std;

struct Vector2 {
	float x;
	float y;

public:
	Vector2():x(0.f),y(0.f){}

	Vector2(float px,float py):x(px),y(py){}

	Vector2(int px, int py) :x(px), y(py){}

	Vector2(POINT pt):x((float)pt.x),y((float)pt.y){}

	Vector2& operator = (POINT pt) {
		x = (float)pt.x;
		y = (float)pt.y;
	}
};

#define DeltaTime CTime::getInstance()->DeltaTime_d()
#define fDeltaTime CTime::getInstance()->DeltaTime_f()

#define KEY_CHECK(key,state) KeyManager::getInstance()->GetKeyState(key) == state

#define PI 3.1415926535f;

enum class GROUP_TYPE {
	DEFAULT,

	PLAYER,



	END
};

enum class SCENE_TYPE {
	START,

	STAGE01,

	END
};