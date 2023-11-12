#include "PongBar.h"
#include <vector>

PongBar::PongBar(float xP, float w,float h, int* d):dir(d)
{
	x = xP;
	y = 0;
	sizeY = h;
	sizeX = w;
	speed = 0.7;
	draw = new Rectangle("v_bar.shader", "f_bar.shader");

	int vertexSize = glGetUniformLocation(draw->getShaderProgram(), "objectSize");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexSize, sizeX, sizeY, 1);
}

void PongBar::update(float dt)
{
	y += *dir * speed * dt;
	y = fminf(1 - sizeY, fmaxf(y, -1));
	int vertexOffsetLocation = glGetUniformLocation(draw->getShaderProgram(), "objectPos");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexOffsetLocation, x, y, 0);
}

float PongBar::getX()
{
	return x;
}

float PongBar::getY()
{
	return y;
}

float PongBar::getHeight()
{
	return sizeY;
}

float PongBar::getWidth()
{
	return sizeX;
}


