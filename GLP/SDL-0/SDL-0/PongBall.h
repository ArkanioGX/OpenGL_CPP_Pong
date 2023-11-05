#pragma once
#include "Drawable.h"
class PongBall
{
	Drawable draw;
	float x, y;
	float xspeed = 0.02; float yspeed = 0.01;

public:

	PongBall();

	void update();
};

