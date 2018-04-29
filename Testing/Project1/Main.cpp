#include "Client.h"
#include <SFML/Network.hpp>
#include <string>
#include "Algorthims.h"
int main()
{
	Algorthims algorthimData;
	

	/// TESTING CLIENT
	bool validPort = false;
	short SelectedPortNumber;
	std::string ip;

	Client* newClient = new Client;

	while (validPort == false)
	{
		std::cout << "Please type in an IP to connect to. " << std::endl;
		std::cin >> ip;
		std::cout << "Insert a number between 1-5000 as the port to connect to." << std::endl ;
		std::cin >> SelectedPortNumber;

		if (SelectedPortNumber > 1 || SelectedPortNumber < 5000)
		{
			//if (newClient->ClientConnection(sf::IpAddress::getLocalAddress().toString(), SelectedPortNumber))
			if (newClient->ClientConnection(ip, SelectedPortNumber))
			{
				validPort = true;
				std::cout << "Connected established." << std::endl;
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

	

	
	///Testing ALGORTHIMS
	//algorthimData.FindSolution();
	//algorthimData.PopulationCreator();

	return 0;
}