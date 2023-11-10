#include "PongBall.h"

void PongBall::update() {
	x += xspeed;
	y += yspeed;
	int vertexOffsetLocation = glGetUniformLocation(draw->getShaderProgram(), "objectPos");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexOffsetLocation,x,y,0);

	if (x+sizeX > 1 || x-sizeX < -1) {
		xspeed *= -1;
	}

	if (y+sizeY > 1 || y-sizeY < -1) {
		yspeed *= -1;
	}
}

PongBall::PongBall() {
	float s = 1;
	vector<float> v = {
		0,0,0,
		float(cos(0))*s,float(sin(0))*s,0,
		float(cos(0.785398))* s,float(sin(0.785398))* s,0,

		0,0,0,
		float(cos(0.785398))* s,float(sin(0.785398))* s,0,
		float(cos(1.5708))* s,float(sin(1.5708))* s,0,

		0,0,0,
		float(cos(1.5708))* s,float(sin(1.5708))* s,0,
		float(cos(2.35619))* s,float(sin(2.35619))* s,0,

		0,0,0,
		float(cos(2.35619))* s,float(sin(2.35619))* s,0,
		float(cos(3.14159))* s,float(sin(3.14159))* s,0,

		0,0,0,
		float(cos(3.14159))* s,float(sin(3.14159))* s,0,
		float(cos(3.92699))* s,float(sin(3.92699))* s,0,

		0,0,0,
		float(cos(3.92699))* s,float(sin(3.92699))* s,0,
		float(cos(4.71239))* s,float(sin(4.71239))* s,0,

		0,0,0,
		float(cos(4.71239))* s,float(sin(4.71239))* s,0,
		float(cos(5.49779))* s,float(sin(5.49779))* s,0,

		0,0,0,
		float(cos(5.49779))* s,float(sin(5.49779))* s,0,
		float(cos(0)) * s,float(sin(0))* s,0
	};
	draw = new Drawable(v,"v_ball.shader", "f_ball.shader");
	x = 0;
	y = 0;
	xspeed = 0.01;
	yspeed = 0.005;
	sizeX = 0.1*0.75;
	sizeY = 0.1;

	int vertexOffsetLocation = glGetUniformLocation(draw->getShaderProgram(), "objectSize");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexOffsetLocation, sizeX,sizeY, 1);
}