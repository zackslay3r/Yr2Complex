#include "Client.h"



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
	while (quit == false)
	{
		
		std::string s;
		sf::Packet sendMessage;
		std::cout << "\nEnter \"exit\" to quit or message to send: " << std::endl;
		//getline(std::cin, s);
		std::cin >> s;
		if (s == "exit")
		{
			quit = true;
		}
		else 
		{
			if (s == "solve")
			{
				std::string SolutionDNA;
				char input[100];

				std::cout << "Input a sentence for me to solve with genetic algorithims." << std::endl;
				std::cin.ignore();
				std::cin.getline(input, 50);
				
					SolutionDNA = std::string(input);
					//sendMessage << s;
					sendMessage << SolutionDNA;
					ClientMutex.lock();
					//msgSend = s;
					socket.send(sendMessage);
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
					break;
				}
			}
			}
		}
		
	}
	if (quit == true)
	{
		socket.disconnect();
		exit(0);
		
	}
}


