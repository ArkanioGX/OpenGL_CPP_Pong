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
	draw = new Drawable(v);
	x = 0;
	y = 0;
}