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
		
		
			
				std::string SolutionDNA;
				sf::Packet sendMessage;

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
					
				else
				{

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
							inputCompleted = false;
							SolutionDNA = " ";
							break;
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


