
#include <Windows.h>

#include "StateMachine.h"


bool keyPressed(int key)
{
	return (GetAsyncKeyState(key) & 0x8000);
}

void printOption()
{
	std::cout << "\n" << std::endl;
	std::cout << "what would you like to do?" << std::endl;
	std::cout << "1: sends coin -event" << std::endl;
	std::cout << "2: sends pass -event" << std::endl;
	std::cout << "3: sends reset -event" << std::endl;
	std::cout << "4: sends ready -event" << std::endl;
	std::cout << "5: get gate state" << std::endl;
	std::cout << "6: exit" << std::endl;
	Sleep(100);
}

int main()
{
	int exit = 0;
	StateMachine sm;

	printOption();

	while (exit == 0)
	{

		if (keyPressed(0x31))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			sm.coin();
			printOption();
		}
		else if (keyPressed(0x32))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			sm.pass();
			printOption();
		}
		else if (keyPressed(0x33))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			sm.reset();
			printOption();
		}
		else if (keyPressed(0x34))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			sm.ready();
			printOption();
		}
		else if (keyPressed(0x35))
		{
			std::cout << std::endl;
			std::cout << std::endl;

			int info = 0;
			info = sm.getState()->getId();					
			std::cout << "Gate status code:"<< sm.getState()->getId() << std::endl;
			std::cout << "LOCKED = 1" << std::endl;
			std::cout << "UNLOCKED = 2 " << std::endl;
			std::cout << "VIOLATION = 3 " << std::endl;
			printOption();
		}
		else if (keyPressed(0x36))
		{
			exit = 1;
		}

		
	}
	system("PAUSE");
}