#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "Rectangle.h"
#include "PongBall.h"
#include "Timer.h"
#include "PongBar.h"
using namespace std;
//#define GLEW_STATIC

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded!\n";
	}
	///////////SETTING UP SDL/////////////
	//Create a simple window
	int width = 800;
	int height = 600;
	unsigned int center = SDL_WINDOWPOS_CENTERED;
	SDL_Window* Window = SDL_CreateWindow("My window", center, center, width, height, SDL_WINDOW_OPENGL);
	//SDL_WINDOW_OPENGL is a u32 flag !


	//Create an OpenGL compatible context to let glew draw on it
	SDL_GLContext Context = SDL_GL_CreateContext(Window);

	/////////SETTING UP OPENGL WITH GLEW///
	//Initialize glew
	glewExperimental = GL_TRUE;
	if (glewInit() == GLEW_OK) {
		cout << "Glew initialized successfully\n";
	}

	PongBall* p = new PongBall();
	
	int dP = 0;

	int dIA = 0;
	
	PongBar* bIA = new PongBar(0.8,0.02,0.4,&dIA);

	PongBar* bPl= new PongBar(-0.8, 0.02, 0.4, &dP);

	p->setIA(bIA);
	p->setPlayer(bPl);

	bool isRunning = true;

	Timer timer;
	float dt = 0;

	bool dPressed = false;
	bool uPressed = false;

	bool IAMoving = true;

	while (isRunning) {
		float dt(timer.computeDelayTime() / 1000.f);
		// Inputs
		//dP = 0;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
				/* Look for a keypress */

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_UP) {
					// Up Arrow
					uPressed = true;
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					// Down Arrow
					dPressed = true;
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_UP) {
					// Up Arrow
					uPressed = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					// Down Arrow
					dPressed = false;
				}
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
		
		//IA Controls
		{
			if (IAMoving) {
				if (p->getY() < (bIA->getY()+bIA->getHeight()/2)) {
					dIA = -1;
				}
				else if (p->getY() > (bIA->getY() + bIA->getHeight() / 2)) {
					dIA = 1;
				}

				if (fabsf(p->getY() - (bIA->getY() + bIA->getHeight() / 2)) < 0.15) {
					IAMoving = false;
					dIA = 0;
				}
			}
			else {
				if (fabsf(p->getY() - (bIA->getY() + bIA->getHeight() / 2)) > 0.25) {
					IAMoving = true;
				}
			}
		}

		dP = uPressed - dPressed;

		p->update(dt);
		bIA->update(dt);
		bPl->update(dt);

		

		Rectangle::drawAll();
		
		SDL_GL_SwapWindow(Window); // Swapbuffer

		timer.delayTime();
	}

	std::cin.get();
	return 0;
}