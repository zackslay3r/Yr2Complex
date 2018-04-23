#include "Server.h"
#include <thread>


int main()
{
	bool validPort = false;
	std::thread ListenerThread;
	Server* s = new Server;

	sf::Thread* thread = 0;


	while (validPort == false)
	{
		std::cout << "Please put a number in between 1 and 5000 for a port number.";
		short tempShort;
		std::cin >> tempShort;
		if (tempShort > 0 || tempShort < 5000)
		{
			s->PORT = tempShort;
			validPort = true;
		}

	}



	//s->PORT = 2501;
	// this is a function pointer
	// function as a variable.
	ListenerThread = std::thread([s] {s->ServerStuff(); });
	//s->ServerStuff();

	while (true)
	{
		s->RecieveMessages();
	}

	return 0;
}