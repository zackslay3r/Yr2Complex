#include "Server.h"



Server::Server()
{
	listenerRun = true;
	
}


Server::~Server()
{
}

void Server::ServerStuff()
{
	
	while (listenerRun)
	{
		sf::TcpListener listener;
		listener.listen(PORT);

		sf::TcpSocket* tcpsocket = new sf::TcpSocket();
		//socket gets assigned here.
		sockets.push_back(tcpsocket);
		listener.accept(*tcpsocket);
		std::cout << "New client connected: " << tcpsocket->getRemoteAddress() << std::endl;

	}
}
