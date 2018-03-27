#include "Client.h"



Client::Client()
{
}


Client::~Client()
{
}



bool Client::ClientStuff(sf::TcpSocket& socket, std::string IPADDRESS, short PORT)
{
	{
		if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected\n";
			return true;
		}
		return false;
	}
}
