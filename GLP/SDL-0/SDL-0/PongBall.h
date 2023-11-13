#pragma once
#include "Rectangle.h"
#include "PongBar.h"
#include <random>
class PongBall
{
	Rectangle* draw;
	float x, y;
	float maxSpeed, xspeed ,yspeed;
	float sizeX,sizeY;

	PongBar* pIA;
	PongBar* pPl;

	bool getCollision(PongBar* pb);

public:

	PongBall();

	void update(float dt);

	float getY();

	void setPlayer(PongBar* pbPl);
	void setIA(PongBar* pbIA);
};

