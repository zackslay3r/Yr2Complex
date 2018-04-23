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
	sf::TcpListener listener;
	listener.listen(PORT);
	selector.add(listener);
	while (listenerRun)
	{
		if (selector.wait(sf::Time(sf::milliseconds(1))))
		{
			if (selector.isReady(listener))
			{
				sf::TcpSocket* tcpsocket = new sf::TcpSocket();
				
				if(listener.accept(*tcpsocket) == sf::TcpSocket::Status::Done)
				{
				//socket gets assigned here.
				sockets.push_back(tcpsocket);
				selector.add(*tcpsocket);
				std::cout << "New client connected: " << tcpsocket->getRemoteAddress() << std::endl;
				}
			}
			//char buffer[1024];
			sf::Packet recievedPacket;
			std::string buffer;
			std::size_t received = 0;

			sf::Socket::Status status;
			//for (auto& socket : sockets)

			for (auto iter = sockets.begin(); iter != sockets.end();)
			{
				
				sf::TcpSocket* socket;
				socket = *iter;
			
				
				

					buffer.clear();
					recievedPacket.clear();	
					
			/*		if (selector.isReady(*socket) == false)
					{
					continue;
					}*/
					
					
					
					status = socket->receive(recievedPacket);
					bool deleted = false;
					
					
					
					
					//socket->receive(recievedPacket);

					//socket->receive(buffer, sizeof(buffer), received);


					if (status == sf::Socket::Status::Done)
					{
						if ((recievedPacket >> buffer) && !buffer.empty())
						{
							std::cout << socket->getRemoteAddress().toString() << " " << buffer << std::endl;

						}
					}
					else if (status == sf::Socket::Status::Disconnected)
					{
						socket->disconnect();
						iter = sockets.erase(iter);
						selector.remove(*socket);
						deleted = true;
					}
					else if (status == sf::Socket::Status::Error)
					{
						//			std::cout << "Confused" << std::endl;
					}

					if (deleted == false)
					{
						iter++;
					}
				
			}


		}
		

		
		
		

	}
}

void Server::RecieveMessages()
{

	//std::cout << "The client said: " << buffer << std::endl;
}
