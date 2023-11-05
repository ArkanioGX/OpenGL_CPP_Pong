#pragma once
#include "Drawable.h"
class PongBar
{
	Drawable draw;
	float x, y;
	float ysize;
	
public:

	PongBar();

	void update();
};

