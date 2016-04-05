#ifndef STEINSGATE_H
#define STEINSGATE_H

#include <iostream>

enum State
{
	locked = 1,
	unlocked = 2,
	violation = 3
};

class SteinsGate
{
public:
	SteinsGate();
	~SteinsGate();
	void lock();
	void unlock();
	void thankYou();
	void thankYouOff();
	void alarm();
	void resetAlarm();
	void violation();
	int getState();
	
	void setState(int state);
private:
	int state;
	
};

#endif