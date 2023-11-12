#include "Timer.h"
#include <SDL_timer.h>
#include <algorithm>

Timer::Timer() : frameStart(0), lastFrame(0)
{
}

unsigned int Timer::computeDelayTime()
{
	frameStart = SDL_GetTicks();
	unsigned int dt = frameStart - lastFrame;
	lastFrame = frameStart;
	return dt;
}
