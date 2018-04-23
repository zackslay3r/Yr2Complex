#pragma once
#include <vector>
#include "Gene.h"
class Algorthims
{
public:
	Algorthims();

	//// MAIN PROBLEM 
	//// have a random population of 10 0's/1's/2's and have them all be equal to 0.
	

	void PopulationCreator();
	int CalcFitness(Gene* gene);

	/// Make sure for when these algorthims are created you!
	/// 1. Have a inital population.
	/// 2. Fitness Function.
	/// 3. Selection.
	/// 4. CrossOver.
	/// 5. Mutation.
	std::vector<Gene*> Population;
	std::vector<Gene*> Solution;

	int popCount = 20;
	~Algorthims();
};

