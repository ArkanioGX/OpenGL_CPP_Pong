#include "PongBall.h"

void PongBall::update() {
	x += xspeed;
	y += yspeed;
	int vertexOffsetLocation = glGetUniformLocation(draw->getShaderProgram(), "offset");
	glUseProgram(draw->getShaderProgram());
	glUniform3f(vertexOffsetLocation,x,y,0);

}

PongBall::PongBall() {
	float s = 0.5;
	float v[] = {
		0,0,0,
		cos(0),sin(0),0,
		1,0,0,
	};
	draw = new Drawable(v);
	x = 0;
	y = 0;
}