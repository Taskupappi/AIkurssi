#include "SteinsGate.h"

SteinsGate::SteinsGate()
{
	state = locked;
}

SteinsGate::~SteinsGate()
{
	//std::cout << "~SteinsGate" << std::endl;
}

void SteinsGate::lock()
{
	std::cout << "gate locked" << std::endl;
}

void SteinsGate::unlock()
{
	std::cout << "gate unlocked" << std::endl;	
}

void SteinsGate::thankYou()
{
	std::cout << "thank you for your donation" << std::endl;
}

void SteinsGate::thankYouOff()
{
	std::cout << "thank you turned off" << std::endl;
}

void SteinsGate::alarm()
{
	std::cout << "alarm triggered" << std::endl;
}

void SteinsGate::resetAlarm()
{
	std::cout << "alarm reset" << std::endl;
}

void SteinsGate::violation()
{
	std::cout << "violation occured!" << std::endl;
}

int SteinsGate::getState()
{
	return state;
}

void SteinsGate::setState(int state)
{
	this->state = state;
}





