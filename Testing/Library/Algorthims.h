#pragma once
#include <vector>
#include "Gene.h"
#include "dllmain.h"

struct Member
{
	std::string DNA;
	int Fitness;
	double probablity;
};
struct Population
{
	std::vector<Member> Members = std::vector<Member>(375);
};

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
	

	int popCount = 20;
	int currentFitness = 0;
	int generations;


	
	void ParentSelection();

	

	void FindSolution();

	

	~Algorthims();
};

