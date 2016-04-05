#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <iostream>

#include "StateMachineStates.h"
#include "SteinsGate.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
	void coin();
	void pass();
	void reset();
	void ready();
	int getState();

	void setState(int state);
private:
	SteinsGate gate;

};
#endif