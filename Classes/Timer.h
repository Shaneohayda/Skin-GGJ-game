#pragma once

class Timer
{
	unsigned long ticks;
public:
	Timer(void);
	~Timer(void);

	bool loadMedia;
	void start();
	unsigned int getSec();
	unsigned int getMSec();
};
