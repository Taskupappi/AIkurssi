#ifndef LOCKEDSTATE_H
#define LOCKEDSTATE_H

#include <iostream>
#include "EnumStates.h"

class GateState;

class LockedState : public GateState
{
public:
	LockedState() : GateState(LOCKED)
	{
	};
	
	~LockedState(){};
	
	int coin()
	{
		return UNLOCKED;
	}

	int pass()
	{
		return ALARM;
	}

	int reset()
	{
		return 0;
	}

	int ready()
	{
		return 0;
	}

};

#endif