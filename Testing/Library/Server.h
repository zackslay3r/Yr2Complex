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

// This is the Server class.
// It is responsible for recieving input from a client and using the Algorthims library in order to solve the solution a client has provided.
class DLL Server
{
public:
	// Constructor

	Server();
	// Destructor
	~Server();
	// ServerStuff
	// THis function is responsible for enabling clients to connect with the server.
	// it returns void and has no parameters.
	void ServerStuff();
	// AnswerQuestion()
	// This function is responsible for sorting out the problem statement.
	// It returns type void and takes 2 parameters. One of clientDetails for the client and a string that is of the phrase to be solved.
	void AnswerQuestion(ClientDetails* clientDetails, std::string buffer);
	// SendMessages()
	// This function is responsible for the sending of the message to the client when the problem is solved.
	// It returns void and has no parameters.
	void SendMessages();

	short PORT = 2501;
	// an atomic is a template type that no matter if two threads are accessing, it will sort it out.
	std::atomic<bool> listenerRun;
	
	std::string finalOutput;
	
	sf::SocketSelector selector;
	std::vector<std::thread> threads;
protected:
	


	
	std::vector<sf::Mutex> Detailsmutex;
	std::vector<ClientDetails*> details;

};

