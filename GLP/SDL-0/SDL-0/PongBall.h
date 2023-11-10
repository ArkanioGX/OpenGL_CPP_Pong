#pragma once
#include "Drawable.h"
class PongBall
{
	Drawable* draw;
	float x, y;
	float xspeed ,yspeed;
	float maxSpeed;
	float sizeX,sizeY;
public:

	PongBall();

	void update();
};

