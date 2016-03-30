#ifndef UNLOCKEDSTATE_H
#define UNLOCKEDSTATE_H

#include <iostream>
#include "EnumStates.h"

class GateState;

class UnlockedState : public GateState
{
public:
	UnlockedState() : GateState(UNLOCKED)
	{
	};
	~UnlockedState(){};

	int coin()
	{
		return THANKYOU;
	}

	int pass()
	{
		std::cout << "you passed the gate" << std::endl;
		return LOCKED;
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