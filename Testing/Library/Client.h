#pragma once
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
class Client
{
public:
	Client();
	~Client();
	bool ClientConnection(std::string IPADDRESS, short PORT);
	void ClientChat();
	void getInput();
	sf::TcpSocket socket;
	bool isConnected;
	sf::Mutex ClientMutex;
	bool quit = false;
};

