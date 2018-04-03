#include "Client.h"



Client::Client()
{
}


Client::~Client()
{
}



bool Client::ClientStuff( std::string IPADDRESS, short PORT)
{
	{
		if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected\n";
			system("pause");
			return true;
		}
		return false;
	}
}
