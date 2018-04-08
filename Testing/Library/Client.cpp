#include "Client.h"



Client::Client()
{
	isConnected = false;
}


Client::~Client()
{
}



bool Client::ClientConnection( std::string IPADDRESS, short PORT)
{
	

	{
		if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected\n";
			system("pause");
			isConnected = true;
			return true;
		}
		return false;
	}
}

void Client::ClientChat()
{
	while()
}

void Client::getInput()
{
	std::string s;
	std::cout << "\nEnter \"exit\" to quit or message to send: ";
	getline(std::cin, s);
	if (s == "exit")
	{
		quit = true;
	}
	ClientMutex.lock();
	msgSend = s;
	globalMutex.unlock();
}


