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

	void getInput();
	sf::TcpSocket socket;
	bool isConnected;
	sf::Mutex ClientMutex;
	bool quit = false;
	bool inputCompleted;
	void sendClientRequest(sf::Packet packet);
	bool EstablishConnection();
	bool stillConnected = true;
	sf::Packet sendMessage;

	std::string msgSend;
	std::string stringToSave;
	std::string SolutionDNA;

};

