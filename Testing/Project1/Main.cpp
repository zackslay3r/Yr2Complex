#include "Client.h"
#include <SFML/Network.hpp>
#include <string>
int main()
{
	Client* newClient = new Client;
	newClient->ClientStuff(sf::IpAddress::getLocalAddress().toString(), 2501);
	system("pause");
	return 0;
}