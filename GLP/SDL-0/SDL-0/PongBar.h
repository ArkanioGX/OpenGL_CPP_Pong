#pragma once
#include "Rectangle.h"
class PongBar
{
	Rectangle* draw;
	float x, y;
	float sizeX;
	float sizeY;
	float speed;

	int* dir;
	
public:

	PongBar(float xP,float w, float h, int* d);

	void update(float dt);

	float getX();
	float getY();
	float getHeight();
	float getWidth();
};

