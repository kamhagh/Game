#include "Clock.h"


bool Clock::initialize(){

	QueryPerformanceFrequency(&timeFrequency);
	QueryPerformanceFrequency(&timeLastFrame);

	return true;
}

bool Clock::shutdown(){

	return true;
}

void Clock::newFrame(){

	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);
	LARGE_INTEGER delta;
	delta.QuadPart = thisTime.QuadPart - timeLastFrame.QuadPart;
	deltaTime = ((float)delta.QuadPart) / (timeFrequency.QuadPart);

	timeLastFrame.QuadPart = thisTime.QuadPart;
}

float Clock::timeElapsedLastFrame() const{

	return deltaTime;
}