#pragma once
#include"CTime.h"

struct Vector2 {
	float x;
	float y;

public:
	Vector2():x(0.f),y(0.f){}

	Vector2(float px,float py):x(px),y(py){}

	Vector2(int px, int py) :x(px), y(py){}
};

#define DeltaTime CTime::getInstance()->DeltaTime_d()
#define fDeltaTime CTime::getInstance()->DeltaTime_f()