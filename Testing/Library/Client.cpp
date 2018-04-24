#include "Client.h"



Client::Client()
{
	isConnected = false;
}


Client::~Client()
{
}



bool Client::ClientConnection( std::string IPADDRESS, short PORT)
{
	

	{
		if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected\n";
			isConnected = true;
			return true;
		}
		return false;
	}
}

void Client::ClientChat()
{

}

void Client::getInput()
{
	while (quit == false)
	{
		
		std::string s;
		sf::Packet sendMessage;
		std::cout << "\nEnter \"exit\" to quit or message to send: " << std::endl;
		getline(std::cin, s);
		
		if (s == "exit")
		{
			quit = true;
		}
		else
		{
			sendMessage << s;
			ClientMutex.lock();
			msgSend = s;
			socket.send(sendMessage);
			ClientMutex.unlock();
		}
	}
	if (quit == true)
	{
		socket.disconnect();
		exit(0);
		
	}
}


