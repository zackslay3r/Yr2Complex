#include "Server.h"



Server::Server()
{
	listenerRun = true;
	algorthimManagement = new Algorthims();
}


Server::~Server()
{
}

void Server::ServerStuff()
{
	sf::TcpListener listener;
	listener.setBlocking(false);
	listener.listen(PORT);
	selector.add(listener);
	std::cout << "The servers IP is " << sf::IpAddress::getLocalAddress().toString() << std::endl;
	while (listenerRun)
	{
		if (true /*selector.wait(sf::Time(sf::milliseconds(1)))*/)
		{
			//if (selector.isReady(listener))
			//{
				sf::TcpSocket* tcpsocket = new sf::TcpSocket();
				tcpsocket->setBlocking(false);
				if(listener.accept(*tcpsocket) == sf::TcpSocket::Status::Done)
				{
				//socket gets assigned here.
				sockets.push_back(tcpsocket);
				selector.add(*tcpsocket);
				std::cout << "New client connected: " << tcpsocket->getRemoteAddress() << std::endl;
				}
				else
				{
					delete tcpsocket;
				}
			//}
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
							//if (buffer == "solve")
							//{
								//buffer.clear();
								//std::string newStringToSolve;
								//recievedPacket >> newStringToSolve;
								algorthimManagement = new Algorthims(buffer);
								//algorthimManagement->SetString(buffer);
								algorthimManagement->FindSolution();
								sf::Packet sendToClient;
								sendToClient << algorthimManagement->ResultGenerations;
								sendToClient << algorthimManagement->ResultFitness;
								sendToClient << algorthimManagement->ResultString;
								socket->send(sendToClient);
								delete algorthimManagement;
								
							//}

							std::cout << socket->getRemoteAddress().toString() << " " << buffer << std::endl;

						}
					}
					else if (status == sf::Socket::Status::Disconnected)
					{
						std::cout << "Disconnected user." << socket->getRemoteAddress().toString() << std::endl;
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
