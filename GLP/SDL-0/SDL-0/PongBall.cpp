#include "PongBall.h"

void PongBall::update(float dt) {
	x += xspeed * dt;
	y += yspeed * dt;
	int vertexOffsetLocation = glGetUniformLocation(draw->getShaderProgram(), "objectPos");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexOffsetLocation,x,y,0);

	

	if (x+sizeX > 1 || x-sizeX < -1) {
		x = xspeed*0.3; //Reset
		xspeed *= -1;
		
	}

	if (y+sizeY > 1 || y < -1) {
		yspeed *= -1;
		y = fminf(1 - sizeY, fmaxf(y, -1 + sizeY));
	}

	if (getCollision(pPl)) {
		x = pPl->getX() + pPl->getWidth() / 2 + sizeX / 2; //Reset
		xspeed *= -1;
	}

	if (getCollision(pIA)) {
		x = pIA->getX() - pIA->getWidth() / 2 - sizeX; //Reset
		xspeed *= -1;
	}
}

float PongBall::getY()
{
	return y;
}

void PongBall::setPlayer(PongBar* pbPl)
{
	pPl = pbPl;
}

void PongBall::setIA(PongBar* pbIA)
{
	pIA = pbIA;
}

bool PongBall::getCollision(PongBar* pb)
{
	if (x + sizeX >= pb->getX() &&     // r1 right edge past r2 left
		x <= pb->getX() + pb->getWidth() &&       // r1 left edge past r2 right
		y + sizeY >= pb->getY() &&       // r1 top edge past r2 bottom
		y <= pb->getY() + pb->getHeight()) {       // r1 bottom edge past r2 top
		return true;
	}
	return false;
}

PongBall::PongBall() {
	draw = new Rectangle("v_ball.shader", "f_ball.shader");
	x = 0;
	y = 0;
	xspeed = 1;
	yspeed = 0.75;
	sizeX = 0.05*0.75;
	sizeY = 0.05;

	int vertexSize = glGetUniformLocation(draw->getShaderProgram(), "objectSize");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexSize, sizeX,sizeY, 1);
}
