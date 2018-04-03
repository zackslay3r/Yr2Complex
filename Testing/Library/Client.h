#pragma once
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
class Client
{
public:
	Client();
	~Client();
	bool ClientStuff(std::string IPADDRESS, short PORT);
	sf::TcpSocket socket;
};

