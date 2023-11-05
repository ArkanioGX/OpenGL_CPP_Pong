#include "PongBall.h"

void PongBall::update() {
	x += xspeed;
	y += yspeed;
	int vertexOffsetLocation = glGetUniformLocation(draw.getShaderProgram(), "offset");
	glUseProgram(draw.getShaderProgram());
	glUniform3f(vertexOffsetLocation,x,y,0);

}

PongBall::PongBall() {
	x = 0;
	y = 0;
}