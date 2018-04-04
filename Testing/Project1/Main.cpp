#include "Client.h"
#include <SFML/Network.hpp>
#include <string>
int main()
{
	bool validPort = false;
	short SelectedPortNumber;
	Client* newClient = new Client;

	while (!validPort)
	{
		std::cout << "Insert a number between 1-5000 as the port to connect to.";
		std::cin >> SelectedPortNumber;
		if (SelectedPortNumber > 1 || SelectedPortNumber < 5000)
		{
			if (newClient->ClientStuff(sf::IpAddress::getLocalAddress().toString(), SelectedPortNumber))
			{
				validPort == true;
				std::cout << "Connected established.";
			}
			else
			{
				std::cout << "Connection failed. Invalid Port.";
			}
			
		}
	
	}

	
	system("pause");
	return 0;
}