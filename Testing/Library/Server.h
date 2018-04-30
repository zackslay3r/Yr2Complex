#pragma once
#include <vector>
#include <SFML/Network.hpp>
#include <iostream>
#include <atomic>
#include "Algorthims.h"
#include <thread>
#include "ClientDetails.h"
#include <mutex>
class Server
{
public:
	Server();
	~Server();
	void ServerStuff();
	void AnswerQuestion(ClientDetails* clientDetails, std::string buffer);
	void RecieveMessages();
	short PORT = 2501;
	// an atomic is a template type that no matter if two threads are accessing, it will sort it out.
	std::atomic<bool> listenerRun;
	


	sf::SocketSelector selector;
	std::vector<std::thread> threads;
protected:
	


	//std::vector<sf::TcpSocket*> sockets;
	std::vector<sf::Mutex> Detailsmutex;
	std::vector<ClientDetails*> details;

};

