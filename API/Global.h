#pragma once
#include"CTime.h"
#include<vector>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<map>

#pragma comment(lib,"Msimg32.lib")

using namespace std;

struct Vector2 {
	float x;
	float y;



public:
	Vector2():x(0.f),y(0.f){}

	Vector2(float px,float py):x(px),y(py){}

	Vector2(int px, int py) :x(px), y(py){}

	Vector2(POINT pt):x((float)pt.x),y((float)pt.y){}

	Vector2 operator = (POINT pt) {
		x = (float)pt.x;
		y = (float)pt.y;
		return Vector2((float)pt.x, (float)pt.y);
	}

	Vector2& operator += (Vector2 vec) {
		vec.x += x;
		vec.y += y;
		return vec;
	}

	Vector2 operator * (int i) {
		return Vector2(x * (float)i, y * (float)i);
	}

	Vector2 operator * (float i) {
		return Vector2(x * i, y * i);
	}

	Vector2 operator / (float i) {
		assert(!(0.f == i));
		return Vector2(x / i, y / i);
	}

	Vector2 operator + (Vector2 vec) {
		return Vector2(x + vec.x, y + vec.y);
	}

	Vector2 operator - (Vector2 vec) {
		return Vector2(x - vec.x, y - vec.y);
	}

	float Distance() {
		return sqrt(x * x + y * y);
	}

	Vector2& Normalize() {
		float len = Distance();

		assert(len != 0.f);
		x /= len;
		y /= len;

		return *this;
	}
};

#define DeltaTime CTime::getInstance()->DeltaTime_d()
#define fDeltaTime CTime::getInstance()->DeltaTime_f()

#define KEY_CHECK(key,state) KeyManager::getInstance()->GetKeyState(key) == state

#define PI 3.1415926535f;

enum class GROUP_TYPE {
	DEFAULT,

	PLAYER,
	JEWEL,
	BUTTON,


	END
};

enum class SCENE_TYPE {
	MAIN,
	START,
	TOOL,
	STAGE01,

	END
};

enum class BRUSH_TYPE {
	HOLLOW,
	END
};

enum class PEN_TYPE {
	RED,
	GREEN,
	BLUE,
	END
};

enum class EVENT_TYPE {
	CREATE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,


	END
};