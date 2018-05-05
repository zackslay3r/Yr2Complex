#pragma once
#include <vector>
#include "Gene.h"
#include "dllmain.h"

// THis is a member of the population.
struct Member
{
	std::string DNA;
	int Fitness;
	double probablity;
};
// A struct that will be our population.
struct Population
{
	std::vector<Member> Members = std::vector<Member>(375);
};

//This is the Algorthims class.
// It is responsible for finding the solution to whatever the client asks.

class DLL Algorthims
{
public:
	// This is the solution we are trying to find with our genetic algorthims.
	std::string DNASolution;
	
	// A bool to check if the solution has been found.
	bool SolutionFound = false;
	
	// Used for the mutation of genes. 
	int MutationRate = 25;
	
	// Have the Algorthims class contain a Poplation of members.
	Population Pop;

	//This is the Algorthims constructor. 
	// The constructor takes a parameter of type String, which will be set to be the DNASolution.
	Algorthims(std::string Solution);


	//This is a vector of 2 partent that we are going to hold in order for the next generation.
	std::vector<Member> Parents;


	// These 3 variables are being used to hold data that will be sent to the client.
	int ResultGenerations;
	int ResultFitness;
	std::string ResultString;
	


	// This variable is used to store the amount of generation within Algorthims before being sent to the client.
	int generations;


	// This is the parent selection function.
	// This will go though the population and select 2 memebers of the population with the highest fitness to be the parents for the next generation.
	// This takes no parameters and returns void.
	void ParentSelection();

	

	// This is the FindSolution function.
	// This will automate the process of finding the solution to the clients pharse. This is the primary function within the 'Algorthims' class.
	// It takes no parameters and returns void.
	void FindSolution();

	
	// THis is the Algorthims destructor.
	~Algorthims();
};

