#ifndef VIOLATIONSTATE_H
#define VIOLATIONSTATE_H

#include <iostream>
#include "EnumStates.h"

class GateState;

class ViolationState : public GateState
{
public:
	ViolationState() : GateState(VIOLATION)
	{
	};
	~ViolationState(){};

	int coin()
	{
		return VIOLATION;
	}

	int pass()
	{
		return VIOLATION;
	}

	int reset()
	{
		return RESETALARM;
	}

	int ready()
	{
		return READY;
	}
};

#endif