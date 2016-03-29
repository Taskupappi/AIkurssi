
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
				sm.getState();
				if (info == 1)
					std::cout << "gate is locked!" << std::endl;
				else if (info == 2)
					std::cout << "gate is unlocked" << std::endl;
				else if (info == 3)
					std::cout << "gate is in violation state" << std::endl;
				else
					std::cout << "error occured while trying to get gate state" << std::endl;

				printOption();
			}
			else if (keyPressed(0x36))
			{
				exit = 1;
			}
		}


		system("PAUSE");
	
		/*if (exit != 0)
			return 0;*/
}

