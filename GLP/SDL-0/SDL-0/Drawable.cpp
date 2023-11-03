#include "Drawable.h"

vector<Drawable*> Drawable::drawableList = {  };

Drawable::Drawable() {
	InsertDrawableInList(this);
	float v[9] = {	-0.2f,-0.2f,0.0f,
					0.2f,-0.2f,0.0f,
					0.0f,0.2f,0.0f};
	std::copy(begin(v), end(v), begin(vertices));
	
	setupShaderProgram("v_simple.shader", "f_rainbow.shader");
}

Drawable::Drawable(float v[]) {
	InsertDrawableInList(this);
	std::copy(v, v + (sizeof(v)/sizeof(float)), begin(vertices));

	setupShaderProgram("v_simple.shader", "f_simple.shader");
}

Drawable::Drawable(float v[], string shV, string shF) {
	InsertDrawableInList(this);
	std::copy(v, v + (sizeof(v) / sizeof(float)), begin(vertices));
	setupShaderProgram(shV, shF);
}

Drawable::Drawable(float v[], unsigned int sh) {
	InsertDrawableInList(this);
	std::copy(v, v + (sizeof(v) / sizeof(float)), begin(vertices));
}

void Drawable::InsertDrawableInList(Drawable* d) {
	drawableList.push_back(d);
}

void Drawable::setupShaderProgram(string v, string f) {
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


		//now that we have a vertex shader, let’s put the code text inside
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);


		//aaaaand… Compile !
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
	glBindVertexArray(vao); }
}

void Drawable::draw() {
	glUseProgram(shProg);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 3);
}

void Drawable::drawAll() {
	for (Drawable* d : drawableList)
	{
		d->draw();
	}
}

string Drawable::LoadShader(string fileName) {
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