#include "StateMachine.h"

StateMachine::StateMachine()
{
	this->gate = new Gate();
	gate->lock();
	currentState = new LockedState();
}

StateMachine::~StateMachine()
{
	delete gate;
	delete currentState;
}

void StateMachine::coin()
{
	setGateState(currentState->coin());
}

void StateMachine::pass()
{
	setGateState(currentState->pass());
}

void StateMachine::reset()
{
	if (currentState->getId() == VIOLATION)
	{
		setGateState(currentState->reset());
	}
}

void StateMachine::ready()
{
	if (currentState->getId() == VIOLATION)
	{	
		setGateState(currentState->ready());
		currentState = new LockedState();
	}
}

void StateMachine::setState(GateState *state)
{
	currentState = state;
}

GateState* StateMachine::getState()
{
	return currentState;
}

void StateMachine::setGateState(const int gateState)
{	
	switch (gateState)
	{
		case LOCKED:
		{
			gate->lock();
			currentState = new LockedState();
			break;
		}	
		case UNLOCKED:
		{
			gate->unlock();
			currentState = new UnlockedState();
			break;
		}		
		case VIOLATION:
		{
			gate->violated();
			currentState = new ViolationState();
			break;
		}
		case THANKYOU:
		{
			gate->thankYou();
			break;
		}
		case THANKYOUOFF:
		{
			gate->thankYouOff();
			break;
		}
		case ALARM:
		{
			gate->alarm();
			currentState = new ViolationState();
			break;
		}
		case RESETALARM:
		{
			gate->resetAlarm();
			break;
		}
		case READY:
		{
			gate->ready();
			currentState = new LockedState();
			break;
		}
		default:
			break;
	}	
}