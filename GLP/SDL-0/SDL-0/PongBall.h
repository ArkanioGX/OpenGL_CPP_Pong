#pragma once
#include "Drawable.h"
class PongBall
{
	Drawable* draw;
	float x, y;
	float xspeed ,yspeed;
	float maxSpeed;
public:

	PongBall();

	void update();
};

