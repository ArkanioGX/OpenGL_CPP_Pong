#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <SDL.h>
#include <glew.h>

using namespace std;

class Rectangle
{
	static vector<Rectangle*> drawableList;

	float vertices[18] = {
		1,1,0,
		0,1,0,
		0,0,0,

		1,1,0,
		1,0,0,
		0,0,0
	};
	
	unsigned int vao, vbo, shProg;

	void InsertDrawableInList(Rectangle* d);

	void setupShaderProgram(string v, string f);
	
public:

	Rectangle();
	Rectangle(float x, float y, float w, float h);
	Rectangle( std::string shV, std::string shF);

	void draw();

	static void drawAll();

	string LoadShader(string sh);

	unsigned int getShaderProgram() {
		return shProg;
	}
};

