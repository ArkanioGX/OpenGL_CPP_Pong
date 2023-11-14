#pragma once
class Timer
{
public:
	Timer();
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;

	unsigned int computeDelayTime();

	void delayTime();

private:
	const static unsigned int FPS = 60;
	const static unsigned int FPS_DELAY = 1000 / FPS;
	const unsigned int MAX_DT = 50;

	unsigned int frameStart;

	unsigned int lastFrame;

	unsigned int frameTime;
};

