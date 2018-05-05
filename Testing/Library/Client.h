#pragma once
#include <SFML/Network.hpp>

#include <iostream>
#include <string>
#include "dllmain.h"

// This is the client class.
// This is responsible for storing all the functions and ablities of the client.
class DLL Client
{
public:
	// This is the constructor.
	Client();
	// This is the descructor.
	~Client();
	//ClientConnection()
	// This function is responsible for checking if a client is connected.
	// This returns a bool and takes 2 parameters, one is a string for the IP address and one is of type Short for the port.
	bool ClientConnection(std::string IPADDRESS, short PORT);

	// getInput();
	// This function is responsible for recieving the input from the user to the client and to be able to send it to the server.
	void getInput();
	
	// A clients socket.
	sf::TcpSocket socket;
	// bool that checks if a client is connected.
	bool isConnected;
	// A client mutex for data protection.
	sf::Mutex ClientMutex;
	// A bool for if a client disconnects.
	bool quit = false;
	
	// sendClientRequest()
	// THis function is responsible for the sending of information to the server.
	// this returns void and take on a parameter of a pack for the purposes of sending.
	void sendClientRequest(sf::Packet packet);

	bool EstablishConnection();
	
	bool stillConnected = true;
	
	sf::Packet sendMessage;

	std::string msgSend;
	std::string stringToSave;
	std::string SolutionDNA;

};

