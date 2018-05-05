#pragma once
#include <mutex>
#include "SFML/Network.hpp"
#include "Algorthims.h"
#include "dllmain.h"

class DLL ClientDetails
{
public:
	ClientDetails();
	
	~ClientDetails();

	sf::TcpSocket clientSocket;
	std::mutex clientMutex;
	Algorthims* clientAlgorithims;

};

