#include "Gate.h"

Gate::Gate()
{
}

Gate::~Gate()
{
}

void Gate::lock()
{
	std::cout << "Gate locked!" << std::endl;
}
void Gate::unlock()
{
	std::cout << "Gate unlocked!" << std::endl;
}
void Gate::thankYou()
{
	std::cout << "Thank you for your donation!" << std::endl;
}
void Gate::thankYouOff()
{
	std::cout << "No more donations ._." << std::endl;
}
void Gate::alarm()
{
	std::cout << "Gate alarm triggered!" << std::endl;
}
void Gate::resetAlarm()
{
	std::cout << "Gate alarm reset!" << std::endl;
}
void Gate::violated()
{
	std::cout << "Gate violated!" << std::endl;
}
void Gate::ready()
{
	std::cout << "Gate is ready!" << std::endl;
	lock();
}
//int getStateValue()
//{
//	//is this needed?
//}
//void setState(int state)
//{
//	//do I need this?
//}