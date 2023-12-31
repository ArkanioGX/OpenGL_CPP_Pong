#include "Rectangle.h"

vector<Rectangle*> Rectangle::drawableList = {  };

Rectangle::Rectangle() {
	InsertDrawableInList(this);
	setupShaderProgram("v_simple.shader", "f_simple.shader");
}

Rectangle::Rectangle(float x, float y, float w, float h)
{
	InsertDrawableInList(this);
	setupShaderProgram("v_bar.shader", "f_bar.shader");
}



Rectangle::Rectangle( string shV, string shF) {
	InsertDrawableInList(this);
	setupShaderProgram(shV, shF);
}

void Rectangle::InsertDrawableInList(Rectangle* d) {
	drawableList.push_back(d);
}

void Rectangle::setupShaderProgram(string v, string f) {
	//glUseProgram(0);
	//VBO Setup
	{
		//Pass how many buffers should be created and the reference of the ID to get the value set
		glGenBuffers(1, &vbo);
		string vs = LoadShader(v);
		const char* vertexShaderSource = vs.c_str();

		string fs = LoadShader(f);
		const char* fragmentShaderSource = fs.c_str();

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);


		//now that we have a vertex shader, let�s put the code text inside
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);


		//aaaaand� Compile !
		glCompileShader(vertexShader);


		//Do the same with the fragment shader !
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);


		shProg = glCreateProgram();



		//now attach shaders to use to the program
		glAttachShader(shProg, vertexShader);
		glAttachShader(shProg, fragmentShader);

		//and link it 
		glLinkProgram(shProg);

		//now that the program is complete, we can use it 
		glUseProgram(shProg); 
	}

	//VAO Setup
	{
		glUseProgram(shProg);
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);


		//Binds the buffer linked to this ID to the vertex array buffer to be rendered. Put 0 instead of vbo to reset the value.
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		//Finally send the vertices array in the array buffer 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//Shader to use next
		glUseProgram(shProg);

		//VAO to use next
		glBindVertexArray(vao);
	}
}

void Rectangle::draw() {
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 3);
}

void Rectangle::drawAll() {
	for (Rectangle* d : drawableList)
	{
		glUseProgram(d->shProg);
		d->draw();
		glUseProgram(0);
	}
}

string Rectangle::LoadShader(string fileName) {
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.fail()) {
		cerr << "Error - failed to open " << fileName << endl;
	}
	string fileText = "";
	string line = "";
	while (getline(myFile, line)) {
		fileText += line + '\n';
	}

	myFile.close();
	return fileText;
}