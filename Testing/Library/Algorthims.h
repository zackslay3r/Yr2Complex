#pragma once
#include <vector>
#include "Gene.h"	
struct Member
{
	std::string DNA;
	int Fitness;

};
struct Population
{
	std::vector<Member> Members = std::vector<Member>(5000);
};

class Algorthims
{
public:
	// This is the solution we are trying to find with our genetic algorthims.
	std::string DNASolution = "Hello there fam.";
	
	// A bool to check if the solution has been found.
	bool SolutionFound = false;
	
	// USed for the mutation of genes. 
	int MutationRate = 5;
	
	Population Pop;



	

	Algorthims();

	//// MAIN PROBLEM 
	//// have a random population of 10 0's/1's/2's and have them all be equal to 0.
	

	void PopulationCreator();
	//int CalcFitness(Gene* gene);
	void CalcFitness();
	void ParentSelection();


	void FindSolution();
	/// Make sure for when these algorthims are created you!
	/// 1. Have a inital population.
	/// 2. Fitness Function.
	/// 3. Selection.
	/// 4. CrossOver.
	/// 5. Mutation.
	std::vector<Gene*> Population;
	std::vector<Gene*> Solution;
	std::vector<Member> Parents;
	int popCount = 20;
	int currentFitness = 0;
	int generations;
	~Algorthims();
};
