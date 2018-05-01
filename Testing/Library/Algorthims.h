#pragma once
#include <vector>
#include "Gene.h"

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

class Algorthims
{
public:
	// This is the solution we are trying to find with our genetic algorthims.
	std::string DNASolution;
	
	// A bool to check if the solution has been found.
	bool SolutionFound = false;
	
	// USed for the mutation of genes. 
	int MutationRate = 25;
	
	Population Pop;


	Algorthims(std::string Solution);


	void Setup();

	void Start();

	
	void SetString(std::string string);

	void PopulationCreator();
	//int CalcFitness(Gene* gene);
	void CalcFitness();
	void ParentSelection();

	

	Member pickParent(std::vector<Member> population);
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

	int ResultGenerations;
	int ResultFitness;
	std::string ResultString;
	

	int popCount = 20;
	int currentFitness = 0;
	int generations;
	~Algorthims();
};

