#include "StateMachine.h"


StateMachine::StateMachine()
{
	gate.lock();
}

StateMachine::~StateMachine()
{

}

void StateMachine::coin()
{
	switch (gate.getState())
	{
	case locked:
	{
		gate.unlock();
		break;
	}
	case unlocked:
	{
		gate.thankYou();
		break;
	}
	case violation:
	{
		gate.violation();
		break;
	}
	default:
		break;
	}
}

void StateMachine::pass()
{
	switch (gate.getState())
	{
	case locked:
	{
		gate.alarm();
		break;
	}
	case unlocked:
	{
		gate.lock();
		break;
	}
	case violation:
	{
		gate.violation();
		break;
	}
	default:
		break;
	}
}

void StateMachine::ready()
{
	gate.resetAlarm();
	gate.lock();
}

void StateMachine::reset()
{

	if (gate.getState() == violation)
	{
		gate.resetAlarm();
		ready();
	}
}

int StateMachine::getState()
{
	return gate.getState();
}

void StateMachine::setState(int state)
{
	gate.setState(state);
}