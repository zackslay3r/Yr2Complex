#pragma once
#include <mutex>
#include "SFML/Network.hpp"
#include "Algorthims.h"
#include "dllmain.h"

// This is the clientDetails class.
// check client will contain one of these for each client within the server in order to be able to correctly link sockets, mutex's and a copy of Algorthims.
class DLL ClientDetails
{
public:
	ClientDetails();
	
	~ClientDetails();

	sf::TcpSocket clientSocket;
	std::mutex clientMutex;
	Algorthims* clientAlgorithims;

};

