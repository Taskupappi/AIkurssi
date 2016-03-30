#include "GateState.h"

GateState::GateState()
{
	id = 0;
}

GateState::GateState(int x)
{
	id = x;
}

GateState::~GateState()
{

}

int GateState::coin()
{
	return 0;
}

int GateState::pass()
{
	return 0;
}

int GateState::reset()
{
	return 0;
}

int GateState::ready()
{
	return 0;
}

int GateState::getId()
{
	return id;
}