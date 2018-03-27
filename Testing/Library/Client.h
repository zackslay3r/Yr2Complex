#pragma once
#include <SFML/Network.hpp>
#include <iostream>
class Client
{
public:
	Client();
	~Client();
	bool ClientStuff(sf::TcpSocket& socket, std::string IPADDRESS, short PORT);
};

