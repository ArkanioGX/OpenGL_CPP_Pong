#include "PongBall.h"

void PongBall::update() {

	x += xspeed;
	cout << x << endl;
	int vertexOffsetLocation = glGetUniformLocation(draw.getShaderProgram(), "time");
	int vertexOffsetLocation2 = glGetUniformLocation(draw.getShaderProgram(), "resolution");
	glUseProgram(draw.getShaderProgram());
	glUniform1f(vertexOffsetLocation,SDL_GetTicks()/100);
	glUniform2f(vertexOffsetLocation2,500,500);

}

PongBall::PongBall() {
	x = 0;
	y = 0;
}