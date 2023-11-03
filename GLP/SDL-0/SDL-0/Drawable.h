#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <SDL.h>
#include <glew.h>

using namespace std;

class Drawable
{
	static vector<Drawable*> drawableList;

	float vertices[64];
	
	unsigned int vao, vbo, shProg;

	void InsertDrawableInList(Drawable* d);

	void setupShaderProgram(string v, string f);
	
public:

	Drawable();
	Drawable(float v[]);
	Drawable(float v[], std::string shV, std::string shF);
	Drawable(float v[], unsigned int sh);

	void draw();

	static void drawAll();

	string LoadShader(string sh);

	unsigned int getShaderProgram() {
		return shProg;
	}
};

