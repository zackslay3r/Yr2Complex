#pragma once
#include <mutex>
#include "SFML\Network.hpp"
class ClientDetails
{
public:
	ClientDetails();
	
	~ClientDetails();

	sf::TcpSocket clientSocket;
	std::mutex clientMutex;

};

