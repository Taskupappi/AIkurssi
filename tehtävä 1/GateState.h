#ifndef GATESTATE_H
#define GATESTATE_H

//#include "LockedState.h"
//#include "UnlockedState.h"
//#include "ViolationState.h"

class GateState
{
public:
	GateState();
	GateState(int x);
	~GateState();
	virtual int coin();
	virtual int pass();
	virtual int reset();
	virtual int ready();
	virtual int getId();
protected:
	int id;
private:
};

#endif