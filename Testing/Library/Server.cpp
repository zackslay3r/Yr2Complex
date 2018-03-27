#include "Server.h"



Server::Server()
{

	
}


Server::~Server()
{
}

void Server::ServerStuff(short PORT)
{
		sf::TcpListener listener;
		listener.listen(PORT);

		sf::TcpSocket* tcpsocket = new sf::TcpSocket();
		//socket gets assigned here.
		sockets.push_back(tcpsocket);
		listener.accept(*tcpsocket);
		std::cout << "New client connected: " << tcpsocket->getRemoteAddress() << std::endl;
		
}
