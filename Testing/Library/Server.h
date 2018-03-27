#pragma once
#include <vector>
#include <SFML/Network.hpp>
#include <iostream>
class Server
{
public:
	Server();
	~Server();
	void ServerStuff(short PORT);

protected:
 
	std::vector<sf::Socket*> sockets;
};

