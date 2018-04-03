#include "Server.h"
#include <thread>


int main()
{

	std::thread ListenerThread;
	Server* s = new Server;

	sf::Thread* thread = 0;

	s->PORT = 2501;
	// this is a function pointer
	// function as a variable.
	ListenerThread = std::thread([s] {s->ServerStuff(); });
	//s->ServerStuff();

	while (true)
	{
	}

	return 0;
}