#pragma once
#include <vector>
#include <SFML/Network.hpp>
#include <iostream>
#include <atomic>
#include "Algorthims.h"
#include <thread>
#include "ClientDetails.h"
#include <mutex>
#include "dllmain.h"
class DLL Server
{
public:
	Server();
	~Server();
	void ServerStuff();
	void AnswerQuestion(ClientDetails* clientDetails, std::string buffer);
	void SendMessages();

	short PORT = 2501;
	// an atomic is a template type that no matter if two threads are accessing, it will sort it out.
	std::atomic<bool> listenerRun;
	
	std::string finalOutput;
	
	sf::SocketSelector selector;
	std::vector<std::thread> threads;
protected:
	


	//std::vector<sf::TcpSocket*> sockets;
	std::vector<sf::Mutex> Detailsmutex;
	std::vector<ClientDetails*> details;

};

