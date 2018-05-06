#include "Client.h"
#include <SFML/Network.hpp>

#include <string>
#include "Algorthims.h"







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
				// If we are connected, get the user input.
				newClient->getInput();
			}
			//if not, prompt them to be able to reconnect.
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
