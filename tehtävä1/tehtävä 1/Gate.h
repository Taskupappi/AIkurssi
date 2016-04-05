#ifndef GATE_H
#define GATE_H

#include <iostream>
#include "EnumStates.h"

class Gate
{
public:
	Gate();
	~Gate();

	void lock();
	void unlock();
	void thankYou();
	void thankYouOff();
	void alarm();
	void resetAlarm();
	void violated();
	void ready();
	//GateState* getState();

	//int getStateValue();//is this needed?
	//void setState(int state);//is this needed?

private:
	//GateState state;
};

#endif