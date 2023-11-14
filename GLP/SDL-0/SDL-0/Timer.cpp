#include "Timer.h"
#include <SDL_timer.h>
#include <algorithm>

Timer::Timer() : frameStart(0), lastFrame(0), frameTime(0)
{
}

unsigned int Timer::computeDelayTime()
{
	frameStart = SDL_GetTicks();
	unsigned int dt = frameStart - lastFrame;
	lastFrame = frameStart;
	return std::min(dt,MAX_DT);
}

void Timer::delayTime()
{
	frameTime = SDL_GetTicks() - frameStart;
	if (frameTime < FPS_DELAY) {
		SDL_Delay(FPS_DELAY - frameTime);
	}
}

