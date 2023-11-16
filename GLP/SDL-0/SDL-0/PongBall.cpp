#include "PongBall.h"

# define M_PI          3.141592653589793238462643383279502884L /* pi */


void PongBall::update(float dt) {
	x += xspeed * dt;
	y += yspeed * dt;
	int vertexOffsetLocation = glGetUniformLocation(draw->getShaderProgram(), "objectPos");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexOffsetLocation,x,y,0);

	

	if (x+sizeX > 1 || x-sizeX < -1) {
		x = xspeed*0.3; //Reset Pos in center
		xspeed *= -1;
		
	}

	if (y+sizeY > 1 || y < -1) { //Bounce on the Y limit of the screen
		yspeed *= -1;
		y = fminf(1 - sizeY, fmaxf(y, -1 + sizeY));
	}

	if (getCollision(pPl)) { //Checks the collision with the player bar
		x = pPl->getX() + pPl->getWidth() / 2 + sizeX / 2; //Reset Pos

		float barBallRatio = fabsf(y - pPl->getY()) / pPl->getHeight();
		int Degree = -70 + (barBallRatio * 130);
		xspeed = cos(Degree * M_PI / 180);
		yspeed = sin(Degree * M_PI / 180);
	}

	if (getCollision(pIA)) { //Checks collsion with the IA Bar
		x = pIA->getX() - pIA->getWidth() / 2 - sizeX; //Reset
		
		float barBallRatio = fabsf(y - pIA->getY()) / pIA->getHeight();
		int Degree = 115 + ((1-barBallRatio) * 130);
		xspeed = cos(Degree * M_PI / 180);
		yspeed = sin(Degree * M_PI / 180);
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

bool PongBall::getCollision(PongBar* pb) //Check for collsion with pong bar
{
	return (x + sizeX >= pb->getX() &&
		x <= pb->getX() + pb->getWidth() &&
		y + sizeY >= pb->getY() &&
		y <= pb->getY() + pb->getHeight());
}

PongBall::PongBall() {
	draw = new Rectangle("v_ball.shader", "f_ball.shader");
	x = 0;
	y = 0;
	xspeed = 1;
	yspeed = 0;
	sizeX = 0.05*0.75;
	sizeY = 0.05;
	maxSpeed = 1;

	int vertexSize = glGetUniformLocation(draw->getShaderProgram(), "objectSize");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexSize, sizeX,sizeY, 1);
}
