#include "Client.h"
#include <SFML/Network.hpp>
//#include <../SFML-2.4.2/include/SFML/Network.hpp>
#include <string>
#include "Algorthims.h"


///This
//#include ""




bool validPort = false;
short SelectedPortNumber;
std::string ip;
Client* newClient = new Client;

int main()
{

	/// TESTING CLIENT
	bool validPort = false;

	

	// If we have established a connection, we want to allow the user to have free input from within the client.
	if (newClient->EstablishConnection() == true)
	{
		
		validPort = true;
		while (validPort == true)
		{
			if (newClient->stillConnected == true)
			{
				newClient->getInput();
			}
			else
			{
				std::cout << "You are not connected anymore..." << std::endl;
				
				if (newClient->EstablishConnection() == true)
				{
					validPort = true;
					newClient->stillConnected = true;
					break;
				}
				
			}

		}
	
	}

	

	


	return 0;
}

void EstablishConnection(bool validPort)
{
	
	
	//while (validPort == false)
	//{
	//	std::cout << "Please type in an IP to connect to. " << std::endl;
	//	std::cin >> ip;
	//	std::cout << "Insert a number between 1-5000 as the port to connect to." << std::endl;
	//	std::cin >> SelectedPortNumber;

	//	if (SelectedPortNumber > 1 || SelectedPortNumber < 5000)
	//	{

	//		if (newClient->ClientConnection(ip, SelectedPortNumber))
	//		{
	//			validPort = true;
	//			std::cout << "Connected established." << std::endl;
	//		}
	//		else
	//		{
	//			std::cout << "Connection failed. Invalid Port.";
	//		}

	//	}

	//}

}