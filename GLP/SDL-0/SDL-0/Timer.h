#pragma once
class Timer
{
public:
	Timer();
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;

	unsigned int computeDelayTime();


private:
	unsigned int frameStart;

	unsigned int lastFrame;

};

