#pragma once
#include <mutex>
#include "SFML\Network.hpp"
#include "Algorthims.h"
class ClientDetails
{
public:
	ClientDetails();
	
	~ClientDetails();

	sf::TcpSocket clientSocket;
	std::mutex clientMutex;
	Algorthims* clientAlgorithims;

};

