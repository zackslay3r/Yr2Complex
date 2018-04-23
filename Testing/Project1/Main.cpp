#include "Client.h"
#include <SFML/Network.hpp>
#include <string>
int main()
{
	bool validPort = false;
	short SelectedPortNumber;
	Client* newClient = new Client;

	while (validPort == false)
	{
		std::cout << "Insert a number between 1-5000 as the port to connect to.";
		std::cin >> SelectedPortNumber;
		if (SelectedPortNumber > 1 || SelectedPortNumber < 5000)
		{
			if (newClient->ClientConnection(sf::IpAddress::getLocalAddress().toString(), SelectedPortNumber))
			{
				validPort = true;
				std::cout << "Connected established.";
			}
			else
			{
				std::cout << "Connection failed. Invalid Port.";
			}
			
		}
	
	}
	if (validPort == true)
	{
		while (validPort == true)
		{
			newClient->getInput();
		}
	
	}

	
	
	return 0;
}