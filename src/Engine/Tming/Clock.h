#pragma once
#include <Windows.h>

class Clock{

public:
	
public:

	bool initialize();
	bool shutdown();
	void newFrame();
	float timeElapsedLastFrame() const; // delta distance of each frame

private:

	LARGE_INTEGER timeLastFrame;
	LARGE_INTEGER timeFrequency;
	LARGE_INTEGER deltaLastFrame;
	float deltaTime;
};

