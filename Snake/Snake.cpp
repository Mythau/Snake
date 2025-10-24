#include <chrono>
#include <iostream>
#include <windows.h>
#include <thread>
#include "Header.h"


bool running = true;

int main()
{
	
	while (running)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(WaitPeriod));
	};

}
