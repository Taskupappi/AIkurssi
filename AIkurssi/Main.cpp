
#include <Windows.h>

#include "StateMachine.h"


bool keyPressed(int key)
{
	Sleep(100);
	return (GetAsyncKeyState(key) & 0x8000);
}


int main()
{
	int exit = 0;
	StateMachine sm;

	

		std::cout << "what would you like to do?" << std::endl;
		std::cout << "1: sends coin -event" << std::endl;
		std::cout << "2: sends pass -event" << std::endl;
		std::cout << "3: sends reset -event" << std::endl;
		std::cout << "4: sends ready -event" << std::endl;
		std::cout << "5: get gate state" << std::endl;
		std::cout << "6: exit" << std::endl;

		while (exit == 0)
		{

			if (keyPressed(0x31))
			{
				sm.coin();
			}
			else if (keyPressed(0x32))
			{
				sm.pass();
			}
			else if (keyPressed(0x33))
			{
				sm.reset();
			}
			else if (keyPressed(0x34))
			{
				sm.ready();
			}
			else if (keyPressed(0x35))
			{
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
