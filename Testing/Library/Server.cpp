#include "Server.h"
#include "SFML/System.hpp"
#include <stdlib.h>
#include <thread>
#include <chrono>
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
				//sf::TcpSocket* tcpsocket = new sf::TcpSocket();
				//sf::Mutex* newMutex = new sf::Mutex();
				ClientDetails* newClientDetails = new ClientDetails();
				std::unique_lock<std::mutex> lock(newClientDetails->clientMutex);
				if(listener.accept(newClientDetails->clientSocket) == sf::TcpSocket::Status::Done)
				{
				//socket gets assigned here.
				//sockets.push_back(tcpsocket);
				//mutex.push_back(newMutex);
					details.push_back(newClientDetails);

				//ClientDetails
				//selector.add(newClientDetails->clientSocket);
				std::cout << "New client connected: " << newClientDetails->clientSocket.getRemoteAddress() << std::endl;
				lock.unlock();
				}
				else
				{
					lock.unlock();
					delete newClientDetails;

				}
				
			//}
			//char buffer[1024];
			sf::Packet recievedPacket;
			
			//buffer.resize(100);
			std::size_t received = 0;

			sf::Socket::Status status;
			//for (auto& socket : sockets)

			for (auto iter = details.begin(); iter != details.end();)
			{
				std::string buffer;
				sf::TcpSocket* socket;
				
				socket = &(*iter)->clientSocket;
			
				
				

					buffer.clear();
					recievedPacket.clear();	
					
			/*		if (selector.isReady(*socket) == false)
					{
					continue;
					}*/
					
					
					std::unique_lock<std::mutex> lock((*iter)->clientMutex);
					status = socket->receive(recievedPacket);
					lock.unlock();
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
								/*algorthimManagement = new Algorthims(buffer);*/
								//algorthimManagement->SetString(buffer);
								
							//(*iter)->clientAlgorithims->SetString(buffer);

							threads.push_back(std::thread([this,iter,buffer] {AnswerQuestion(*iter,buffer); }));
								//algorthimManagement->FindSolution();
								////algorthimManagement->Start();

								//sf::Packet sendToClient;
								//sendToClient << algorthimManagement->ResultGenerations;
								//sendToClient << algorthimManagement->ResultFitness;
								//sendToClient << algorthimManagement->ResultString;
								//socket->send(sendToClient);
								//delete algorthimManagement;
								
							//}
							std::unique_lock<std::mutex> lock((*iter)->clientMutex);
							std::cout << socket->getRemoteAddress().toString() << " " << buffer << std::endl;
							lock.unlock();
							buffer.clear();
						}
					}
					else if (status == sf::Socket::Status::Disconnected)
					{
						std::unique_lock<std::mutex> lock((*iter)->clientMutex);
						std::cout << "Disconnected user." << socket->getRemoteAddress().toString() << std::endl;
						
						socket->disconnect();
						lock.unlock();
						iter = details.erase(iter);
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

void Server::AnswerQuestion(ClientDetails* clientdetails, std::string buffer)
{
	
	
	clientdetails->clientAlgorithims = new Algorthims(buffer);
	clientdetails->clientAlgorithims->FindSolution();
	
	sf::Packet sendToClient;
	sendToClient << clientdetails->clientAlgorithims->ResultGenerations;
	sendToClient << clientdetails->clientAlgorithims->ResultFitness;
	sendToClient << clientdetails->clientAlgorithims->ResultString;
	std::unique_lock<std::mutex> lock(clientdetails->clientMutex);
	clientdetails->clientSocket.send(sendToClient);
	lock.unlock();

}

void Server::SendMessages()
{
	// Create a string that will be used to output all the data.
	std::string finalOutput;
	// For every client, we are going to add to the string what we wish to output.
	for (auto &iter : details)
	{
		if (iter->clientAlgorithims != nullptr && (iter)->clientAlgorithims->Parents.size() > 0)
		{
			if (iter->clientAlgorithims->SolutionFound == false)
			{
				finalOutput += std::string("Generation : ") + std::to_string((iter)->clientAlgorithims->generations) + 
				std::string(" Correct characters: ") + std::to_string((iter)->clientAlgorithims->Parents.at(0).Fitness / 10) + 
				std::string(" Out of: ") + std::to_string((iter)->clientAlgorithims->DNASolution.size()) + std::string("With Sequence : ") + 
				(iter)->clientAlgorithims->ResultString;
				finalOutput += "\n";
			}
			else
			{
				
				finalOutput += std::string("Generation ") + std::to_string((iter)->clientAlgorithims->generations) + std::string(" Evolved to the full sequence. ");
				finalOutput += "\n";
			}
		}
	}	
	system("CLS");
	std::cout << "The servers IP is " << sf::IpAddress::getLocalAddress().toString() << std::endl;
	std::cout << "The port number is" << PORT;
	std::cout << finalOutput;
	std::this_thread::sleep_for(std::chrono::milliseconds(16));
	
	// Then clear it.
	
	//finalOutput = " ";

	// Output it.
	
	
	//std::cout << "Generation : " <<  << " Correct characters: " << Parents.at(0).Fitness / 10 << " Out of: " << DNASolution.size() << std::endl << "With Sequence : " << Parents.at(0).DNA.c_str() << std::endl;


	//std::cout << "The client said: " << buffer << std::endl;
}
