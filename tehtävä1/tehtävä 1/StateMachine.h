#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "Gate.h"
#include "GateState.h"
#include "EnumStates.h"

#include "LockedState.h"
#include "UnlockedState.h"
#include "ViolationState.h"

#include <vector>

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
	void coin();
	void pass();
	void reset();
	void ready();

	GateState* getState();
	void setState(GateState *state);
	void setGateState(const int gateState);

protected:
	GateState *currentState;
	Gate *gate;
private:
};
#endif