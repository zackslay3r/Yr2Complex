#include "Client.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>

Client::Client()
{
	isConnected = false;
	stillConnected = false;
}


Client::~Client()
{
}



bool Client::ClientConnection( std::string IPADDRESS, short PORT)
{
	

	
		if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected\n";
			isConnected = true;
			return true;
		}
		else if (socket.connect(IPADDRESS, PORT) == sf::Socket::Disconnected)
		{
		
		}
		else
		{
			return false;
		}

}



void Client::getInput()
{
	
	bool inputCompleted = false;
	bool firstRun = false;

	while (quit == false)
	{
				
				std::cout << "Input a sentence for me to solve with genetic algorithims or type 'quit' to disconnect." << std::endl;
				std::cout << "You may also type 'save' to save the string you last solved or 'load' to load the string last saved." << std::endl;
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

					if (file_contents.size() > 0)
					{
						std::cout << "File contained: " << file_contents << std::endl;

						std::string response;
						std::cout << "Use this string?" << std::endl;
						getline(std::cin, response);

						if (response == "Yes" || response == "yes")
						{
							SolutionDNA = file_contents;
							sendClientRequest(sendMessage);
						}
						else
						{
							continue;
						}
					}
					else
					{
						std::cout << "There is no phrase currently saved on file. Please try after you have saved a phrase." << std::endl;
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
					else
					{
						std::cout << "A string has not been solved yet. Please try to save after you have inputted a string to solve." << std::endl;
					}
				}
				else
				{
					stringToSave = SolutionDNA;
					sendClientRequest(sendMessage);
					
				}
		
		
	}
	if (quit == true)
	{
		socket.disconnect();
		exit(0);
		
	}
}

void Client::sendClientRequest(sf::Packet packet)
{
	packet << SolutionDNA;
	ClientMutex.lock();

	socket.send(packet);
	ClientMutex.unlock();







	sf::Packet AlgorthimResults;
	sf::Socket::Status ClientStatus;
	ClientStatus = socket.receive(AlgorthimResults);
	while (true)
	{
		

		if (ClientStatus == sf::Socket::Status::Done)
		{
			
			int generations;
			int fitness;
			std::string DNA;

			AlgorthimResults >> generations;
			AlgorthimResults >> fitness;
			AlgorthimResults >> DNA;


			std::cout << "Generation : " << generations << " Highest Fitness : " << fitness << std::endl << "With Sequence : " << DNA << std::endl;
			
			SolutionDNA = " ";
			stillConnected = true;
			break;
		}
		else if (ClientStatus == sf::Socket::Status::Disconnected)
		{
			std::cout << "You have been disconnect from the server, please try again. ";
			socket.disconnect();
			stillConnected = false;
			while (stillConnected == false)
			{
				if (EstablishConnection() == true)
				{
					getInput();
				}
			}
		}

	}
}

bool Client::EstablishConnection()
{
	/// TESTING CLIENT
	bool validPort = false;

	std::string ip;
	short SelectedPortNumber;


		while (validPort == false)
		{
			std::cout << "Please type in an IP to connect to. " << std::endl;
			std::cin >> ip;
			std::cout << "Insert a number between 1-5000 as the port to connect to." << std::endl;
			std::cin >> SelectedPortNumber;

			if (SelectedPortNumber > 1 || SelectedPortNumber < 5000)
			{

				if (ClientConnection(ip, SelectedPortNumber))
				{
					validPort = true;
					std::cout << "Connected established." << std::endl;
					stillConnected = true;
					return true;
				}
				else
				{
					std::cout << "Connection failed. Invalid Port.";
					//validPort = false;
					return false;
				}

			}

		

	}
}


