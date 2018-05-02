#include "Client.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>

Client::Client()
{
	isConnected = false;
}


Client::~Client()
{
}



bool Client::ClientConnection( std::string IPADDRESS, short PORT)
{
	

	{
		if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected\n";
			isConnected = true;
			return true;
		}
		return false;
	}
}

void Client::ClientChat()
{

}

void Client::getInput()
{
	bool inputCompleted = false;
	bool firstRun = false;

	while (quit == false)
	{
			// This was for testing purposes only....
		/*
			std::string s;
		
			std::cout << "\nEnter \"exit\" to quit or message to send: " << std::endl;
			//std::cin.ignore();
			getline(std::cin, s);
			inputCompleted = true;

		//std::cin >> s;
		*/
		//if (s == "exit")
		//{
		//	quit = true;
		//}
		
		
			
				
				
				std::cout << "Input a sentence for me to solve with genetic algorithims or type 'quit' to disconnect." << std::endl;
				if (firstRun == false)
				{
					std::cin.ignore();
					firstRun = true;
				}
				
				getline(std::cin, SolutionDNA);
				if (SolutionDNA == "quit")
				{
					quit = true;
				}
				else if (SolutionDNA == "load")
				{

					std::ifstream loadFile{"Save.txt"};
					std::string file_contents{ std::istreambuf_iterator<char>(loadFile), std::istreambuf_iterator<char>() };

					std::cout << "File contained: " << file_contents << std::endl;

					std::string response;
					std::cout << "Use this string?" << std::endl;
					getline(std::cin, response);

					if (response == "Yes" || response == "yes")
					{
						SolutionDNA = file_contents;
						doClientThings(sendMessage);
					}
					else
					{
						continue;
					}
				}
				else if (SolutionDNA == "save")
				{
					if (stringToSave.size() != 0)
					{
						
						std::ofstream saveFile("Save.txt");

						saveFile << stringToSave;

						saveFile.close();
					}
				}
				else
				{
					stringToSave = SolutionDNA;
					doClientThings(sendMessage);
					
				}
		
		
	}
	if (quit == true)
	{
		socket.disconnect();
		exit(0);
		
	}
}

void Client::doClientThings(sf::Packet packet)
{
	packet << SolutionDNA;
	ClientMutex.lock();
	//msgSend = s;
	socket.send(packet);
	ClientMutex.unlock();







	sf::Packet AlgorthimResults;
	sf::Socket::Status ClientStatus;

	while (true)
	{
		ClientStatus = socket.receive(AlgorthimResults);

		if (ClientStatus == sf::Socket::Status::Done)
		{
			int generations;
			int fitness;
			std::string DNA;

			AlgorthimResults >> generations;
			AlgorthimResults >> fitness;
			AlgorthimResults >> DNA;


			std::cout << "Generation : " << generations << " Highest Fitness : " << fitness << std::endl << "With Sequence : " << DNA << std::endl;
			inputCompleted = false;
			SolutionDNA = " ";
			break;
		}
	}
}


