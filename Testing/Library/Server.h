#pragma once
#include <vector>
#include <SFML/Network.hpp>
#include <iostream>
#include <atomic>
class Server
{
public:
	Server();
	~Server();
	void ServerStuff();
	void RecieveMessages();
	short PORT = 2501;
	// an atomic is a template type that no matter if two threads are accessing, it will sort it out.
	std::atomic<bool> listenerRun;
	sf::SocketSelector selector;
protected:
	


	std::vector<sf::TcpSocket*> sockets;
};

